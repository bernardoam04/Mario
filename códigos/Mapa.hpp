#ifndef MAPA_HPP
#define MAPA_HPP

#include <SFML/Graphics.hpp>
#include "tinyxml2.hpp"

#include <sstream>
#include <iostream>
#include <vector>

class Mapa {
private:
    sf::Texture texturatileset;
    sf::Texture texturatileset2;
    sf::VertexArray vertices;
    std::vector<int> tileData;
public:
    Mapa();
    void carregarMapa(const std::string& arquivoMapa);
    void renderizar(sf::RenderWindow& janela);
};

#endif