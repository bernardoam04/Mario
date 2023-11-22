#include "../include/PoderesEspeciais.hpp"
#include <iostream>
#include "PoderesEspeciais.hpp"
#include <random>

PoderesEspeciais::PoderesEspeciais(Colisao &colisao) : colisao(colisao)
{
    sf::Texture cogumeloTexture, cogumeloTexture1, cogumeloTexture2;
    sf::Texture estrelaTexture, estrelaTexture1, estrelaTexture2, estrelaTexture3;

    //Carregamento dos cogumelos
    cogumeloTexture.loadFromFile("../imagens/cogumelo.png");
    cogumeloTextures.push_back(cogumeloTexture);

    cogumeloTexture1.loadFromFile("../imagens/cogumelo2.png");
    cogumeloTextures.push_back(cogumeloTexture1);

    cogumeloTexture2.loadFromFile("../imagens/cogumelo3.png");
    cogumeloTextures.push_back(cogumeloTexture2);

    //Carregamento das estrelas
    estrelaTexture.loadFromFile("../imagens/estrela.png");
    estrelaTextures.push_back(estrelaTexture);

    estrelaTexture1.loadFromFile("../imagens/estrela2.png");
    estrelaTextures.push_back(estrelaTexture1);

    estrelaTexture2.loadFromFile("../imagens/estrela3.png");
    estrelaTextures.push_back(estrelaTexture2);

    estrelaTexture3.loadFromFile("../imagens/estrela4.png");
    estrelaTextures.push_back(estrelaTexture3);
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

    tipo = gerarTipoAleatorio();

    // Configura o sprite e a textura com base no tipo
    switch (tipo) {
        case COGUMELO:
            poderSprite.setTexture(cogumeloTextures[0]);
            break;
        case ESTRELA:
            poderSprite.setTexture(estrelaTextures[0]);
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
            posicao.x += velocidadeHorizontal * deltaTime.asSeconds();
        } else if (movEsquerda) {
            posicao.x -= velocidadeHorizontal * deltaTime.asSeconds();
        }    
    } 
    else {
        // Movimento vertical
        velocidadeVertical += aceleracaoGravidade;
        posicao.y += velocidadeVertical * deltaTime.asSeconds();
    }

    //Verificação de colisão com as laterais direita e esquerda
    if ( (movDireita && colisao.verificarColisao(posicao.x + tileSize, posicao.y+tileSize/2) != 0 && colisao.verificarColisao(posicao.x + tileSize, posicao.y+tileSize/2)!=9) ) {

        // Colisão à direita, ajusta posição
        posicao.x -= velocidadeHorizontal * deltaTime.asSeconds();
        movEsquerda = true;
        movDireita = false;
    }
    else if ( movEsquerda && colisao.verificarColisao(posicao.x, posicao.y+tileSize/2) != 0 && colisao.verificarColisao(posicao.x, posicao.y+tileSize/2)!=9)  {
        // Colisão à esquerda, ajusta posição
        posicao.x += velocidadeHorizontal * deltaTime.asSeconds();
        movEsquerda = false;
        movDireita = true;
    }
}

void PoderesEspeciais::atualizar(sf::Time tempoAtual, sf::Time deltaTime)
{
    int tempo = static_cast<int> (tempoAtual.asSeconds());
    tempo = tempo % 4;

    //Atualização da textura de acordo com o tempo
    switch (tipo) {
        case COGUMELO:
            if(tempo == 3){
                poderSprite.setTexture(cogumeloTextures[1]);
            }
            else{
                poderSprite.setTexture(cogumeloTextures[tempo]);
            }
                break;
        case ESTRELA:
            poderSprite.setTexture(estrelaTextures[tempo]);
            break;
    }

    ModificacaoPosicao(deltaTime);
}


