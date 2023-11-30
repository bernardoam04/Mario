#include "Tartaruga.hpp"

Tartaruga::Tartaruga(Colisao &colisao, std::shared_ptr <sf::RenderWindow> janela1) : Personagem(colisao), janela(janela1)
{
    setVivo(true);
    personagemTexture.loadFromFile("");
    personagemSprite.setOrigin(sf::Vector2f(8.5, 8.5));
    personagemSprite.setPosition(sf::Vector2f(0.0, 0.0));
    setAlturaPersonagem(personagemTexture.getSize().y);
    setLarguraPersonagem(personagemTexture.getSize().x);
}

void Tartaruga::atacar() {
}

void Tartaruga::modificarPosicao(sf::Time deltaTime, int larguraMapa) {//Ainda nao implementado (obviamente)
    (void)deltaTime;
    (void)larguraMapa;
}

void Tartaruga::morrer() {
    setVivo(false);
}

void Tartaruga::desenharTartaruga() {

    sf::Sprite sprite(personagemTexture);  // Tamanho do sprite
    sprite.setPosition(getPosicao());
    janela->draw(sprite);

}
