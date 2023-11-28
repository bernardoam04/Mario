#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <memory>

class Menu{
private:
    enum OpcaoSelecionada {
        NenhumaSelecao,
        IniciarJogo,
        Opcoes,
        Sair
    };

    std::shared_ptr <sf::RenderWindow> janela;
    sf::Text iniciarJogoTexto;
    sf::Text opcoesTexto;
    sf::Text sairTexto;
    sf::Texture menuTexture; 
    sf::Sprite menuSprite; 
    OpcaoSelecionada opcaoSelecionada;

    void ajustarPosicaoMenu();
    void ajustarPosicaoTextos();

public:
    Menu(std::shared_ptr <sf::RenderWindow> janela1, sf::Font &fonte);
    void desenharTela();
    bool atualizar(sf::Event ev);
    void atualizarPosicaoTextos();
    // virtual ~Menu();
    bool sair();
};

#endif