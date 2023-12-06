#include "Goomba.hpp"
#include <iostream>

Goomba::Goomba(Colisao &colisao, std::shared_ptr<sf::RenderWindow> janela1, float x, float y) : Personagem(colisao), janela(janela1)
{
    try
    {
        // Verifica se o ponteiro de janela1 é nulo
        if (!janela1)
        {
            throw std::invalid_argument("Janela não inicializada");
        }

        setVivo(true);
        setMovDireita(false);
        setMovEsquerda(true);
        setVelocidadeVertical(0);
        setEstaNoAr(false);
        personagemTexture.loadFromFile("../imagens/TartarugaEsq.png");
        setAlturaPersonagem(personagemTexture.getSize().y);
        setLarguraPersonagem(personagemTexture.getSize().x);
        larguraGoomba = personagemTexture.getSize().x;
        alturaGoomba = personagemTexture.getSize().y;
        setPosicaoPersonagem(sf::Vector2f(x, y));
        janela->draw(personagemSprite);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao inicializar Goomba: " << e.what() << std::endl;
    }
}

void Goomba::atacar(std::shared_ptr <Jogador> mario){
    if(getVivo()){
        mario->perderVida();
    }
}

void Goomba::inicializarGoombas() {

}

bool Goomba::verificarColisaoComGoomba(std::shared_ptr<Jogador> mario)
{
    try
    {
        if (!mario)
        {
            throw std::invalid_argument("Jogador não inicializado");
        }

        if (getVivo() && !mario->estaSubindo())
        {
            sf::Vector2f posicaoPersonagem = mario->getPosicao();
            int larguraPersonagem = mario->getLarguraJogador();
            int alturaPersonagem = mario->getAlturaJogador();
            float xPersonagem = posicaoPersonagem.x;
            float yPersonagem = posicaoPersonagem.y;

            // Coordenadas do retângulo que representa o personagem
            float xPersonagemDireita = xPersonagem + larguraPersonagem / 2;
            float yPersonagemBase = yPersonagem + alturaPersonagem;

            // Coordenadas do retângulo que representa o goomba
            float xGoombaEsquerda = getPosicao().x;
            float xGoombaDireita = getPosicao().x + larguraGoomba;
            float yGoombaTopo = getPosicao().y;
            float yGoombaBase = getPosicao().y + alturaGoomba;

            // Verificar colisão
            bool colisaoHorizontal = xPersonagemDireita >= xGoombaEsquerda && xPersonagemDireita <= xGoombaDireita;
            bool colisaoVertical = yPersonagemBase >= yGoombaTopo && yPersonagemBase <= yGoombaBase;

            return colisaoHorizontal && colisaoVertical;
        }
        return false;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro em verificarColisaoComGoomba: " << e.what() << std::endl;
        return false;
    }
}

bool Goomba::verificarColisaoLateralComGoomba(std::shared_ptr<Jogador> mario)
{
    try
    {
        if (!mario)
        {
            throw std::invalid_argument("Jogador não inicializado");
        }

        bool colisaoDireita = verificarColisaoLateralComGoombaDireita(mario);
        bool colisaoEsquerda = verificarColisaoLateralComGoombaEsquerda(mario);

        return colisaoDireita || colisaoEsquerda;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro em verificarColisaoLateralComGoomba: " << e.what() << std::endl;
        return false;
    }
}

bool Goomba::verificarColisaoLateralComGoombaDireita(std::shared_ptr<Jogador> mario)
{
    try
    {
        if (!mario)
        {
            throw std::invalid_argument("Jogador não inicializado");
        }

        if (getVivo())
        {
            sf::Vector2f posicaoPersonagem = mario->getPosicao();
            int larguraPersonagem = mario->getLarguraJogador();
            int alturaPersonagem = mario->getAlturaJogador();
            float xPersonagem = posicaoPersonagem.x;
            float yPersonagem = posicaoPersonagem.y;

            // Coordenadas que representam o personagem
            float xPersonagemDireita = xPersonagem + larguraPersonagem;
            float yPersonagemBase = yPersonagem + alturaPersonagem - getTileSize() / 2;

            // Coordenadas do retângulo que representa o goomba
            float xGoombaEsquerda = getPosicao().x;
            float xGoombaDireita = getPosicao().x + larguraGoomba;
            float yGoombaTopo = getPosicao().y;
            float yGoombaBase = getPosicao().y + alturaGoomba;

            // Verificar colisão
            bool colisaoHorizontal = xPersonagemDireita >= xGoombaEsquerda && xPersonagemDireita <= xGoombaDireita;
            bool colisaoVertical = yPersonagemBase >= yGoombaTopo && yPersonagemBase <= yGoombaBase;

            return colisaoHorizontal && colisaoVertical;
        }
        return false;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro em verificarColisaoLateralComGoombaDireita: " << e.what() << std::endl;
        return false;
    }
}

bool Goomba::verificarColisaoLateralComGoombaEsquerda(std::shared_ptr<Jogador> mario)
{
    try
    {
        if (!mario)
        {
            throw std::invalid_argument("Jogador não inicializado");
        }

        if (getVivo())
        {
            sf::Vector2f posicaoPersonagem = mario->getPosicao();
            int alturaPersonagem = mario->getAlturaJogador();
            float xPersonagem = posicaoPersonagem.x;
            float yPersonagem = posicaoPersonagem.y;

            // Coordenadas que representam o personagem
            float xPersonagemDireita = xPersonagem;
            float yPersonagemBase = yPersonagem + alturaPersonagem - getTileSize() / 2;

            // Coordenadas do retângulo que representa o goomba
            float xGoombaDireita = getPosicao().x + larguraGoomba;
            float xGoombaEsquerda = getPosicao().x + larguraGoomba - larguraGoomba;
            float yGoombaTopo = getPosicao().y;
            float yGoombaBase = getPosicao().y + alturaGoomba;

            // Verificar colisão
            bool colisaoHorizontal = xPersonagemDireita >= xGoombaEsquerda && xPersonagemDireita <= xGoombaDireita;
            bool colisaoVertical = yPersonagemBase >= yGoombaTopo && yPersonagemBase <= yGoombaBase;

            return colisaoHorizontal && colisaoVertical;
        }
        return false;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro em verificarColisaoLateralComGoombaEsquerda: " << e.what() << std::endl;
        return false;
    }
}


bool Goomba::verificarColisaoDistanciaX(float x, float y, float largura){

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

bool Goomba::verificarColisaoDistanciaY(float x, float y, float altura)
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

void Goomba::modificarPosicao(sf::Time deltaTime, int larguraMapa) {

    sf::Vector2f posicaoAtual = getPosicao();
    setVelocidadeHorizontal(30.0f);
    float velocidadeHorizontalAtual = getVelocidadeHorizontal();

    // Configurar para quando bater em alguma coisa rebater
    if (getMovEsquerda()) {
       posicaoAtual.x -= velocidadeHorizontalAtual * deltaTime.asSeconds();
    }

    // Inverter a direção da direita pra esquerda se houver colisão
    if (verificarColisaoDistanciaY(posicaoAtual.x + larguraGoomba , posicaoAtual.y, alturaGoomba -3) && getMovDireita()) {
        setMovDireita(false);
        setMovEsquerda(true);
    }

    // Inverter a direção da esquerda pra direita se houver colisão
    if (verificarColisaoDistanciaY(posicaoAtual.x , posicaoAtual.y, alturaGoomba -3) && getMovEsquerda()) {
        setMovEsquerda(false);
        setMovDireita(true);
    }

    // Limitar a posição dentro dos limites do mapa
    if (posicaoAtual.x + larguraGoomba <= 0) {
        setMovDireita(true);
    } else if (posicaoAtual.x + 35 >= larguraMapa) {
        setMovDireita(false);
    }

    if (!verificarColisaoDistanciaX(posicaoAtual.x , posicaoAtual.y + alturaGoomba, larguraGoomba -3)) {
        setEstaNoAr(true);
        setVelocidadeVertical(getVelocidadeVertical()+ getAceleracaoGravidade());
        posicaoAtual.y += getVelocidadeVertical() * deltaTime.asSeconds();
    }
    else{
        setEstaNoAr(false);
        setVelocidadeVertical(0);
    }

    // Mover para a direita se a direção for positiva
    if (getMovDireita()) {
        posicaoAtual.x += velocidadeHorizontalAtual * deltaTime.asSeconds();
    }

    //Morre se cair do mapa
    if(posicaoAtual.y > 640){
        morrer();
    }

    setPosicaoPersonagem(posicaoAtual);
}

void Goomba::morrer() {
    temporizadorMorte.restart();
    setVivo(false);
}

void Goomba::desenharGoomba(float x) {

    float larguraTela = janela->getSize().x;

    // Calcula os índices de início e fim da tela visível
    int xInicioTela = static_cast<int>((x - larguraTela / 2));
    int xFimTela = static_cast<int>((x + larguraTela / 2));    
    
    //Desenha o Goomba apenas se ele estigver dentro da tela visível
    if(getPosicao().x + larguraGoomba > xInicioTela && getPosicao().x < xFimTela){
        if(getVivo()){
            sf::Sprite sprite(personagemTexture); 
            sprite.setPosition(getPosicao());
            sprite.setTexture(personagemTexture);
            janela->draw(sprite);
        }
        else if(temporizadorMorte.getElapsedTime().asSeconds() < 0.3){
            personagemTexture.loadFromFile("../imagens/goombaMorto.png");
            sf::Sprite sprite(personagemTexture); 
            sprite.setPosition(getPosicao());
            sprite.setTexture(personagemTexture);
            janela->draw(sprite);
        }
    } 
}

Goomba::~Goomba(){

}
