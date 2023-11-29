#include "../include/GerenciadorGeral.hpp"

GerenciadorGeral::GerenciadorGeral(std::shared_ptr <sf::RenderWindow> janela1, sf::Font &fonte, std::shared_ptr<SoundManager> sounds) : pontuacao(nullptr),  
camera(nullptr), colisao(nullptr), _sounds(sounds), mario(nullptr), puloHabilitado(true)
{
    this->janela = janela1;
    this->mapa.setSound(this->_sounds);
    this->mapa.carregarMapa("../imagens/cenario.tmx");
    this->_sounds->reiniciarMusica();
    this->mapa.inicializarColisoes();
    colisao = std::make_shared<Colisao>(mapa.getDadosMapa(), mapa.getTileSize());
    mario = std::make_shared<Jogador>(*colisao, larguraTela);
    InicializarPoderesEspeciais();
    camera = std::make_shared<Camera>(larguraTela, alturaTela);
    pontuacao = std::make_shared<Pontuacao>(fonte, camera);
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

GerenciadorGeral::~GerenciadorGeral()
{
}

bool GerenciadorGeral::atualizar(sf::Time tempoAtual, sf::Time deltaTime, sf::Event ev)
{
    for (unsigned int i = 0; i < vetorPoderesEspeciais.size(); i++) {
        vetorPoderesEspeciais[i]->atualizar(tempoAtual, deltaTime);
    }
    bool jogoAtivo = this->atualizarEventos(ev);

    mario->modificarPosicao(deltaTime, mapa.getLarguraMapa());

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
    mario->atualizarColisao(mapa);

    //Ajusta a visão da câmera
    janela->setView(this->camera->getView());
    
    //Desenha o mapa
    this->mapa.renderizar(*this->janela, tempoAtual);

    janela->draw(pontuacao->exibirPontuacao());

    desenharJogador(mario->getPosicao()); 

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
                }
            }
            sf::Vector2f posicaoAtualMario = mario->getPosicao();

            if(vetorPoderesEspeciais[i]->verificarColisao(posicaoAtualMario, mario->getAlturaJogador(), mario->getLarguraJogador())){
                indicesComColisao.insert(i);
            }
            bool desenho = indicesComColisao.find(i) == indicesComColisao.end();
            
            if(desenho){
                vetorPoderesEspeciais[i]->desenhar(*this->janela);
                contagemDesenhoPoderes[i]++;
            }
        }
    }    
    mapa.atualizarContagemMoeda(contagemMoedasMisteriosas);
    int contagemPoderesEspeciais = indicesComColisao.size();

    mapa.atualizarContagemPoderes(contagemPoderesEspeciais);

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

void GerenciadorGeral::desenharMapa(sf::Time tempoAtual){
    this->mapa.renderizar(*this->janela, tempoAtual);
}

void GerenciadorGeral::desenharJogador(sf::Vector2f posicao) {//TRANSFERIR ESSA FUNCAO PRA CLASSE PERSONAGEM DEPOIS
    sf::Sprite sprite(mario->getTexture());  // Tamanho do sprite
    sprite.setPosition(posicao);
    janela->draw(sprite);
}
