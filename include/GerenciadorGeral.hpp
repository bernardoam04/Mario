#ifndef GERENCIADORGERAL_HPP
#define GERENCIADORGERAL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Mapa.hpp"
#include "Camera.hpp"
#include "Colisao.hpp"
#include "PoderesEspeciais.hpp"

class GerenciadorGeral{
private:
    //Constantes
    const float altura_tela =640;
    const float largura_tela =640;

    //Tipos Abstratos
    sf::RenderWindow* janela;
    sf::VideoMode tela;
    sf::Event ev;
    Mapa mapa;  
    Camera camera;
    Colisao *colisao;
    std::vector<PoderesEspeciais*> vetorPoderesEspeciais;

    //Métodos privados
    void inicializarVariaveis();
    void InicializarPoderesEspeciais();
    void iniciarJanela();
public:
    //Construtor e Destrutor
    GerenciadorGeral();
    virtual ~GerenciadorGeral();

    //Métodos de Verificação
    int verificarColisao(float x, float y) const;
    bool janelaAberta() const;

    //Métodos utilizados no jogo diretamente
    void atualizar(sf::Time tempoAtual, sf::Time deltaTime);
    void atualizarEventos();
    void renderizar();

    //Getters
    float getAlturaTela() const;
    float getLarguraTela() const;
};

#endif
