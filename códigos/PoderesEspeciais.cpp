#include "PoderesEspeciais.hpp"

PoderesEspeciais::PoderesEspeciais(Colisao& colisao) : colisao(colisao) 
{

    cogumeloTexture.loadFromFile("../imagens/cogumelo.png"); 
    estrelaTexture.loadFromFile("../imagens/estrela.png"); 
}

void PoderesEspeciais::inicializar(int tipo, float x, float y)
{
    this->tipo = tipo;
    this->posicao.x = x;
    this->posicao.y = y;

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

int PoderesEspeciais::verificarColisaoPoder(float x, float y)
{
    return colisao.verificarColisao(x,y);
}

void PoderesEspeciais::atualizar(sf::Time deltaTime)
{
    float x = posicao.x +tileSize/2;
    float y = posicao.y+tileSize;
    velocidadeVertical +=aceleracaoGravidade;

    if(colisao.verificarColisao(x, y)  != 0 && colisao.verificarColisao(x, y) != 9  ) {
        posicao.x += 50.0f * deltaTime.asSeconds();
    }

    else{
        posicao.y += velocidadeVertical * deltaTime.asSeconds();
    }
    // Ajuste a velocidade horizontal conforme necessário
}


