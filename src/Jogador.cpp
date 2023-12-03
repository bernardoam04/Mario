#include "../include/Jogador.hpp"
#include "Jogador.hpp"

Jogador::Jogador(Colisao &colisao, const float larguraTela, const float alturaTelaJogo, std::shared_ptr <sf::RenderWindow> janela1) 
: Personagem(colisao), janela(janela1) ,alturaTela(alturaTelaJogo)
{
    setPosicaoPersonagem(sf::Vector2f(larguraTela/2,getAlturaChao())); 
    setVivo(true);
    personagemTexture.loadFromFile("../imagens/marioPequeno.png");
    personagemSprite.setTexture(personagemTexture);
    personagemSprite.setOrigin(sf::Vector2f(8.5, 8.5));
    personagemSprite.setPosition(sf::Vector2f(0.0, 0.0));
    setPosicaoPersonagem(sf::Vector2f(larguraTela/2,getAlturaChao() - personagemTexture.getSize().y)); 

    personagemMorreuTexture.loadFromFile("../imagens/marioPerdeu.png");
    personagemMorreuSprite.setTexture(personagemTexture);
    personagemMorreuSprite.setOrigin(sf::Vector2f(8.5, 8.5));
    personagemMorreuSprite.setPosition(sf::Vector2f(0.0, 0.0));

    moedas = 0;
    alturaJogador = personagemTexture.getSize().y;
    larguraJogador = personagemTexture.getSize().x;
    contadorAndadaDir = 0;
    contadorAndadaEsq = 0;
    setVelocidadeVertical(0);

    mariosDireita.push_back(loadTexture("../imagens/marioDir1.png"));
    mariosDireita.push_back(loadTexture("../imagens/marioDir2.png"));
    mariosDireita.push_back(loadTexture("../imagens/marioDir3.png"));
    mariosDireita.push_back(loadTexture("../imagens/marioDir4.png"));
    mariosEsquerda.push_back(loadTexture("../imagens/marioEsq1.png"));
    mariosEsquerda.push_back(loadTexture("../imagens/marioEsq2.png"));
    mariosEsquerda.push_back(loadTexture("../imagens/marioEsq3.png"));
    mariosEsquerda.push_back(loadTexture("../imagens/marioEsq4.png"));

    mariosPequenosDireita.push_back(loadTexture("../imagens/marioPequenoPulandoDir.png"));
    mariosPequenosEsquerda.push_back(loadTexture("../imagens/marioPequenoPulandoEsq.png"));
    mariosPequenosDireita.push_back(loadTexture("../imagens/marioDir1Peq.png"));
    mariosPequenosDireita.push_back(loadTexture("../imagens/marioDir2Peq.png"));
    mariosPequenosDireita.push_back(loadTexture("../imagens/marioDir3Peq.png"));
    mariosPequenosDireita.push_back(loadTexture("../imagens/marioDir4Peq.png"));
    mariosPequenosEsquerda.push_back(loadTexture("../imagens/marioEsq1Peq.png"));
    mariosPequenosEsquerda.push_back(loadTexture("../imagens/marioEsq2Peq.png"));
    mariosPequenosEsquerda.push_back(loadTexture("../imagens/marioEsq3Peq.png"));
    mariosPequenosEsquerda.push_back(loadTexture("../imagens/marioEsq4Peq.png"));
    estaGrande = false;

    inicializarBooleanos();
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
    if(vida == 1){
        int alturaJogadorAnterior = alturaJogador;
        // Atualiza a altura da textura
        personagemTexture.loadFromFile("../imagens/marioGrande.png"); 
        alturaJogador = mariosDireita[0].getSize().y;

        // Ajusta a posição vertical do jogador para compensar a mudança de altura
        sf::Vector2f posicaoAtual = getPosicao();
        posicaoAtual.y -= (alturaJogador - alturaJogadorAnterior);  // Ajuste pela metade da nova altura
        setPosicaoPersonagem(posicaoAtual);
        vida++;
    }
}

void Jogador::modificarPosicao(sf::Time deltaTime, int larguraMapa)
{
    // Obtendo valores atuais
    float velocidadeHorizontalAtual = getVelocidadeHorizontal();
    bool estaNoArAtual = getEstaNoAr();
    sf::Vector2f posicaoAtual = getPosicao();
    if(!estaMovendoDireita()){
        contadorAndadaDir = 0;
    }
    if(!estaMovendoEsquerda()){
        contadorAndadaEsq = 0;
    }

    // Verificar e desativar invencibilidade após 2.5 segundos se jogador foi atingido
    if (invencivel && temporizadorInvencivel.getElapsedTime().asSeconds() >= 2.5f && !pegouEstrela) {
        invencivel = false;
    }

    // Verificar e desativar invencibilidade após 10 segundos se jogador pegou estrela
    else if (invencivel && temporizadorInvencivel.getElapsedTime().asSeconds() >= 10.0f && pegouEstrela) {
        invencivel = false;
        pegouEstrela = false;
    }

    // Configurando nova velocidade horizontal 
    setVelocidadeHorizontal(180.0f);

    // Movimentação horizontal
    if (estaMovendoEsquerda() && !verificarColisaoDistanciaY(posicaoAtual.x-2, posicaoAtual.y, alturaJogador-5) 
        && (posicaoAtual.x > 0))//Verifica se o jogador esta nos limites do mapa
    {
        posicaoAtual.x -= velocidadeHorizontalAtual * deltaTime.asSeconds();
        setMovEsquerda(true);
        contadorAndadaEsq++;
    } 
    else if(estaMovendoEsquerda() && verificarColisaoDistanciaY(posicaoAtual.x-2, posicaoAtual.y, alturaJogador-5) ){
        setMovEsquerda(false);
    }
    else if (estaMovendoDireita() && !verificarColisaoDistanciaY(posicaoAtual.x +larguraJogador+2, posicaoAtual.y, alturaJogador-5) 
        && (posicaoAtual.x < larguraMapa)) {//Verifica se o jogador esta nos limites do mapa

        posicaoAtual.x += velocidadeHorizontalAtual * deltaTime.asSeconds();
        setMovDireita(true);
        contadorAndadaDir++;
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

    //Caso o mario pule em um Goomba
    if (puloemGoomba){
        setVelocidadeVertical(-100.0f);
        puloemGoomba = false;
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
    
    //Mudanças de posição caso o mario bata a cabeça em algum bloco
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

    //Se o mario chegar na posição final ele ganha
    if(posicaoAtual.x> 7200){
        posicaoAtual.x = 7200;
        ganhou = true;
    }

    //Se o mario cair ele perde
    if(posicaoAtual.y > alturaTela){
        vida = 0;
        perdeu = true;
    }

    if(vida==0){
        perdeu = true;
    }

    if(getVelocidadeVertical() < 0){
        subindo = true;
    }
    else{
        subindo = false;
    }

    // Configurando a nova posição
    setPosicaoPersonagem(posicaoAtual);
}

void Jogador::inicializarBooleanos()
{
    subindo = false;
    pegouEstrela = false;
    invencivel = false;
    puloemGoomba = false;
    setEstaNoAr(false);
    ativarPoder = false;
    movendoDireita = false;
    movendoEsquerda = false;
    pulando = false;
    colisaoCabeca = false;
    ganhou = false;
    perdeu = false;
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
bool Jogador::getPerdeu()
{
    return perdeu;
}

bool Jogador::estaInvencivel()
{
    return invencivel;
}

bool Jogador::estaSubindo()
{
    return subindo;
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

void Jogador::setPuloEmGoomba(bool pulo)
{
    puloemGoomba = pulo;
}

void Jogador::setEstaGrande(bool valor){
    estaGrande = valor;
}

void Jogador::ficarInvencivel()
{
    invencivel = true;
    temporizadorInvencivel.restart();
}

void Jogador::pegarEstrela()
{
    pegouEstrela = true;
    ficarInvencivel();
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

void Jogador::perdeuMudarTextura(){
    personagemTexture.loadFromFile("../imagens/marioPerdeu.png"); 
}

void Jogador::desenhar() {

    //Lógica pra desenhar marios grandes andando
    if(!getEstaNoAr()&& vida > 1){ //Mario grande
        contadorAndadaDir = contadorAndadaDir % 16;
        contadorAndadaEsq = contadorAndadaEsq % 16;

        alturaJogador = mariosDireita[0].getSize().y;
        larguraJogador = mariosDireita[0].getSize().x;

        sf::Sprite sprite(mariosDireita[contadorAndadaDir/4]); 

        if(estaMovendoEsquerda()){
            sprite.setTexture(mariosEsquerda[contadorAndadaEsq/4]);
        }
        sprite.setPosition(getPosicao());
        
        janela->draw(sprite);
    }
    else if(getEstaNoAr() && vida > 1){
        alturaJogador = mariosDireita[0].getSize().y;
        larguraJogador = mariosDireita[0].getSize().x;

        sf::Sprite sprite(mariosDireita[0]); 

        if(estaMovendoEsquerda()){
            sprite.setTexture(mariosEsquerda[0]);
        }
        sprite.setPosition(getPosicao());
        
        janela->draw(sprite);
    }

    //Lógica pra desenhar marios pequenos andando
     else if(!getEstaNoAr() && vida == 1){ // Mario pequeno

        contadorAndadaDir = contadorAndadaDir % 16;
        contadorAndadaEsq = contadorAndadaEsq % 16;

        alturaJogador = mariosPequenosDireita[0].getSize().y;
        larguraJogador = mariosPequenosDireita[0].getSize().x;

        sf::Sprite sprite(mariosPequenosDireita[(contadorAndadaDir/4)+1]); 

        if(estaMovendoEsquerda()){
            sprite.setTexture(mariosPequenosEsquerda[(contadorAndadaEsq/4)+1]);
        }
        sprite.setPosition(getPosicao());
        
        janela->draw(sprite);
    }

    //Lógica pra desenhar marios pequenos no ar (só usa um sprite à esquerda e um a direita com a mão pra cima)
    else if(getEstaNoAr() && vida == 1){
        alturaJogador = personagemTexture.getSize().y;
        larguraJogador = personagemTexture.getSize().x;

        sf::Sprite sprite(mariosPequenosDireita[0]); 

        if(estaMovendoEsquerda()){
            sprite.setTexture(mariosPequenosEsquerda[0]);
        }
        sprite.setPosition(getPosicao());
        
        janela->draw(sprite);
    }
    if(getPerdeu()){
        alturaJogador = personagemTexture.getSize().y;
        larguraJogador = personagemTexture.getSize().x;

        sf::Sprite sprite(mariosPequenosDireita[0]); 

        sprite.setTexture(personagemMorreuTexture);
        sprite.setPosition(getPosicao());
        
        janela->draw(sprite);        
    }
}

void Jogador::perderVida()
{
    if(vida > 0 && !invencivel){
        vida--;
        int alturaJogadorAnterior = alturaJogador;
        // Atualiza a altura da textura
        personagemTexture.loadFromFile("../imagens/marioPequeno.png"); 
        alturaJogador = mariosPequenosDireita[0].getSize().y;
        larguraJogador = mariosPequenosDireita[0].getSize().x;

        // Ajusta a posição vertical do jogador para compensar a mudança de altura
        sf::Vector2f posicaoAtual = getPosicao();
        posicaoAtual.y += (alturaJogadorAnterior - alturaJogador);  // Ajuste pela metade da nova altura
        setPosicaoPersonagem(posicaoAtual);
    }
}

