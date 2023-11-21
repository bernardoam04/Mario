#include "../include/PoderesEspeciais.hpp"
#include <iostream>
#include "PoderesEspeciais.hpp"
#include <random>

PoderesEspeciais::PoderesEspeciais(Colisao &colisao) : colisao(colisao)
{
    cogumeloTexture.loadFromFile("../imagens/cogumelo.png"); 
    estrelaTexture.loadFromFile("../imagens/estrela.png");
}

int PoderesEspeciais::gerarTipoAleatorio()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(COGUMELO, ESTRELA);

    return dis(gen);
}


void PoderesEspeciais::inicializar(float x, float y)
{
    this->posicao = sf::Vector2f(x, y);

    int tipo = gerarTipoAleatorio();
    // Configure o sprite e a textura com base no tipo
    switch (tipo) {
        case COGUMELO:
            poderSprite.setTexture(cogumeloTexture);
            break;
        case ESTRELA:
            poderSprite.setTexture(estrelaTexture);
            break;
    }
    poderSprite.setPosition(posicao);
}

void PoderesEspeciais::desenhar(sf::RenderWindow& janela) 
{
    poderSprite.setPosition(posicao);
    janela.draw(poderSprite);
}

void PoderesEspeciais::ModificacaoPosicao(sf::Time deltaTime)
{
        //Verificação de colisão com o chão (gravidade)
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

    //Verificação de colisão com as laterais direita e esquerda
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


void PoderesEspeciais::atualizar(sf::Time deltaTime)
{
    ModificacaoPosicao(deltaTime);
}


