#include "Tartaruga.hpp"
#include <iostream>

Tartaruga::Tartaruga(Colisao &colisao, std::shared_ptr <sf::RenderWindow> janela1) : Personagem(colisao), janela(janela1)
{
    setVivo(true);
    setAlturaPersonagem(personagemTexture.getSize().y);
    setLarguraPersonagem(personagemTexture.getSize().x);
    setPosicaoPersonagem(sf::Vector2f(1000, getAlturaChao() + 50));
    personagemTexture.loadFromFile("../imagens/TartarugaEsq.png");
    janela->draw(personagemSprite);
}

void Tartaruga::atacar() {
}

void Tartaruga::inicializarTartarugas() {

}

bool Tartaruga::verificarColisaoDistanciaX(float x, float y, float largura){

    // Número de pontos a serem verificados entre x e x + largura
    int numeroDePontos = 10;  // Ajustar conforme necessário

    // Calcula a distância entre cada ponto
    float distanciaEntrePontos = largura / static_cast<float>(numeroDePontos - 1);

    // Loop para verificar colisão em cada ponto
    for (int i = 0; i < numeroDePontos; ++i) {
        // Calcula as coordenadas do ponto atual
        float pontoX = x + i * distanciaEntrePontos;
        float pontoY = y;

        // Verifica a colisão para o ponto atual
        if (colisao.verificarColisao(pontoX, pontoY) != 0 && colisao.verificarColisao(pontoX, pontoY) != 9) {
            // Retorna verdadeiro se houver colisão em algum ponto
            return true;
        }
    }

    // Retorna falso se não houver colisão em nenhum ponto
    return false;
}

void Tartaruga::modificarPosicao(sf::Time deltaTime, int larguraMapa) {
    // AINDA FALTA IMPLEMENTAR A QUEDA

    sf::Vector2f posicaoAtual = getPosicao();
    float velocidadeHorizontalAtual = getVelocidadeHorizontal();
    setVelocidadeHorizontal(30.0f);

    // Configurar para quando bater em alguma coisa rebater
    if (!getMovDireita()) {
        posicaoAtual.x -= velocidadeHorizontalAtual * deltaTime.asSeconds();
    }

    // Inverter a direção se houver colisão
    if (verificarColisaoDistanciaX(posicaoAtual.x + 35, posicaoAtual.y, getAlturaPersonagem() - 5)) {
        setMovDireita(!getMovDireita());
    }

    // Limitar a posição dentro dos limites do mapa
    if (posicaoAtual.x + 35 <= 0) {
        setMovDireita(true);
    } else if (posicaoAtual.x + 35 >= larguraMapa) {
        setMovDireita(false);
    }

    // Mover para a direita se a direção for positiva
    if (getMovDireita()) {
        posicaoAtual.x += velocidadeHorizontalAtual * deltaTime.asSeconds();
    }

    setPosicaoPersonagem(posicaoAtual);
}



void Tartaruga::morrer() {
    setVivo(false);
}

void Tartaruga::desenharTartaruga() {

    sf::Sprite sprite(personagemTexture); 
    sprite.setPosition(getPosicao());
    sprite.setTexture(personagemTexture);
    janela->draw(sprite);

}

Tartaruga::~Tartaruga(){

}
