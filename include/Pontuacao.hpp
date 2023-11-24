#ifndef PONTUACAO_HPP
#define PONTUACAO_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Camera.hpp"
#include <memory>


class Pontuacao {
private:
    int contagem;
    sf::Text texto;
    std::shared_ptr <Camera> camera;
public:
    //Construtor e Destrutor
    Pontuacao(sf::Font &fonte, std::shared_ptr <Camera> camera);
    ~Pontuacao();

    //Atualizações e renderização
    void atualizarPontuacao(sf::Time tempoAtual, float taxa);
    sf::Text exibirPontuacao();

    //Getter
    int getPontuacaoTotal();
};

#endif 
