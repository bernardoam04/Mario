#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "GerenciadorGeral.hpp"
#include <memory>

/**
 * @brief Representa o menu principal do jogo.
 */
class Menu {
public:
    /**
     * @brief Enumeração para as opções selecionadas no menu.
     */
    enum OpcaoSelecionada {
        NenhumaSelecao,
        IniciarJogo,
        Opcoes,
        Sair
    };

private:
    // Textos
    sf::Text iniciarJogoTexto;
    sf::Text opcoesTexto;
    sf::Text sairTexto;

    // Atributos de desenho
    sf::Texture menuTexture;
    sf::Sprite menuSprite;
    sf::Texture semSomTexture;
    sf::Sprite semSomSprite;
    
    OpcaoSelecionada opcaoSelecionada;

    // Atributos privados
    void ajustarPosicaoMenu();
    void ajustarPosicaoTextos();

    bool somAtivo;

protected:
    std::shared_ptr<sf::RenderWindow> janela;

public:
    // Construtor
    /**
     * @brief Constrói um objeto Menu.
     * @param janela1 Ponteiro compartilhado para a janela do jogo.
     * @param fonte Fonte utilizada para os textos no menu.
     */
    Menu(std::shared_ptr<sf::RenderWindow> janela1, sf::Font &fonte);

    // Métodos usados diretamente
    /**
     * @brief Desenha a tela do menu.
     */
    virtual void desenharTela();

    /**
     * @brief Atualiza o estado do menu.
     * @param ev Evento do SFML para tratar eventos de entrada.
     * @return True se uma seleção foi feita, caso contrário, false.
     */
    bool atualizar(sf::Event ev);

    /**
     * @brief Atualiza a posição dos textos no menu.
     */
    void atualizarPosicaoTextos();

    /**
     * @brief Atualiza a opção selecionada no menu.
     */
    void atualizarOpcaoSelecionada();

    /**
     * @brief Trata o clique do mouse para seleção de opções.
     * @return True se uma opção foi selecionada, caso contrário, false.
     */
    bool tratarCliqueMouse();

    /**
     * @brief Reseta a seleção do menu para nenhuma.
     */
    void resetarSelecao(); 

    /**
     * @brief Verifica se a opção "Sair" foi selecionada.
     * @return True se a opção "Sair" foi selecionada, caso contrário, false.
     */
    bool sair();

    // Getters
    /**
     * @brief Obtém a opção atualmente selecionada no menu.
     * @return Opção selecionada no menu.
     */
    OpcaoSelecionada getOpcaoSelecionada() const;

    /**
     * @brief Verifica se o som está ativo no menu.
     * @return True se o som estiver ativo, caso contrário, false.
     */
    bool getSomAtivo();
};

#endif
