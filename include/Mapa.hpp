#ifndef MAPA_HPP
#define MAPA_HPP

#include <SFML/Graphics.hpp>
#include "../lib/tinyxml2.hpp"

#include <sstream>
#include <iostream>
#include <vector>
#include <unordered_map>

class Mapa {
private:
    //Dados utilizados pra desenhar o mapa
    std::unordered_map<int, sf::Texture> texturas;  
    sf::VertexArray vertices;
    std::vector<int> tileData;

    //Constantes
    const int tileSize= 32;
    const int larguraTileset = 280;
    const int alturaTileset = 20;

public:
   //Construtor 
    Mapa();

    void carregarMapa(const std::string& arquivoMapa);
    void renderizar(sf::RenderWindow& janela);

    //Getters
    std::vector<std::vector<int>> getDadosMapa();
    int getTileSize();
    int getLarguraTileset();
    int getAlturaTileset();
    int getLarguraMapa();
};

#endif