#include "Pontuacao.hpp"
#include <sstream>
#include <iostream>

Pontuacao::Pontuacao(sf::Font &fonte, Camera* camera) 
 :  texto("Teste1", fonte, 15), camera(camera)
{
    texto.setFillColor(sf::Color::White);
    sf::Vector2f cameraPosition = camera->getView().getCenter();
    texto.setPosition(cameraPosition.x - 300, cameraPosition.y - 300);
    contagem =0;
}

Pontuacao::~Pontuacao()
{
    delete this->camera;
}

void Pontuacao::atualizarPontuacao(sf::Time tempoAtual, int contagemMoedas)
{
    std::cout << tempoAtual.asSeconds() << std::endl;

    // Pontuação aumenta a cada loop
    contagem += static_cast<int>(contagemMoedas);

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
    std::cout<< texto.getPosition().x<< " "<< texto.getPosition().y<<std::endl;
    return texto;
}

