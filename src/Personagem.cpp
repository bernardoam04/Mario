#include "Personagem.hpp"


void Personagem::inicializarPersonagem(float x, float y)
{
    this->posicaoPersonagem = sf::Vector2f(x, y);
}

void Personagem::desenharPersonagem(sf::RenderWindow& janela)
{
    personagemSprite.setPosition(posicaoPersonagem);
    janela.draw(personagemSprite);
}

void Personagem::modificarPosicao(sf::Time deltaTime) {
    velocidadeHorizontal = 100.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        posicaoPersonagem.x -= velocidadeHorizontal * deltaTime.asSeconds();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        posicaoPersonagem.x += velocidadeHorizontal * deltaTime.asSeconds();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && estaNoAr == false) {
        velocidadeVertical = -300.0f;
        estaNoAr = true;
    }

    if (estaNoAr) {
        velocidadeVertical += 1;//IMPLEMENTAR GRAVIDADE PARA TIRAR ESSE NUM MAGICO
    }

    posicaoPersonagem.y += velocidadeVertical * deltaTime.asSeconds();
}