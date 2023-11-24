#include "../include/Personagem.hpp"

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
    // Implementação padrão para personagens não controlados pelo jogador

    // Lógica de movimentação automática (Sera melhorada conforme a colisao ainda)
    float velocidadeHorizontal = 50.0f;
    float aceleracaoGravidade = 9.8f;

    // Movimentação automática para a direita
    posicaoPersonagem.x += velocidadeHorizontal * deltaTime.asSeconds();

    // Simulação simples de gravidade
    velocidadeVertical += aceleracaoGravidade;
    posicaoPersonagem.y += velocidadeVertical * deltaTime.asSeconds();


}

sf::Vector2f Personagem::getPosicao() const {
    return posicaoPersonagem;
}

float Personagem::getVelocidadeHorizontal() const {
    return velocidadeHorizontal;
}

float Personagem::getVelocidadeVertical() const {
    return velocidadeVertical;
}

bool Personagem::getEstaNoAr() const {
    return estaNoAr;
}

void Personagem::setPosicao(const sf::Vector2f& posicao) {
    posicaoPersonagem = posicao;
}

void Personagem::setVelocidadeHorizontal(float velocidade) {
    velocidadeHorizontal = velocidade;
}

void Personagem::setVelocidadeVertical(float velocidade) {
    velocidadeVertical = velocidade;
}

void Personagem::setEstaNoAr(bool estado) {
    estaNoAr = estado;
}