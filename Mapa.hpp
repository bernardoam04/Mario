#ifndef MAPA_HPP
#define MAPA_HPP

#include <SFML/Graphics.hpp>
#include "tinyxml2.hpp"

#include <sstream>
#include <iostream>

class Mapa {
private:
    sf::Texture texturaTileset;
    sf::VertexArray vertices;

public:
    Mapa();
    void carregarMapa(const std::string& arquivoMapa);
    void renderizar(sf::RenderWindow& janela);
};

#endif
