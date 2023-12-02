#ifndef PONTUACAO_HPP
#define PONTUACAO_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "../include/Camera.hpp"
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
    void atualizarPontuacao(int contagemMoeda, int contagemPoderesEspeciais);
    sf::Text exibirPontuacao();

    //Getters
    int getPontuacaoTotal();
};

#endif 
