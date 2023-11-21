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
    sf::RenderWindow* janela;
    sf::VideoMode tela;
    float altura_tela =640;
    float largura_tela =640;
    sf::Event ev;
    Mapa mapa;  
    Camera camera;
    Colisao *colisao;
    PoderesEspeciais* poderesEspeciais;  // Adicione esta linha
    std::vector<PoderesEspeciais*> vetorPoderesEspeciais;
    void inicializarVariaveis();
    void InicializarPoderesEspeciais();
    void iniciarJanela();

public:
    int verificarColisao(float x, float y) const;
    GerenciadorGeral();
    virtual ~GerenciadorGeral();
    bool janelaAberta() const;
    void atualizar(sf::Time deltaTime);
    void atualizarEventos();
    void renderizar();
    float getAlturaTela() const;
    float getLarguraTela() const;
};

#endif
