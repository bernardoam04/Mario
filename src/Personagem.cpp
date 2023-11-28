#include "../include/Personagem.hpp"

Personagem::Personagem(Colisao &colisao) : colisao(colisao)
{
    personagemSprite.setTexture(personagemTexture);
    personagemSprite.setPosition(posicaoPersonagem);
}

void Personagem::modificarPosicao(sf::Time deltaTime, int larguraMapa) {
    (void)deltaTime;  // Evita o aviso de parâmetro não utilizado
    (void)larguraMapa;
}

sf::Vector2f Personagem::getPosicao() const {
    return posicaoPersonagem;
}

sf::Texture Personagem::getTexture() const {
    return personagemTexture;
}

float Personagem::getAceleracaoGravidade() const {
    return aceleracaoGravidade;

}

float Personagem::getVelocidadeHorizontal() const {
    return velocidadeHorizontal;
}

float Personagem::getVelocidadeVertical() const {
    return velocidadeVertical;
}
float Personagem::getAlturaChao() const {
    return alturaChao;
}

bool Personagem::getEstaNoAr() const {
    return estaNoAr;
}

float Personagem::getTileSize() const{
    return tileSize;
}

bool Personagem::getMovEsquerda() const {
    return movEsquerda;
}

bool Personagem::getMovDireita() const {
    return movDireita;
}

void Personagem::setPosicaoPersonagem(const sf::Vector2f& posicao) {
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

void Personagem::setMovEsquerda(bool movimento) {
    movEsquerda = movimento;
}

void Personagem::setMovDireita(bool movimento) {
    movDireita = movimento;
}