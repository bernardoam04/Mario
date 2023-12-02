#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <memory>

class GameOver{
private:
    std::shared_ptr <sf::RenderWindow> janela;
    sf::Text texto, texto2,texto3;
public:

    //Construtor
    GameOver(std::shared_ptr <sf::RenderWindow> janela1, sf::Font &fonte);

    //Métodos diretamente usados
    void desenharTela(int pontuacaoTotal, const sf::View& view);
    bool atualizar(sf::Event ev, const sf::View &view);
    void atualizarPosicaoTextos(const sf::View& view);
};

#endif