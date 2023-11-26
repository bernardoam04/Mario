#include "../include/PoderesEspeciais.hpp"
#include <iostream>
#include <random>
#include "PoderesEspeciais.hpp"

PoderesEspeciais::PoderesEspeciais(Colisao &colisao) : colisao(colisao)
{
    carregarMoedas();
    carregarPoderes();
}

void PoderesEspeciais::carregarPoderes(){

    sf::Texture cogumeloTexture;
    sf::Texture estrelaTexture;
        
    //Carregamento dos cogumelos
    cogumeloTexture.loadFromFile("../imagens/cogumelo.png");
    cogumeloTextures.push_back(cogumeloTexture);

    cogumeloTexture.loadFromFile("../imagens/cogumelo3.png");
    cogumeloTextures.push_back(cogumeloTexture);

    //Carregamento das estrelas
    estrelaTexture.loadFromFile("../imagens/estrela.png");
    estrelaTextures.push_back(estrelaTexture);

    estrelaTexture.loadFromFile("../imagens/estrela2.png");
    estrelaTextures.push_back(estrelaTexture);

    estrelaTexture.loadFromFile("../imagens/estrela4.png");
    estrelaTextures.push_back(estrelaTexture);
}


void PoderesEspeciais::carregarMoedas(){
    sf::Texture moedaTexture;  

    // Carregamento do arquivo TMX usando a biblioteca tinyxml2
    tinyxml2::XMLDocument doc;
    doc.LoadFile("../imagens/cenario.tmx");

    if (doc.Error()) {
        std::cerr << "Erro ao carregar o arquivo TMX: " << doc.ErrorStr() << std::endl;
        return;
    }

    // Obtém as texturas do tileset
    tinyxml2::XMLNode * pRootElement = doc.FirstChildElement("map")->FirstChildElement("tileset");
    int count = 1;
    while(pRootElement){
        if(count ==9 || count > 28){
            moedaTexture.loadFromFile(pRootElement->FirstChildElement("image")->Attribute("source"));
            moedaTextures.push_back(moedaTexture);
        }
        count++;
        pRootElement = pRootElement->NextSiblingElement("tileset");
    }
}

int PoderesEspeciais::gerarTipoAleatorio()
{
    // Gera um número entre 0 e 99
    int randomValue = std::rand() % 100;

    // 70% de chance de gerar uma moeda
    if (randomValue < 70) {
        return MOEDA;
    }
    else {
        // 15% de chance de gerar um cogumelo
        if (randomValue < 85) {
            return COGUMELO;
        }
        // 15% de chance de gerar uma estrela
        else {
            return ESTRELA;
        }
    }
}


void PoderesEspeciais::inicializar(float x, float y)
{
    this->posicao = sf::Vector2f(x, y);
    this->posicaoInicial = posicao;

    tipo = gerarTipoAleatorio();

    // Configura o sprite e a textura com base no tipo
    switch (tipo) {
        case COGUMELO:
            poderSprite.setTexture(cogumeloTextures[0]);
            break;
        case ESTRELA:
            poderSprite.setTexture(estrelaTextures[0]);
            break;
        case MOEDA:
            poderSprite.setTexture(moedaTextures[0]); 
            moedaColetada = false; 
            break;
    }
    poderSprite.setPosition(posicao);
}

void PoderesEspeciais::desenhar(sf::RenderWindow& janela) 
{
    if(tipo != MOEDA){
        poderSprite.setPosition(posicao);
        janela.draw(poderSprite);
    }

    else if(tipo == MOEDA && !moedaColetada){
        poderSprite.setPosition(posicao);
        janela.draw(poderSprite);
    }
}


void PoderesEspeciais::ModificacaoPosicaoPoderes(sf::Time deltaTime)
{
    //Verificação de colisão com o chão (gravidade)
    if ( (colisao.verificarColisao(posicao.x, posicao.y+tileSize+1) != 0 && colisao.verificarColisao(posicao.x, posicao.y+tileSize+1) !=9) ||
        (colisao.verificarColisao(posicao.x + tileSize, posicao.y+tileSize+1) != 0 && colisao.verificarColisao(posicao.x + tileSize, posicao.y+tileSize+1))) {

        // Movimento horizontal
        velocidadeVertical=0;
        if (movDireita) {
            posicao.x += velocidadeHorizontal * deltaTime.asSeconds();
        } else if (movEsquerda) {
            posicao.x -= velocidadeHorizontal * deltaTime.asSeconds();
        }    
    } 
    else {
        // Movimento vertical
        velocidadeVertical += aceleracaoGravidade;
        posicao.y += velocidadeVertical * deltaTime.asSeconds();
    }

    //Verificação de colisão com as laterais direita e esquerda
    if ( (movDireita && colisao.verificarColisao(posicao.x + tileSize, posicao.y+tileSize/2) != 0 && colisao.verificarColisao(posicao.x + tileSize, posicao.y+tileSize/2)!=9) ) {

        // Colisão à direita, ajusta posição
        posicao.x -= velocidadeHorizontal * deltaTime.asSeconds();
        movEsquerda = true;
        movDireita = false;
    }
    else if ( movEsquerda && colisao.verificarColisao(posicao.x, posicao.y+tileSize/2) != 0 && colisao.verificarColisao(posicao.x, posicao.y+tileSize/2)!=9)  {
        // Colisão à esquerda, ajusta posição
        posicao.x += velocidadeHorizontal * deltaTime.asSeconds();
        movEsquerda = false;
        movDireita = true;
    }
}

void PoderesEspeciais::ModificacaoPosicaoMoeda(sf::Time deltaTime)
{
    // Se a moeda ainda não foi coletada
    if (!moedaColetada) {
        // Se a moeda ainda não começou a subir
        if (!puloIniciado) {
            // Aplica uma força inicial para cima
            velocidadeVertical = -velocidadeInicialPulo;
            puloIniciado = true;
        }

        // Movimento vertical
        velocidadeVertical += aceleracaoGravidadeMoeda;
        posicao.y += velocidadeVertical * deltaTime.asSeconds();

        // Se atingiu o chão, reinicia a posição e marca que a moeda foi coletada
        if (posicao.y > posicaoInicial.y) {
            posicao.y = posicaoInicial.y;
            puloIniciado = false;
            moedaColetada = true;
        }
    }
}


void PoderesEspeciais::atualizar(sf::Time tempoAtual, sf::Time deltaTime)
{
    int tempo = static_cast<int> (tempoAtual.asSeconds());
    tempo = tempo % 3;

    int tempoMoeda = static_cast<int> (tempoAtual.asMicroseconds());
    tempoMoeda = tempoMoeda % 8;

    //Atualização da textura de acordo com o tempo
    switch (tipo) {
        case COGUMELO:
            if(tempo == 2){
                poderSprite.setTexture(cogumeloTextures[1]);
            }
            else{
                poderSprite.setTexture(cogumeloTextures[tempo]);
            }
                break;
        case ESTRELA:
            poderSprite.setTexture(estrelaTextures[tempo]);
            break;
        case MOEDA:
            poderSprite.setTexture(moedaTextures[tempoMoeda]);
    }

    if(tipo != MOEDA)
        ModificacaoPosicaoPoderes(deltaTime);
    else
        ModificacaoPosicaoMoeda(deltaTime);
}

sf::Vector2f PoderesEspeciais::getPosicaoInicial()
{
    return posicaoInicial;
}
