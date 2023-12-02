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
    //Textos
    sf::Text iniciarJogoTexto;
    sf::Text opcoesTexto;
    sf::Text sairTexto;

    //Atributos de desenho
    sf::Texture menuTexture;
    sf::Sprite menuSprite;
    
    OpcaoSelecionada opcaoSelecionada;

    //Atributos privados
    void ajustarPosicaoMenu();
    void ajustarPosicaoTextos();

protected:
    std::shared_ptr<sf::RenderWindow> janela;


public:
    //Construtor
    Menu(std::shared_ptr<sf::RenderWindow> janela1, sf::Font &fonte);

    //Métodos usados diretamente
    virtual void desenharTela();
    virtual bool atualizar(sf::Event ev);
    virtual void atualizarPosicaoTextos();
    virtual void atualizarOpcaoSelecionada();
    virtual bool tratarCliqueMouse();
    void resetarSelecao(); 
    bool sair();

    //Getters
    OpcaoSelecionada getOpcaoSelecionada() const;
};

#endif