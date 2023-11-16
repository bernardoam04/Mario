#ifndef MAPA_HPP
#define MAPA_HPP

#include <SFML/Graphics.hpp>
#include "tinyxml2.hpp"

#include <sstream>
#include <iostream>
#include <vector>
#include <unordered_map>

class Mapa {
private:
    std::unordered_map<int, sf::Texture> texturas;  
    sf::VertexArray vertices;
    std::vector<int> tileData;
    const int tileSize= 32;
    const int larguraTileset = 280;
public:
    Mapa();
    int getTileSize();
    int getLarguraTileset();
    int getLarguraMapa();
    void carregarMapa(const std::string& arquivoMapa);
    void renderizar(sf::RenderWindow& janela);
};

#endif