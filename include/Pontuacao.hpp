#ifndef PONTUACAO_HPP
#define PONTUACAO_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Camera.hpp"

class Pontuacao {
private:
    int contagem;
    sf::Text texto;
    Camera *camera; 
public:
    Pontuacao(sf::Font &fonte, Camera *camera);
    ~Pontuacao();

    void atualizarPontuacao(sf::Time tempoAtual, int contagemMoedas);
    sf::Text exibirPontuacao();
};

#endif 
