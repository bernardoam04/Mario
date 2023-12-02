#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <memory>


class Menu {
public:
    enum OpcaoSelecionada {
        NenhumaSelecao,
        IniciarJogo,
        Opcoes,
        Sair
    };
private:
    sf::Text iniciarJogoTexto;
    sf::Text opcoesTexto;
    sf::Text sairTexto;
    sf::Texture menuTexture;
    sf::Sprite menuSprite;
    OpcaoSelecionada opcaoSelecionada;

    void ajustarPosicaoMenu();
    void ajustarPosicaoTextos();

protected:
    std::shared_ptr<sf::RenderWindow> janela;


public:
    Menu(std::shared_ptr<sf::RenderWindow> janela1, sf::Font &fonte);
    virtual void desenharTela();
   virtual bool atualizar(sf::Event ev);
    virtual void atualizarPosicaoTextos();
    bool sair();
    virtual void atualizarOpcaoSelecionada();
    virtual bool tratarCliqueMouse();
    OpcaoSelecionada getOpcaoSelecionada() const;
    void resetarSelecao(); 
   
};

#endif