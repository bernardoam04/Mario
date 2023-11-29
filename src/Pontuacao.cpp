#include "../include/Pontuacao.hpp"
#include <sstream>
#include <iostream>

Pontuacao::Pontuacao(sf::Font &fonte, std::shared_ptr <Camera> camera) 
 :  texto("Teste1", fonte, 15), camera(camera)
{
    texto.setFillColor(sf::Color::White);
    sf::Vector2f cameraPosition = camera->getView().getCenter();
    texto.setPosition(cameraPosition.x - 300, cameraPosition.y - 300);
    contagem =0;
}

Pontuacao::~Pontuacao()
{
}

void Pontuacao::atualizarPontuacao(int contagemMoedas, int contagemPoderesEspeciais)
{
    int taxaMoeda = 100;
    int taxaPoder = 1000;

    // Pontuação aumenta a cada loop
    contagem = contagemMoedas * taxaMoeda +  contagemPoderesEspeciais * taxaPoder;

    // Converter int para string
    std::ostringstream converter;
    converter << "Score " << contagem;

    // Obtém a posição da câmera e ajusta a posição da pontuação
    texto.setString(converter.str());
}


sf::Text Pontuacao::exibirPontuacao()
{
    sf::Vector2f cameraPosition = camera->getView().getCenter();
    texto.setPosition(cameraPosition.x -300 , cameraPosition.y-300);
    return texto;
}

int Pontuacao::getPontuacaoTotal(){
    return contagem;
}


