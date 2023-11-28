#include "../include/Jogador.hpp"
#include "Jogador.hpp"

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
    alturaJogador = personagemTexture.getSize().y;
    larguraJogador = personagemTexture.getSize().x;
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

bool Jogador::verificarColisaoDistanciaX(float x, float y, float largura) {
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

bool Jogador::verificarColisaoDistanciaY(float x, float y, float altura)
{
    // Número de pontos a serem verificados entre x e x + largura
    int numeroDePontos = 10;  // Ajustar conforme necessário

    // Calcula a distância entre cada ponto
    float distanciaEntrePontos = altura / static_cast<float>(numeroDePontos - 1);

    // Loop para verificar colisão em cada ponto
    for (int i = 0; i < numeroDePontos; ++i) {
        // Calcula as coordenadas do ponto atual
        float pontoX = x;
        float pontoY = y + i * distanciaEntrePontos;

        // Verifica a colisão para o ponto atual
        if (colisao.verificarColisao(pontoX, pontoY) != 0 && colisao.verificarColisao(pontoX, pontoY) != 9) {
            // Retorna verdadeiro se houver colisão em algum ponto
            return true;
        }
    }

    // Retorna falso se não houver colisão em nenhum ponto
    return false;
}


void Jogador::modificarPosicao(sf::Time deltaTime, int larguraMapa) {

    // Obtendo valores atuais
    float velocidadeHorizontalAtual = getVelocidadeHorizontal();
    float velocidadeVerticalAtual = getVelocidadeVertical();
    bool estaNoArAtual = getEstaNoAr();
    sf::Vector2f posicaoAtual = getPosicao();

    // Configurando nova velocidade horizontal (deve ser sincronizada com a camera ainda)
    setVelocidadeHorizontal(180.0f);

    // Movimentação horizontal
    if (estaMovendoEsquerda() && !verificarColisaoDistanciaY(posicaoAtual.x, posicaoAtual.y, alturaJogador-3) 
        && (posicaoAtual.x > 0))//Verifica se o jogador esta nos limites do mapa
    {
        posicaoAtual.x -= velocidadeHorizontalAtual * deltaTime.asSeconds();
        setMovEsquerda(true);
    } 
    else if(estaMovendoEsquerda() && verificarColisaoDistanciaY(posicaoAtual.x, posicaoAtual.y, alturaJogador-3) ){
        setMovEsquerda(false);
    }
    else if (estaMovendoDireita() && !verificarColisaoDistanciaY(posicaoAtual.x +larguraJogador, posicaoAtual.y, alturaJogador-3) 
        && (posicaoAtual.x < larguraMapa)) {//Verifica se o jogador esta nos limites do mapa

        posicaoAtual.x += velocidadeHorizontalAtual * deltaTime.asSeconds();
        setMovDireita(true);
    }
    else if(estaMovendoDireita() && verificarColisaoDistanciaY(posicaoAtual.x +larguraJogador, posicaoAtual.y, alturaJogador-3) ){
        setMovDireita(false);
    }

    // Verificação para pulo
    if (estaPulando() && !estaNoArAtual  && verificarColisaoDistanciaX(posicaoAtual.x, posicaoAtual.y+alturaJogador, larguraJogador) 
        ) {
        setVelocidadeVertical(-350.0f);
        setEstaNoAr(true);
    }
    // Aplicação da gravidade se estiver no ar
    if (estaNoArAtual) {
        if(getVelocidadeVertical()< 200 || getVelocidadeVertical()<0){
            setVelocidadeVertical(velocidadeVerticalAtual + getAceleracaoGravidade());
        }
        posicaoAtual.y += velocidadeVerticalAtual * deltaTime.asSeconds();

        // Verifica se a posição é maior ou igual à altura do chão
        if (verificarColisaoDistanciaX(posicaoAtual.x +3, posicaoAtual.y+alturaJogador, larguraJogador-6)) {
            setVelocidadeVertical(0);
            setEstaNoAr(false);
        }
        else if (verificarColisaoDistanciaX(posicaoAtual.x +3, posicaoAtual.y, larguraJogador - 6)) {
            setVelocidadeVertical(50); 
            colisaoCabeca = true;
        }
    }
    else{
        if (!verificarColisaoDistanciaX(posicaoAtual.x+3, posicaoAtual.y+alturaJogador, larguraJogador - 6)) {
            setEstaNoAr(true);
        }
    }
    
    if (colisaoCabeca) {
        if(getVelocidadeVertical()<200){
            setVelocidadeVertical(getVelocidadeVertical() + getAceleracaoGravidade());
            posicaoAtual.y += velocidadeVerticalAtual * deltaTime.asSeconds();
        }
        if (!verificarColisaoDistanciaX(posicaoAtual.x + 3, posicaoAtual.y, larguraJogador - 6)) {
            colisaoCabeca = false;
            // Movimentação horizontal
        if (estaMovendoEsquerda() && !verificarColisaoDistanciaY(posicaoAtual.x, posicaoAtual.y, alturaJogador-3) 
            && (posicaoAtual.x > 0))//Verifica se o jogador esta nos limites do mapa
        {

            posicaoAtual.x -= velocidadeHorizontalAtual * deltaTime.asSeconds();
            setMovEsquerda(true);//ainda sera corrigido

        } else if (estaMovendoDireita() && !verificarColisaoDistanciaY(posicaoAtual.x +larguraJogador, posicaoAtual.y, alturaJogador-3) 
            && (posicaoAtual.x < larguraMapa)) {//Verifica se o jogador esta nos limites do mapa

            posicaoAtual.x += velocidadeHorizontalAtual * deltaTime.asSeconds();
            setMovDireita(true);
        }
        }

    }
    // Configurando a nova posição
    setPosicaoPersonagem(posicaoAtual);
}

int Jogador::getLarguraJogador()
{
    return larguraJogador;
}

void Jogador::setMovendoDireita(bool movendo)
{
    movendoDireita = movendo;
}

void Jogador::setMovendoEsquerda(bool movendo) {
    movendoEsquerda = movendo;
}

void Jogador::setPulando(bool pulo) {
    pulando = pulo;
}

void Jogador::atualizarColisao(Mapa &mapa)
{
    int posicaoX = static_cast<int>(getPosicao().x + larguraJogador/2);
    int posicaoY = static_cast<int>(getPosicao().y);

    mapa.aplicarColisaoBlocoMoeda(posicaoX, posicaoY);

    int posicaoX2 = static_cast<int>(getPosicao().x + larguraJogador/2);
    int posicaoY2 = static_cast<int>(getPosicao().y + alturaJogador* 0.75);

    mapa.aplicarColisaoMoeda(posicaoX2, posicaoY2);
}
