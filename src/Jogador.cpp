#include "../include/Jogador.hpp"

/*TODO:
Melhorar os condicionais da funcao de movimentacao
Implementar corretamente a gravidade
Implemetar corretamente a colisao e pisar nas plataformas (interacao com os blocos do mapa)
Arrumar os spirtes*/


Jogador::Jogador(Colisao &colisao) : Personagem(colisao){

    setPosicaoPersonagem(sf::Vector2f(0.0,getAlturaChao())); 
    personagemTexture.loadFromFile("../imagens/MarioDir1.png");
    personagemSprite.setTexture(personagemTexture);
    personagemSprite.setOrigin(sf::Vector2f(8.5, 8.5));
    personagemSprite.setPosition(sf::Vector2f(0.0, 0.0));
    vida = 100;
    moedas = 0;
    ativarPoder = false;
}

Jogador::~Jogador() {
    
}

Jogador& Jogador::operator=(const Jogador& other) {
    if (this != &other) {
        // Atribuição dos membros adicionais da classe Jogador
        this->vida = other.vida;
        this->moedas = other.moedas;
        this->ativarPoder = other.ativarPoder;
    }
    return *this;
}

void Jogador::modificarPosicao(sf::Time deltaTime, int larguraMapa) {

    // Obtendo valores atuais
    float velocidadeHorizontalAtual = getVelocidadeHorizontal();
    float velocidadeVerticalAtual = getVelocidadeVertical();
    float tileSize = getTileSize();
    bool estaNoArAtual = getEstaNoAr();
    sf::Vector2f posicaoAtual = getPosicao();

    // Configurando nova velocidade horizontal (deve ser sincronizada com a camera ainda)
    setVelocidadeHorizontal(180.0f);

    // Movimentação horizontal
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
        ((colisao.verificarColisao(posicaoAtual.x, posicaoAtual.y + tileSize / 2) == 0  && //Verifica se nao tem nenhum bloco
        colisao.verificarColisao(posicaoAtual.x, posicaoAtual.y + tileSize + 1) != 9) || //Verifica se nao tem moeda
        (colisao.verificarColisao(posicaoAtual.x + tileSize, posicaoAtual.y + tileSize + 1) == 0 &&
        colisao.verificarColisao(posicaoAtual.x + tileSize, posicaoAtual.y + tileSize + 1) != 9)) &&
        (posicaoAtual.x > 0))//Verifica se o jogador esta nos limites do mapa
    {

        posicaoAtual.x -= velocidadeHorizontalAtual * deltaTime.asSeconds();
        setMovEsquerda(true);//ainda sera corrigido

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        ((colisao.verificarColisao(posicaoAtual.x, posicaoAtual.y + tileSize / 2) == 0  && //Verifica se nao tem nenhum bloco
        colisao.verificarColisao(posicaoAtual.x, posicaoAtual.y + tileSize + 1) != 9) || //Verifica se nao tem moeda
        (colisao.verificarColisao(posicaoAtual.x + tileSize, posicaoAtual.y + tileSize + 1) == 0 &&
        colisao.verificarColisao(posicaoAtual.x + tileSize, posicaoAtual.y + tileSize + 1) != 9)) &&
        (posicaoAtual.x < larguraMapa)) {//Verifica se o jogador esta nos limites do mapa

        posicaoAtual.x += velocidadeHorizontalAtual * deltaTime.asSeconds();
        setMovDireita(true);
    }

    // Verificação para pulo
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !estaNoArAtual  &&
        ((colisao.verificarColisao(posicaoAtual.x, posicaoAtual.y + tileSize / 2) == 0  && //Verifica se nao tem nenhum bloco
        colisao.verificarColisao(posicaoAtual.x, posicaoAtual.y + tileSize + 1) != 9) || //Verifica se nao tem moeda
        (colisao.verificarColisao(posicaoAtual.x + tileSize, posicaoAtual.y + tileSize + 1) == 0 &&
        colisao.verificarColisao(posicaoAtual.x + tileSize, posicaoAtual.y + tileSize + 1) != 9))
        ) {

        setVelocidadeVertical(-300.0f);
        setEstaNoAr(true);
    }

    // Aplicação da gravidade se estiver no ar
    if (estaNoArAtual) {
        posicaoAtual.y += velocidadeVerticalAtual * deltaTime.asSeconds();
        setVelocidadeVertical(velocidadeVerticalAtual + getAceleracaoGravidade());

    // Verifica se a posição é maior ou igual à altura do chão
    if (posicaoAtual.y >= getAlturaChao()) {
        posicaoAtual.y = getAlturaChao();  // Corrige a posição para a altura do chão
        setVelocidadeVertical(0);
        setEstaNoAr(false);
    }
}
    // Configurando a nova posição
    setPosicaoPersonagem(posicaoAtual);
}
