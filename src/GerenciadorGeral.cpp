#include "../include/GerenciadorGeral.hpp"
#include "GerenciadorGeral.hpp"

GerenciadorGeral::GerenciadorGeral(std::shared_ptr <sf::RenderWindow> janela1, sf::Font &fonte, std::shared_ptr<SoundManager> sounds) : pontuacao(nullptr),  
camera(nullptr), colisao(nullptr), _sounds(nullptr), mario(nullptr), goomba(nullptr), puloHabilitado(true)
{
    //Inicialização de atributos
    this-> _sounds = sounds;
    this->janela = janela1;
    this->mapa.setSound(this->_sounds);
    this->mapa.carregarMapa("../imagens/cenario.tmx");
    this->mapa.inicializarColisoes();
    gameOver = false;
    //Inicialização dos smart pointers
    colisao = std::make_shared<Colisao>(mapa.getDadosMapa(), mapa.getTileSize());
    mario = std::make_shared<Jogador>(*colisao, larguraTela, alturaTela, janela);
    camera = std::make_shared<Camera>(larguraTela, alturaTela);
    pontuacao = std::make_shared<Pontuacao>(fonte, camera);

    if(somAtivo){
        this->_sounds->reiniciarMusica();
    }

    //Métodos de inicialização
    inicializarTextos(fonte);
    InicializarPoderesEspeciais();
    InicializarGoombas();
}
void GerenciadorGeral::InicializarPoderesEspeciais(){
    int tileSize = mapa.getTileSize();
    auto dadosMapa = mapa.getDadosMapa();
    for (unsigned int i = 0; i < dadosMapa.size(); ++i) {
        for (unsigned int j = 0; j < dadosMapa[i].size(); ++j) {
            // Verifica se o bloco é do tipo desejado (nesse caso, tipo 2)
            if (dadosMapa[i][j] == 2) {
                // Calcula a posição do bloco acima
                float x = j * tileSize;
                float y = (i - 1) * tileSize;
                // Inicializa um novo PoderEspecial na posição acima do bloco
                std::shared_ptr<PoderesEspeciais> poderesEspeciais = std::make_shared<PoderesEspeciais>(*colisao);
                poderesEspeciais->inicializar(x, y);
                vetorPoderesEspeciais.push_back(poderesEspeciais);
                contagemDesenhoPoderes.push_back(0);
            }
        }
    }
}

void GerenciadorGeral::InicializarGoombas()
{
    goomba = std::make_shared<Goomba>(*colisao, janela, 1000, 544);
    goombas.push_back(goomba);

    goomba = std::make_shared<Goomba>(*colisao, janela, 1400, 544);
    goombas.push_back(goomba);

    goomba = std::make_shared<Goomba>(*colisao, janela, 3456, 544);
    goombas.push_back(goomba);

    goomba = std::make_shared<Goomba>(*colisao, janela, 3490, 544);
    goombas.push_back(goomba);

    goomba = std::make_shared<Goomba>(*colisao, janela, 3510, 544);
    goombas.push_back(goomba);

    goomba = std::make_shared<Goomba>(*colisao, janela, 6144, 544);
    goombas.push_back(goomba);

    goomba = std::make_shared<Goomba>(*colisao, janela, 6170, 544);
    goombas.push_back(goomba);
}

void GerenciadorGeral::inicializarTextos(sf::Font &fonte)
{
    sf::Vector2f posicaoInicialTextos;
    posicaoInicialTextos.x = -1000;
    posicaoInicialTextos.y = -1000;

    textoMaisCem.setFont(fonte);
    textoMaisCem.setString("100");
    textoMaisCem.setCharacterSize(15);
    textoMaisCem.setFillColor(sf::Color::White);
    textoMaisCem.setPosition(posicaoInicialTextos);

    textoMaisMil.setFont(fonte);
    textoMaisMil.setString("1000");
    textoMaisMil.setCharacterSize(15);
    textoMaisMil.setFillColor(sf::Color::White);
    textoMaisMil.setPosition(posicaoInicialTextos);

    textoGanhou.setFont(fonte);
    textoGanhou.setString("YOU WIN!");
    textoGanhou.setCharacterSize(30);
    textoGanhou.setFillColor(sf::Color::White);
}


void GerenciadorGeral::atualizarPosicaoTexto(sf::Text &texto)
{
    // Calcula a posição centralizada do texto de acordo com a posição do jogador
    sf::FloatRect textRect = texto.getLocalBounds();
    float centerX = mario->getPosicao().x- textRect.width/2;
    float centerY = (alturaTela- textRect.height) / 2;
    texto.setPosition(centerX, centerY);
}

bool GerenciadorGeral::atualizar(sf::Time tempoAtual, sf::Time deltaTime, sf::Event ev)
{
    if(!somAtivo){
        this->_sounds->pausarMusica();
    }
    if (temporizadorTexto.getElapsedTime() > duracaoTexto){
        textoMaisCem.setPosition(-1000, -1000);  // Define a posição fora da tela
        textoMaisMil.setPosition(-1000, -1000);
    }

    for (unsigned int i = 0; i < vetorPoderesEspeciais.size(); i++) {
        vetorPoderesEspeciais[i]->atualizar(tempoAtual, deltaTime);
    }

    bool jogoAtivo = this->atualizarEventos(ev);

    mario->modificarPosicao(deltaTime, mapa.getLarguraMapa());

    for (unsigned int i = 0; i < goombas.size(); i++) {
        goombas[i]->modificarPosicao(deltaTime, mapa.getLarguraMapa());
    }

    if (jogoAtivo == false)
    {
        return false;
    }
    pontuacao->atualizarPontuacao(mapa.getContagemMoeda(), mapa.getContagemPoderEspecial());
    return true;
}

bool GerenciadorGeral::atualizarEventos(sf::Event ev)
{
    while (this->janela->pollEvent(ev)) {
            if (ev.type == sf::Event::Closed){
                _sounds->pausarMusica();
                return false;
            }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { 
        mario->setMovendoDireita(true);
        mario->setMovendoEsquerda(false);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        mario->setMovendoDireita(false);
        mario->setMovendoEsquerda(true);
    }
    else{
        mario->setMovendoDireita(false);
        mario->setMovendoEsquerda(false);
    }

    camera->atualizarPosicao(mario->getPosicao());

    // Verifica o pulo
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && puloHabilitado) {
        mario->setPulando(true);
        puloHabilitado = false;

        //Verificacao para o som sair somente quando mario sai do chao
       if(!mario->getEstaNoAr()){
            _sounds->somPulo();
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !puloHabilitado) {
        mario->setPulando(false);
    }
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        // Habilita o pulo quando a tecla é liberada
        puloHabilitado = true;
        mario->setPulando(false);
    }
    return true;
}

void GerenciadorGeral::renderizar(sf::Time tempoAtual)
{
    contadorInvencivel = tempoAtual.asMilliseconds();
    //Atualizações caso o mario tenha morrido
    if(mario->getPerdeu()){
        _sounds->pausarMusica();
        if(contadorPerdeu == 0){
            _sounds->somGameOver();
        }
        else{
            sf::sleep(sf::seconds(2.0));
        }
        mario->desenhar();
    contadorPerdeu++;
    gameOver = true;
    }
    mario->atualizarColisao(mapa);
    
    //Ajusta a visão da câmera
    janela->setView(this->camera->getView());
    
    //Desenha o mapa
    this->mapa.renderizar(*this->janela, tempoAtual);

    janela->draw(pontuacao->exibirPontuacao());

    //Desenha as goombas
    for (unsigned int i = 0; i < goombas.size(); i++) {
        goombas[i]->desenharGoomba();
        if(goombas[i]->verificarColisaoComGoomba(mario)){
            goombas[i]->morrer();
            mario->setPuloEmGoomba(true);
        }
        if(goombas[i]->verificarColisaoLateralComGoomba(mario)){
            goombas[i]->atacar(mario);
            mario->ficarInvencivel();
        }
    }

    int contagemMoedasMisteriosas = 0;

    //Desenha os Poderes Especiais
    for (unsigned int i = 0; i < vetorPoderesEspeciais.size(); i++) {

        int tileSize = mapa.getTileSize();
        int x= vetorPoderesEspeciais[i]->getPosicaoInicial().x;
        int y= vetorPoderesEspeciais[i]->getPosicaoInicial().y + tileSize;

        if(mapa.getColisaoBlocoMoeda(x,y) == true){
            if(vetorPoderesEspeciais[i]->getTipo() ==3){
                contagemMoedasMisteriosas++;
            }
            if(contagemDesenhoPoderes[i] ==0){
                vetorPoderesEspeciais[i]->inicializar(vetorPoderesEspeciais[i]->getPosicaoInicial().x, vetorPoderesEspeciais[i]->getPosicaoInicial().y);
                if(vetorPoderesEspeciais[i]->getTipo() ==3){
                    _sounds->somMoeda();
                    //Desenha "+100" na tela logo em cima da posição do mario
                    textoMaisCem.setPosition(mario->getPosicao().x, mario->getPosicao().y - mario->getAlturaJogador());
                    temporizadorTexto.restart();  // Inicia o temporizador do texto
                }
            }
            sf::Vector2f posicaoAtualMario = mario->getPosicao();
            
            if(vetorPoderesEspeciais[i]->verificarColisao(posicaoAtualMario, mario->getAlturaJogador(), mario->getLarguraJogador())){
                unsigned int tamanhoInicial = indicesComColisao.size();
                indicesComColisao.insert(i);
                if(vetorPoderesEspeciais[i]->getTipo()!=3){
                    indicesPoderesEspeciais.insert(i);
                }
                unsigned int tamanhoFinal = indicesComColisao.size();

                if(tamanhoFinal> tamanhoInicial && vetorPoderesEspeciais[i]->getTipo()!=3){ //Verifica se foi um poder especial novo e se não era moeda, que já foi tratado o texto dela
                    //Dobra altura do jogador se pegou cogumelo
                    if(vetorPoderesEspeciais[i]->getTipo() == 1){
                        mario->dobrarAltura();
                        mario->setEstaGrande(true);
                    }
                    //Deixa jogador invencivel se pegou estrela
                    else if(vetorPoderesEspeciais[i]->getTipo() == 2){
                        mario->pegarEstrela();
                    }
                    //Desenha "+1000" na tela logo em cima da posição do mario
                    textoMaisMil.setPosition(mario->getPosicao().x, mario->getPosicao().y - mario->getAlturaJogador());
                    temporizadorTexto.restart();  // Inicia o temporizador do texto
                }
            }
            bool desenho = indicesComColisao.find(i) == indicesComColisao.end();
            
            if(desenho){
                vetorPoderesEspeciais[i]->desenhar(*this->janela);
                contagemDesenhoPoderes[i]++;
            }
        }
    }    
    mapa.atualizarContagemMoeda(contagemMoedasMisteriosas);
    int contagemPoderesEspeciais = indicesPoderesEspeciais.size();

    mapa.atualizarContagemPoderes(contagemPoderesEspeciais);

    //Desenhar o mario apenas se ele ainda não ganhou
    if(!mario->getGanhou()){
        if(mario->estaInvencivel()){
            if(contadorInvencivel % 2 == 0){
                mario->desenhar();
            }
        }
        else{
            mario->desenhar();
        }
    } 
    //Desenha texto de vitória caso tenha ganhado
    else{
        atualizarPosicaoTexto(textoGanhou);
        janela->draw(textoGanhou);    
    }

    janela->draw(textoMaisCem);
    janela->draw(textoMaisMil);

    //Mostra a tela
    this->janela->display();
}
int GerenciadorGeral::getPontuacaoTotal() const
{
    return pontuacao->getPontuacaoTotal();
}

const sf::View& GerenciadorGeral::getViewCamera() const {
    return this->camera->getView();
}

bool GerenciadorGeral::getGamerOver()
{
    return gameOver;
}

void GerenciadorGeral::desenharMapa(sf::Time tempoAtual){
    this->mapa.renderizar(*this->janela, tempoAtual);
}

void GerenciadorGeral::desativarSom()
{
    somAtivo = false;
    _sounds->pausarMusica();
    _sounds->desativarSom();
}