#include "GameOver.hpp"
#include <sstream>
#include <iostream>

GameOver::GameOver(std::shared_ptr<sf::RenderWindow> janela1, sf::Font &fonte)
    : texto("GAME OVER", fonte, 50), texto2("SCORE\n", fonte, 30), texto3("Reiniciar Jogo", fonte, 30)
{
    this->janela = janela1;
    texto.setFillColor(sf::Color::White);

    // Calcula a posição centralizada do texto
    sf::FloatRect textoRect = texto.getLocalBounds();
    float x = (janela->getSize().x - textoRect.width) / 2.0f;
    float y = (janela->getSize().y - textoRect.height) / 4.0f;

    // Define a posição do texto
    texto.setPosition(x, y);

    texto2.setFillColor(sf::Color::White);


    // Calcula a posição centralizada do texto
    sf::FloatRect textoRect2 = texto2.getLocalBounds();
    float x2 = (janela->getSize().x - textoRect2.width) / 2.0f;
    float y2 = (((janela->getSize().y - textoRect2.height) / 4.0f) + textoRect2.height * 5.0f);

    texto2.setPosition(x2, y2);

    texto3.setFillColor(sf::Color::White);

   // Calcula a posição centralizada do texto
    sf::FloatRect textoRect3 = texto3.getLocalBounds();
    float x3 = (janela->getSize().x - textoRect3.width) / 2.0f;
    float y3 = (((janela->getSize().y - textoRect3.height) / 2.0f) + textoRect3.height * 5.0f);

    texto3.setPosition(x3, y3);

}

void GameOver::desenharTela(int pontuacaoTotal, const sf::View& view)
{
    janela->draw(texto);

    // Converter int para string
    std::ostringstream converter;
    converter << "SCORE " << pontuacaoTotal;

    // Obtém a posição da câmera e ajusta a posição da pontuação
    texto2.setString(converter.str());

    // Calcula a posição centralizada do texto2
    sf::FloatRect textoRect2 = texto2.getLocalBounds();
    float x2 = view.getCenter().x - view.getSize().x / 2.0f + (view.getSize().x - textoRect2.width) / 2.0f;
    float y2 = (((janela->getSize().y - textoRect2.height) / 4.0f) + textoRect2.height * 5.0f);

    texto2.setPosition(x2, y2);

    janela->draw(texto2);

    janela->draw(texto3);
}

void GameOver::atualizarPosicaoTextos(const sf::View& view)
{
    // Calcula a posição centralizada do texto
    sf::FloatRect textoRect = texto.getLocalBounds();
    float x = view.getCenter().x - view.getSize().x / 2.0f + (view.getSize().x - textoRect.width) / 2.0f;
    float y = (view.getSize().y - textoRect.height) / 4.0f;

    // Define a posição do texto
    texto.setPosition(x, y);

    // Calcula a posição centralizada do texto2
    sf::FloatRect textoRect2 = texto2.getLocalBounds();
    float x2 = view.getCenter().x - view.getSize().x / 2.0f + (view.getSize().x - textoRect2.width) / 2.0f;
    float y2 = (((janela->getSize().y - textoRect2.height) / 4.0f) + textoRect2.height * 5.0f);

    texto2.setPosition(x2, y2);

    // Calcula a posição centralizada do texto3
    sf::FloatRect textoRect3 = texto3.getLocalBounds();
    float x3 = view.getCenter().x - view.getSize().x / 2.0f + (view.getSize().x - textoRect3.width) / 2.0f;
    float y3 = (((janela->getSize().y - textoRect3.height) / 2.0f) + textoRect3.height * 5.0f);

    texto3.setPosition(x3, y3);
}

bool GameOver::atualizar(sf::Event ev, const sf::View &view)
{
    // Atualiza a posição dos textos de acordo com a view da câmera
    atualizarPosicaoTextos(view);
    
    while (this->janela->pollEvent(ev)) {

            if (ev.type == sf::Event::Closed){
                    janela->close();
                    break;
            }
            else if (ev.type == sf::Event::MouseMoved) {
                // Obtém a posição atual do mouse
                sf::Vector2i mousePosition = sf::Mouse::getPosition(*janela);

                // Define a área desejada onde o evento deve ser acionado
                sf::FloatRect areaDesejada = texto3.getGlobalBounds();

                // Verifica se a posição do mouse está dentro da área desejada
                if (areaDesejada.contains(static_cast<float>(mousePosition.x + (view.getCenter().x-(janela->getSize().x/2))), static_cast<float>(mousePosition.y))) {
                    texto3.setScale(1.3, 1.3);

                    // Obtém a nova posição centralizada do texto3 após a mudança de escala
                    sf::FloatRect textoRect3 = texto3.getLocalBounds();
                    float x3 = (view.getCenter().x - view.getSize().x / 2.0f + (view.getSize().x - textoRect3.width*1.3) / 2.0f) - textoRect3.width * 1.3f;
                    float y3 = (((janela->getSize().y - textoRect3.height * 1.3) / 2.0f) + textoRect3.height * 5.0f);

                    // Define a nova posição do texto3
                    texto3.setPosition(x3, y3);
                }
                else {
                    // Mouse está fora da área desejada
                    texto3.setScale(1.0, 1.0); // Define a escala de volta para o valor original

                    // Obtém a nova posição centralizada do texto3 após a mudança de escala
                    sf::FloatRect textoRect3 = texto3.getLocalBounds();
                    float x3 = (view.getCenter().x - view.getSize().x / 2.0f + (view.getSize().x - textoRect3.width * 1.3) / 2.0f) ;
                    float y3 = (((janela->getSize().y - textoRect3.height * 1.3) / 2.0f) + textoRect3.height * 5.0f);
                    
                    // Define a nova posição do texto3
                    texto3.setPosition(x3, y3);
                }
        }
        else if (ev.type == sf::Event::MouseButtonPressed) {
            // Verifica se o clique ocorreu dentro da área desejada
            sf::Vector2i mousePosition = sf::Mouse::getPosition(*janela);

            // Define a área desejada onde o evento deve ser acionado
            sf::FloatRect areaDesejada = texto3.getGlobalBounds();

            if (areaDesejada.contains(static_cast<float>(mousePosition.x + (view.getCenter().x-(janela->getSize().x/2))), static_cast<float>(mousePosition.y))) {
                return false;
            }
        }

        }

    return true;
}

