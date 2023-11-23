#ifndef GERENCIADORGERAL_HPP
#define GERENCIADORGERAL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <memory>

#include "Mapa.hpp"
#include "Camera.hpp"
#include "Colisao.hpp"
#include "PoderesEspeciais.hpp"

class GerenciadorGeral{
private:

    //Informações da tela(mesma do main)
    const float alturaTela = 640;
    const float larguraTela = 640;

    //Tipos Abstratos
    std::shared_ptr <sf::RenderWindow> janela;
    Mapa mapa;  
    Camera camera;
    std::shared_ptr <Colisao> colisao;
    std::vector<std::shared_ptr <PoderesEspeciais>> vetorPoderesEspeciais;

    //Métodos privados
    void inicializarVariaveis();
    void InicializarPoderesEspeciais();
public:
    //Construtor e Destrutor
    GerenciadorGeral(std::shared_ptr <sf::RenderWindow> janela1);
    virtual ~GerenciadorGeral();

    //Métodos de Verificação
    int verificarColisao(float x, float y) const;
    bool janelaAberta() const;

    //Métodos utilizados no jogo diretamente
    void atualizar(sf::Time tempoAtual, sf::Time deltaTime, sf::Event ev);
    void atualizarEventos(sf::Event ev);
    void renderizar(sf::Time tempoAtual);

    //Getters
    float getAlturaTela() const;
    float getLarguraTela() const;
};

#endif
