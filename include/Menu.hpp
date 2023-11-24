#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <memory>

class Menu{
private:
    std::shared_ptr <sf::RenderWindow> janela;
    sf::Text texto;
    sf::Texture menuTexture; 
    sf::Sprite menuSprite; 
public:
    Menu(std::shared_ptr <sf::RenderWindow> janela1, sf::Font &fonte);
    void desenharTela();
    bool atualizar(sf::Event ev);
    void atualizarPosicaoTextos();
};

#endif