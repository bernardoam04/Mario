#ifndef PODERESESPECIAIS_HPP
#define PODERESESPECIAIS_HPP

#include <SFML/Graphics.hpp>
#include "Colisao.hpp"

class PoderesEspeciais  {
private:
    //Texturas e posições
    sf::Texture cogumeloTexture; 
    sf::Texture estrelaTexture;
    sf::Sprite poderSprite;  

    //Constantes
    const float aceleracaoGravidade = 4.8f;  
    static const int COGUMELO = 1; 
    static const int ESTRELA = 2; 
    const float tileSize=32;

    //Modificáveis
    float velocidadeVertical = 0.0f;
    float velocidadeHorizontal = 50.0f;

    //Verificações
    bool estaNoAr = false;
    bool movDireita=true;
    bool movEsquerda=false;
    bool existe = false;

    Colisao &colisao;

public:
    sf::Vector2f posicao; 
    PoderesEspeciais(Colisao &colisao);  
    int verificarColisao(sf::Vector2f coordenadas);
    int gerarTipoAleatorio();
    bool inicializarNoMapa(Mapa& mapa);
    void inicializar(float x, float y);
    void desenhar(sf::RenderWindow& janela);
    void ModificacaoPosicao(sf::Time deltaTime);
    void atualizar(sf::Time deltaTime);
};

#endif 