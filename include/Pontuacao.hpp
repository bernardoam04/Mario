#ifndef PONTUACAO_HPP
#define PONTUACAO_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "../include/Camera.hpp"
#include <memory>

/**
 * @brief Classe responsável por gerenciar e exibir a pontuação do jogador.
 */
class Pontuacao {
private:
    int contagem; ///< Contagem total da pontuação do jogador.
    sf::Text texto; ///< Objeto Texto do SFML para exibir a pontuação na tela.
    std::shared_ptr<Camera> camera; ///< Smart Pointer para a instância da câmera.

public:
    /**
     * @brief Construtor da classe Pontuacao.
     * @param fonte Referência para a fonte a ser utilizada no texto da pontuação.
     * @param camera Smart Pointer para a instância da câmera.
     */
    Pontuacao(sf::Font& fonte, std::shared_ptr<Camera> camera);

    /**
     * @brief Destrutor da classe Pontuacao.
     */
    ~Pontuacao();

    /**
     * @brief Atualiza a pontuação com base na contagem de moedas e poderes especiais.
     * @param contagemMoeda Número de moedas coletadas.
     * @param contagemPoderesEspeciais Número de poderes especiais coletados.
     */
    void atualizarPontuacao(int contagemMoeda, int contagemPoderesEspeciais);

    /**
     * @brief Exibe a pontuação como um objeto Texto do SFML.
     * @return Objeto Texto do SFML contendo a pontuação formatada para ser chamada e mostrada na tela.
     */
    sf::Text exibirPontuacao();

    /**
     * @brief Obtém a pontuação total do jogador.
     * @return Valor da pontuação total.
     */
    int getPontuacaoTotal();
};

#endif
