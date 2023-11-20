#ifndef PODERESESPECIAIS_HPP
#define PODERESESPECIAIS_HPP

#include <SFML/Graphics.hpp>
#include "Colisao.hpp"

class PoderesEspeciais  {
private:
    float tileSize=32;
    sf::Texture cogumeloTexture; 
    sf::Texture estrelaTexture;
    mutable sf::Sprite poderSprite;  
    sf::Vector2f posicao; 
    static const int COGUMELO = 1; 
    static const int ESTRELA = 2; 
    float velocidadeVertical = 0.0f;
    float velocidadeHorizontal = 50.0f;
    float aceleracaoGravidade = 9.8f;  
    bool estaNoAr = false; 
    int tipo;
    bool movDireita=true;
    bool movEsquerda=false;
    Colisao &colisao;
public:
    PoderesEspeciais(Colisao &colisao);  
    int verificarColisao(sf::Vector2f coordenadas);
    void inicializar(int tipo, float x, float y);
    void desenhar(sf::RenderWindow& janela);
    int verificarColisaoPoder(float x, float y);
    void atualizar(sf::Time deltaTime);
};

#endif 