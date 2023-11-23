#include "../include/GerenciadorGeral.hpp"


GerenciadorGeral::GerenciadorGeral(std::shared_ptr <sf::RenderWindow> janela1) : camera(larguraTela, alturaTela) , colisao(nullptr)
{
    this->janela = janela1;
    this->mapa.carregarMapa("../imagens/cenario.tmx");
    this->mapa.inicializarColisoes();
    colisao = std::make_shared<Colisao>(mapa.getDadosMapa(), mapa.getTileSize());
    InicializarPoderesEspeciais();
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
            }
        }
    }
}


GerenciadorGeral::~GerenciadorGeral()
{
}

void GerenciadorGeral::atualizar(sf::Time tempoAtual, sf::Time deltaTime, sf::Event ev)
{
    for (auto& poder : vetorPoderesEspeciais) {
        poder->atualizar(tempoAtual, deltaTime);
    }
    this->atualizarEventos(ev);
}

void GerenciadorGeral::atualizarEventos(sf::Event ev)
{
    while (this->janela->pollEvent(ev)) {

            if (ev.type == sf::Event::Closed){
                    janela->close();
                    break;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                // Move a câmera para a direita com uma velocidade fixa 
                camera.movimentarCameraDireita(mapa.getLarguraMapa(), larguraTela);
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                // Move a câmera para a esquerda com uma velocidade fixa 
                camera.movimentarCameraEsquerda(larguraTela);
            }
        }
}

void GerenciadorGeral::renderizar(sf::Time tempoAtual)
{
    //Ajusta a visão da câmera
    janela->setView(this->camera.getView());
    
    //Desenha o mapa
    this->mapa.renderizar(*this->janela, tempoAtual);

    //Desenha os Poderes Especiais
    for (auto& poder : vetorPoderesEspeciais) {
        poder->desenhar(*this->janela);
    }    

    //Mostra a tela
    this->janela->display();
}