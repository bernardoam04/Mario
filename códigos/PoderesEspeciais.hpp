#ifndef PODERESESPECIAIS_HPP
#define PODERESESPECIAIS_HPP

#include "Colisao.hpp"
#include <SFML/Graphics.hpp>

class PoderesEspeciais {
private:
    sf::Texture cogumeloTexture; 
    sf::Texture estrelaTexture;
    sf::Sprite poderSprite; 
    sf::Vector2f posicao; 
    static const int COGUMELO = 1; 
    static const int ESTRELA = 2; 
    float tileSize = 32.0f;
    float velocidadeVertical = 0.0f;
    float aceleracaoGravidade = 9.8f;  
    bool estaNoAr = false; 
    int tipo;

public:
    PoderesEspeciais();

    void inicializar(int tipo, float x, float y);
    void desenhar(sf::RenderWindow& janela);

    void atualizar();
};

#endif 