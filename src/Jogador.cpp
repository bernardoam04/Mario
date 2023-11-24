#include "../include/Jogador.hpp"

Jogador::Jogador(){
    jogadorTexture.loadFromFile("../imagens/cogumelo.png");
}

void Jogador::modificarPosicao(sf::Time deltaTime) {
    // Obtendo valores atuais
    float velocidadeHorizontalAtual = getVelocidadeHorizontal();
    float velocidadeVerticalAtual = getVelocidadeVertical();
    bool estaNoArAtual = getEstaNoAr();
    sf::Vector2f posicaoAtual = getPosicao();

    // Configurando nova velocidade horizontal
    setVelocidadeHorizontal(100.0f);

    // Movimentação horizontal
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        posicaoAtual.x -= velocidadeHorizontalAtual * deltaTime.asSeconds();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        posicaoAtual.x += velocidadeHorizontalAtual * deltaTime.asSeconds();
    }

    // Verificação para pulo
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !estaNoArAtual) {
        setVelocidadeVertical(-300.0f);
        setEstaNoAr(true);
    }

    // Aplicação da gravidade se estiver no ar
    if (estaNoArAtual) {
        setVelocidadeVertical(velocidadeVerticalAtual + 1); // IMPLEMENTAR GRAVIDADE
    }

    // Atualização da posição vertical
    posicaoAtual.y += velocidadeVerticalAtual * deltaTime.asSeconds();

    // Configurando a nova posição
    setPosicao(posicaoAtual);
}