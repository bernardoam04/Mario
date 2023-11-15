#include "GerenciadorGeral.hpp"

void GerenciadorGeral::inicializarVariaveis()
{
    this->janela = nullptr;
}

void GerenciadorGeral::iniciarJanela()
{
    this->tela.height=640 ;
    this->tela.width=640;
    this->janela = new sf::RenderWindow(this->tela, "Mario!");
}

GerenciadorGeral::GerenciadorGeral() {
    this->inicializarVariaveis();
    this->iniciarJanela();
    this->mapa.carregarMapa("cenario.tmx");
}

GerenciadorGeral::~GerenciadorGeral(){
    delete this->janela;
}

bool GerenciadorGeral::janelaAberta() const
{
    return this->janela->isOpen();
}

void GerenciadorGeral::atualizar()
{
    this->atualizarEventos();
}

void GerenciadorGeral::atualizarEventos()
{
    while (this->janela->pollEvent(this->ev)) {

            if (this->ev.type == sf::Event::Closed){
                    this->janela->close();
                    break;
            }
        }
}

void GerenciadorGeral::renderizar()
{
    this->janela->clear(sf::Color::Black);

    //Desenha o jogo
    this->mapa.renderizar(*this->janela);
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
