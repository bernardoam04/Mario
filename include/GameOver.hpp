#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <memory>

/**
 * @brief Classe responsável pela tela de Game Over do jogo.
 */
class GameOver {
private:
    std::shared_ptr<sf::RenderWindow> janela; ///< Smart Pointer para a janela do SFML.
    sf::Text texto; ///< Objeto Texto do SFML para exibir informações na tela 
    sf::Text texto2; ///< Objeto Texto do SFML para exibir informações na tela.
    sf::Text texto3; ///< Objeto Texto do SFML para exibir informações na tela.

public:
    /**
     * @brief Construtor da classe GameOver.
     * @param janela1 Smart Pointer para a janela do SFML.
     * @param fonte Referência para a fonte a ser utilizada nos textos.
     */
    GameOver(std::shared_ptr<sf::RenderWindow> janela1, sf::Font& fonte);

    /**
     * @brief Desenha a tela de Game Over na janela.
     * @param pontuacaoTotal Pontuação total do jogador.
     * @param view Referência para a vista da câmera.
     */
    void desenharTela(int pontuacaoTotal, const sf::View& view);

    /**
     * @brief Atualiza a tela de Game Over com base em eventos.
     * @param ev Evento do SFML.
     * @param view Referência para a vista da câmera.
     * @return Verdadeiro se a tela precisar ser fechada; falso caso contrário.
     */
    bool atualizar(sf::Event ev, const sf::View& view);

    /**
     * @brief Atualiza as posições dos textos na tela com base na vista da câmera.
     * @param view Referência para a vista da câmera.
     */
    void atualizarPosicaoTextos(const sf::View& view);
};

#endif
