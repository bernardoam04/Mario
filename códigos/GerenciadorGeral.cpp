#include "GerenciadorGeral.hpp"

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

GerenciadorGeral::GerenciadorGeral() : camera(largura_tela, altura_tela) 
{
    this->inicializarVariaveis();
    this->iniciarJanela();
    this->mapa.carregarMapa("cenario.tmx");
}

GerenciadorGeral::~GerenciadorGeral()
{
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

void GerenciadorGeral::renderizar( PoderesEspeciais poderesEspeciais)
{
    //Limpa a tela
    this->janela->clear(sf::Color::Blue);

    //Ajusta a visão da câmera
    this->janela->setView(this->camera.getView());
    
    //Desenha o mapa
    this->mapa.renderizar(*this->janela);
    poderesEspeciais.desenhar(*this->janela);
    
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
