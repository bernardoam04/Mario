#include "../include/Menu.hpp"
#include <iostream>

Menu::Menu(std::shared_ptr<sf::RenderWindow> janela1, sf::Font &fonte)
: texto("Iniciar Jogo", fonte, 30)
{
    this->janela = janela1;

    menuTexture.loadFromFile("../imagens/placaMenu.png");

    menuSprite.setTexture(menuTexture);
    menuSprite.setScale(2.5,2.5);
    menuSprite.setPosition( (janela->getSize().x - (menuTexture.getSize().x * menuSprite.getScale().x)) /2.0f, 
    (janela->getSize().y - (menuTexture.getSize().y * menuSprite.getScale().y))/5.0f );

    texto.setFillColor(sf::Color::White);

    // Calcula a posição centralizada do texto
    sf::FloatRect textoRect = texto.getLocalBounds();
    float x = (janela->getSize().x - textoRect.width) / 2.0f;
    float y = (janela->getSize().y - textoRect.height) / 1.7f;

    // Define a posição do texto
    texto.setPosition(x, y);
}

void Menu::desenharTela()
{
    janela->draw(texto);
    janela->draw(menuSprite);
}

bool Menu::atualizar(sf::Event ev)
{
    while (this->janela->pollEvent(ev)) {

            if (ev.type == sf::Event::Closed){
                    janela->close();
                    break;
            }

            else if (ev.type == sf::Event::MouseMoved) {
                // Obtém a posição atual do mouse
                sf::Vector2i mousePosition = sf::Mouse::getPosition(*janela);

                // Define a área desejada onde o evento deve ser acionado
                sf::FloatRect areaDesejada = texto.getGlobalBounds();

                // Verifica se a posição do mouse está dentro da área desejada
                if (areaDesejada.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                    texto.setScale(1.3, 1.3);

                    // Obtém a nova posição centralizada do texto3 após a mudança de escala
                    sf::FloatRect textoRect = texto.getLocalBounds();
                    float x = (janela->getSize().x - (textoRect.width * 1.3f)) / 2.0f;
                    float y = (janela->getSize().y - (textoRect.height * 1.3f)) / 1.7f;

                    // Define a nova posição do texto3
                    texto.setPosition(x, y);
                }
                else {
                    // Mouse está fora da área desejada
                    texto.setScale(1.0, 1.0); // Define a escala de volta para o valor original

                    // Calcula a posição centralizada do texto
                    sf::FloatRect textoRect = texto.getLocalBounds();
                    float x = (janela->getSize().x - textoRect.width) / 2.0f;
                    float y = (janela->getSize().y - textoRect.height) / 1.7f;
                    
                    // Define a nova posição do texto3
                    texto.setPosition(x, y);
                }
            }

            else if (ev.type == sf::Event::MouseButtonPressed) {
                // Verifica se o clique ocorreu dentro da área desejada
                sf::Vector2i mousePosition = sf::Mouse::getPosition(*janela);

                // Define a área desejada onde o evento deve ser acionado
                sf::FloatRect areaDesejada = texto.getGlobalBounds();


                if (areaDesejada.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                    return false;
                }
            }

    }   
    return true;
}

void Menu::atualizarPosicaoTextos()
{
}
