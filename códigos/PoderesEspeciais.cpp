#include "PoderesEspeciais.hpp"
#include <iostream>

PoderesEspeciais::PoderesEspeciais(Colisao &colisao) : colisao(colisao)
{
    cogumeloTexture.loadFromFile("../imagens/cogumelo.png"); 
    estrelaTexture.loadFromFile("../imagens/estrela.png");
}

void PoderesEspeciais::inicializar(int tipo, float x, float y)
{
    this->tipo = tipo;
    this->posicao = sf::Vector2f(x, y);

    // Configure o sprite e a textura com base no tipo
    switch (tipo) {
        case COGUMELO:
            poderSprite.setTexture(cogumeloTexture);
            break;
        case ESTRELA:
            poderSprite.setTexture(estrelaTexture);
            break;
        // Adicione mais casos conforme necessário para outros tipos de poderes especiais
    }

    poderSprite.setPosition(posicao);
}

void PoderesEspeciais::desenhar(sf::RenderWindow& janela) {
    poderSprite.setPosition(posicao);
    janela.draw(poderSprite);
}

void PoderesEspeciais::atualizar(sf::Time deltaTime)
{
    
    if ( (colisao.verificarColisao(posicao.x, posicao.y+tileSize+1) != 0 && colisao.verificarColisao(posicao.x, posicao.y+tileSize+1) !=9) ||
    (colisao.verificarColisao(posicao.x + tileSize, posicao.y+tileSize+1) != 0 && colisao.verificarColisao(posicao.x + tileSize, posicao.y+tileSize+1))) {
        // Movimento horizontal
        velocidadeVertical=0;
        if (movDireita) {
            posicao.x += 50.0f * deltaTime.asSeconds();
        } else if (movEsquerda) {
            posicao.x -= 50.0f * deltaTime.asSeconds();
        }
    } else {
        // Movimento vertical
        velocidadeVertical += aceleracaoGravidade;
        posicao.y += velocidadeVertical * deltaTime.asSeconds();
    }

    if ( (movDireita && colisao.verificarColisao(posicao.x + tileSize, posicao.y+tileSize/2) != 0 && colisao.verificarColisao(posicao.x + tileSize, posicao.y+tileSize/2)!=9) ) {
        // Colisão à direita, ajusta posição
        posicao.x -= 50.0f * deltaTime.asSeconds();
        movEsquerda = true;
        movDireita = false;
    } else if ( movEsquerda && colisao.verificarColisao(posicao.x, posicao.y+tileSize/2) != 0 && colisao.verificarColisao(posicao.x, posicao.y+tileSize/2)!=9)  {
        // Colisão à esquerda, ajusta posição
        posicao.x += 50.0f * deltaTime.asSeconds();
        movEsquerda = false;
        movDireita = true;
    }
}


