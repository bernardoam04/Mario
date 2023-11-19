#include "PoderesEspeciais.hpp"

PoderesEspeciais::PoderesEspeciais()
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
    janela.draw(poderSprite);
}