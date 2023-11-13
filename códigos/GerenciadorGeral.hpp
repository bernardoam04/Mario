#ifndef GERENCIADORGERAL_HPP
#define GERENCIADORGERAL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class GerenciadorGeral {
private:
    //Variaveis
    sf::RenderWindow* janela;
    sf::VideoMode tela;
    sf::Event ev;

    //Inicialização
    void inicializarVariaveis();
    void iniciarJanela();

public:
    //Construtores e Destrutores
    GerenciadorGeral();
    virtual ~GerenciadorGeral();

    //Acesso
    bool janelaAberta() const;

    //Funções
    void atualizar();
    void atualizarEventos();
    void renderizar();
};

#endif