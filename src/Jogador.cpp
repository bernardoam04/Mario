#include "../include/Jogador.hpp"
#include "Jogador.hpp"

/*TODO:
Melhorar os condicionais da funcao de movimentacao
Implementar corretamente a gravidade
Implemetar corretamente a colisao e pisar nas plataformas (interacao com os blocos do mapa)
Arrumar os spirtes*/


Jogador::Jogador(Colisao &colisao, const float larguraTela, std::shared_ptr <sf::RenderWindow> janela1) : Personagem(colisao), janela(janela1){

    setPosicaoPersonagem(sf::Vector2f(larguraTela/2,getAlturaChao())); 
    setVivo(true);
    personagemTexture.loadFromFile("../imagens/marioPequeno.png");
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

void Jogador::dobrarAltura()
{
    int alturaJogadorAnterior = alturaJogador;
    // Atualiza a altura da textura
    personagemTexture.loadFromFile("../imagens/marioGrande.png"); 
    alturaJogador = personagemTexture.getSize().y;

    // Ajusta a posição vertical do jogador para compensar a mudança de altura
    sf::Vector2f posicaoAtual = getPosicao();
    posicaoAtual.y -= (alturaJogador - alturaJogadorAnterior);  // Ajuste pela metade da nova altura
    setPosicaoPersonagem(posicaoAtual);

    // Incrementa a vida se for menor que 2
    if (vida < 2)
    {
        vida++;
    }
}

void Jogador::modificarPosicao(sf::Time deltaTime, int larguraMapa)
{

    // Obtendo valores atuais
    float velocidadeHorizontalAtual = getVelocidadeHorizontal();
    bool estaNoArAtual = getEstaNoAr();
    sf::Vector2f posicaoAtual = getPosicao();

    // Configurando nova velocidade horizontal (deve ser sincronizada com a camera ainda)
    setVelocidadeHorizontal(180.0f);

    // Movimentação horizontal
    if (estaMovendoEsquerda() && !verificarColisaoDistanciaY(posicaoAtual.x-2, posicaoAtual.y, alturaJogador-5) 
        && (posicaoAtual.x > 0))//Verifica se o jogador esta nos limites do mapa
    {
        posicaoAtual.x -= velocidadeHorizontalAtual * deltaTime.asSeconds();
        setMovEsquerda(true);
    } 
    else if(estaMovendoEsquerda() && verificarColisaoDistanciaY(posicaoAtual.x-2, posicaoAtual.y, alturaJogador-5) ){
        setMovEsquerda(false);
    }
    else if (estaMovendoDireita() && !verificarColisaoDistanciaY(posicaoAtual.x +larguraJogador+2, posicaoAtual.y, alturaJogador-5) 
        && (posicaoAtual.x < larguraMapa)) {//Verifica se o jogador esta nos limites do mapa

        posicaoAtual.x += velocidadeHorizontalAtual * deltaTime.asSeconds();
        setMovDireita(true);
    }
    else if(estaMovendoDireita() && verificarColisaoDistanciaY(posicaoAtual.x +larguraJogador+2, posicaoAtual.y, alturaJogador-5) ){
        setMovDireita(false);
    }

    // Verificação para pulo
    if (estaPulando() && !estaNoArAtual  && verificarColisaoDistanciaX(posicaoAtual.x, posicaoAtual.y+alturaJogador+1, larguraJogador) 
        ) {
        setVelocidadeVertical(-400.0f);
        setEstaNoAr(true);
    }
    // Aplicação da gravidade se estiver no ar
    if (estaNoArAtual) {
        if (!verificarColisaoDistanciaX(posicaoAtual.x +3, posicaoAtual.y+alturaJogador + (getVelocidadeVertical()* deltaTime.asSeconds()), larguraJogador-6) && getVelocidadeVertical()>0){
            setVelocidadeVertical(getVelocidadeVertical() + getAceleracaoGravidade());
            posicaoAtual.y += getVelocidadeVertical() * deltaTime.asSeconds();
        }
        if(getVelocidadeVertical()<0 || getVelocidadeVertical() ==0){
            setVelocidadeVertical(getVelocidadeVertical() + getAceleracaoGravidade());
            posicaoAtual.y += getVelocidadeVertical() * deltaTime.asSeconds();
        }
        if (verificarColisaoDistanciaX(posicaoAtual.x +3, posicaoAtual.y+alturaJogador + (getVelocidadeVertical()* deltaTime.asSeconds()), larguraJogador-6) && getVelocidadeVertical()>0){
            setVelocidadeVertical(30);
            posicaoAtual.y += getVelocidadeVertical() * deltaTime.asSeconds();
        }
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
        if (!verificarColisaoDistanciaX(posicaoAtual.x +3, posicaoAtual.y+alturaJogador + getVelocidadeVertical(), larguraJogador-6)){
            setVelocidadeVertical(getVelocidadeVertical() + getAceleracaoGravidade());
            posicaoAtual.y += getVelocidadeVertical() * deltaTime.asSeconds();
        }
        if(getVelocidadeVertical()<0 ||getVelocidadeVertical()==0 ){
            setVelocidadeVertical(getVelocidadeVertical() + getAceleracaoGravidade());
            posicaoAtual.y += getVelocidadeVertical() * deltaTime.asSeconds();
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

    if(posicaoAtual.y > 900){//Verifica se o jogador caiu do mapa
        setVivo(false);
    }

    if(posicaoAtual.x> 7200){
        posicaoAtual.x = 7200;
        ganhou = true;
    }

    // Configurando a nova posição
    setPosicaoPersonagem(posicaoAtual);
}

int Jogador::getLarguraJogador()
{
    return larguraJogador;
}

int Jogador::getAlturaJogador()
{
    return alturaJogador;
}
bool Jogador::getGanhou()
{
    return ganhou;
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
    std::vector<std::pair<int,int>> posicoes(2);
    int posicaoX = static_cast<int>(getPosicao().x + larguraJogador/2);
    int posicaoY = static_cast<int>(getPosicao().y);

    int posicaoX2 = static_cast<int>(getPosicao().x + larguraJogador/2);
    int posicaoY2 = static_cast<int>(getPosicao().y + alturaJogador* 0.75);

    posicoes[0] = std::make_pair(posicaoX, posicaoY);
    posicoes[1] = std::make_pair(posicaoX2, posicaoY2);

    mapa.aplicarColisao(posicoes);
}


void Jogador::desenhar() {//TRANSFERIR ESSA FUNCAO PRA CLASSE PERSONAGEM DEPOIS
    sf::Sprite sprite(personagemTexture);  // Tamanho do sprite
    sprite.setPosition(getPosicao());
    janela->draw(sprite);
}