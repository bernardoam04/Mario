#ifndef MAPA_HPP
#define MAPA_HPP

#include <SFML/Graphics.hpp>
#include "../lib/tinyxml2.hpp"
#include "../include/SoundManager.hpp"

#include <sstream>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

class Mapa {
private:

    enum BlocosColisaoEspecial{
        NULO = 0,
        SURPRESA = 2,
        MOEDA = 9,
    };

    std::set<int> colisaoEspecial = {NULO, SURPRESA, MOEDA};

    //Dados utilizados pra desenhar o mapa
    std::unordered_map<int, sf::Texture> texturas;  
    sf::VertexArray vertices;
    std::vector<std::pair<int,bool>> tileData;

    //Som
    std::shared_ptr<SoundManager> _sounds;

    //Constantes
    const int tileSize= 32;
    const int larguraTileset = 280;
    const int alturaTileset = 20;

    //Dados de Verificação
    std::vector<int> colisaoBlocoMoeda;
    std::vector<int> colisaoMoeda;

    //Contagem 
    int contagemMoeda = 0;

public:
   //Construtor 
    Mapa();

    void inicializarColisoes();
    void carregarMapa(const std::string& arquivoMapa);
    void renderizar(sf::RenderWindow& janela, sf::Time tempoAtual);
    void aplicarColisao(std::vector<std::pair<int,int>> posicoes);
    bool getColisaoBlocoMoeda(float x, float y);

    //Getters
    std::vector<std::vector<int>> getDadosMapa();
    int getTileSize();
    int getLarguraTileset();
    int getAlturaTileset();
    int getLarguraMapa();
    int getContagemMoeda();

    //Setters
    void atualizarContagemMoeda(int contagemMoedasMisteriosas);
    void setSound(std::shared_ptr<SoundManager> sounds);
};  
#endif