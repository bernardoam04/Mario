#include "../include/GerenciadorGeral.hpp"

void GerenciadorGeral::inicializarVariaveis()
{
    this->janela = nullptr;
}

void GerenciadorGeral::iniciarJanela()
{
    this->tela.height=altura_tela ;
    this->tela.width=largura_tela;
    this->janela = new sf::RenderWindow(this->tela, "Mario!");
}

GerenciadorGeral::GerenciadorGeral() : camera(largura_tela, altura_tela) , colisao(nullptr)
{
    this->inicializarVariaveis();
    this->iniciarJanela();
    this->mapa.carregarMapa("../imagens/cenario.tmx");
    colisao = new Colisao (mapa.getDadosMapa(), mapa.getTileSize());
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
                PoderesEspeciais *poderesEspeciais = new PoderesEspeciais(*colisao);
                poderesEspeciais->inicializar(x, y);
                vetorPoderesEspeciais.push_back(poderesEspeciais);
            }
        }
    }
}


GerenciadorGeral::~GerenciadorGeral()
{
    delete this->janela;
    delete this->colisao;

    // Libera memória dos PoderesEspeciais no vetor
    for (auto& poder : vetorPoderesEspeciais) {
        delete poder;
    }
}


bool GerenciadorGeral::janelaAberta() const
{
    return this->janela->isOpen();
}

void GerenciadorGeral::atualizar(sf::Time tempoAtual, sf::Time deltaTime)
{
    for (auto& poder : vetorPoderesEspeciais) {
        poder->atualizar(tempoAtual, deltaTime);
    }

    this->atualizarEventos();

}

void GerenciadorGeral::atualizarEventos()
{
    while (this->janela->pollEvent(this->ev)) {

            if (this->ev.type == sf::Event::Closed){
                    this->janela->close();
                    break;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                // Move a câmera para a direita com uma velocidade fixa 
                camera.movimentarCameraDireita(mapa.getLarguraMapa(), largura_tela);
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                // Move a câmera para a esquerda com uma velocidade fixa 
                camera.movimentarCameraEsquerda(largura_tela);
            }
        }
}

void GerenciadorGeral::renderizar(sf::Time tempoAtual)
{
    //Limpa a tela
    this->janela->clear(sf::Color::Blue);

    //Ajusta a visão da câmera
    this->janela->setView(this->camera.getView());
    
    //Desenha o mapa
    this->mapa.renderizar(*this->janela, tempoAtual);

    //Desenha os Poderes Especiais
    for (auto& poder : vetorPoderesEspeciais) {
        poder->desenhar(*this->janela);
    }    

    //Mostra a tela
    this->janela->display();
}

float GerenciadorGeral::getAlturaTela() const
{
    return this->tela.height;
}

float GerenciadorGeral::getLarguraTela() const
{
    return this->tela.width;
}
