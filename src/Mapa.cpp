#include "../include/Mapa.hpp"
#include "Mapa.hpp"
#include <iostream>
#include <cmath>


Mapa::Mapa() {
}

int Mapa::getTileSize()
{
    return tileSize;
}

int Mapa::getLarguraTileset()
{
    return larguraTileset;
}

int Mapa::getAlturaTileset()
{
    return alturaTileset;
}

int Mapa::getLarguraMapa()
{
    return larguraTileset * tileSize;
}

int Mapa::getContagemMoeda()
{
    return contagemMoeda;
}

void Mapa::atualizarContagemMoeda(int contagemMoedasMisteriosas)
{
    int contagem = 0;
    for(unsigned int i = 0; i < colisaoMoeda.size(); i++){
        if(colisaoMoeda[i] ==1){
            contagem++;
        }
    }
    contagemMoeda = contagem + contagemMoedasMisteriosas;
}

std::vector<std::vector<int>> Mapa::getDadosMapa()
{
    std::vector<std::vector<int>> matriz;
       
    for (unsigned int i = 0; i < tileData.size() / larguraTileset; ++i) {
        std::vector<int> linha;

        for (int j = 0; j < larguraTileset; ++j) {
            int indice = i * larguraTileset + j;
            linha.push_back(tileData[indice]);
        }

        matriz.push_back(linha);
    }

    return matriz;
}

void Mapa::inicializarColisoes()
{   
        int data = 0;
        for(unsigned int i = 0; i<tileData.size();i++){
            if(tileData[i] == 9){
                colisaoMoeda.push_back(data);
            }
            else if(tileData[i] == 2){
                colisaoBlocoMoeda.push_back(data);
            }
        }
}

void Mapa::carregarMapa(const std::string &arquivoMapa)
{
    // Carregamento do arquivo TMX usando a biblioteca tinyxml2
    tinyxml2::XMLDocument doc;
    doc.LoadFile(arquivoMapa.c_str());

    if (doc.Error()) {
        std::cerr << "Erro ao carregar o arquivo TMX: " << doc.ErrorStr() << std::endl;
        return;
    }

    // Obtém a primeira camada (layer) do mapa
    tinyxml2::XMLElement* layer = doc.FirstChildElement("map")->FirstChildElement("layer");

    // Obtém os dados codificados em CSV
    const char* data = layer->FirstChildElement("data")->GetText();

    // Processa os dados e preenche o array de vértices
    std::stringstream ss(data);
    int tileId;
    while (ss >> tileId) {
        tileData.push_back(tileId);
        if (ss.peek() == ',')
            ss.ignore();
    }
    
    // Define o tamanho do array de vértices
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(tileData.size() * 4);

    // Obtém as texturas do tileset
    tinyxml2::XMLNode * pRootElement = doc.FirstChildElement("map")->FirstChildElement("tileset");
    int count = 1;
    while(pRootElement){
        this->texturas[count++].loadFromFile(pRootElement->FirstChildElement("image")->Attribute("source"));
        pRootElement = pRootElement->NextSiblingElement("tileset");
    }
    
    // Preenche o array de vértices com base nos dados do mapa
    for (size_t i = 0; i < tileData.size(); ++i) {

        int tileNumber = tileData[i]; 

        if(tileNumber != 0){
            // Obtém o quad (quatro vértices) atual
            sf::Vertex* quad = &vertices[i * 4];

            // Define as posições dos vértices
            quad[0].position = sf::Vector2f((i % larguraTileset) * tileSize, (i / larguraTileset) * tileSize);
            quad[1].position = sf::Vector2f((i % larguraTileset + 1) * tileSize, (i / larguraTileset) * tileSize);
            quad[2].position = sf::Vector2f((i % larguraTileset + 1) * tileSize, (i / larguraTileset + 1) * tileSize);
            quad[3].position = sf::Vector2f((i % larguraTileset) * tileSize, (i / larguraTileset + 1) * tileSize);

            // Define as coordenadas de textura dos vértices
            quad[0].texCoords = sf::Vector2f(0, 0);
            quad[1].texCoords = sf::Vector2f(tileSize,0);
            quad[2].texCoords = sf::Vector2f(tileSize, tileSize);
            quad[3].texCoords = sf::Vector2f(0, tileSize);

        }
    }
}

void Mapa::renderizar(sf::RenderWindow& janela, sf::Time tempoAtual) {
    int tempoBloco = static_cast<int> (tempoAtual.asSeconds());
    tempoBloco = tempoBloco % 2;

    int tempoMoeda = static_cast<int> (tempoAtual.asMilliseconds()/100);
    tempoMoeda = tempoMoeda % 8;

    int contagemMoedas = 0;
    int contagemBlocoMoeda = 0;
    // Renderiza os vértices na janela
    for (size_t i = 0; i < tileData.size(); ++i) {
        int tileNumber = tileData[i];

        // Somente renderiza se não for um bloco vazio (tipo 0)
        if (tileNumber != 0 && tileNumber!= 2 && tileNumber!=9) {
            sf::Vertex* quad = &vertices[i * 4];
            janela.draw(quad, 4, sf::Quads, &texturas[tileNumber]);
        }
        else if(tileNumber == 2){
            if(colisaoBlocoMoeda[contagemBlocoMoeda] == 0){
                if(tempoBloco == 0){
                        sf::Vertex* quad = &vertices[i * 4];
                        janela.draw(quad, 4, sf::Quads, &texturas[2]);
                }
                else{
                    sf::Vertex* quad = &vertices[i * 4];
                    janela.draw(quad, 4, sf::Quads, &texturas[27]);
                }
            }
                else{
                    sf::Vertex* quad = &vertices[i * 4];
                    janela.draw(quad, 4, sf::Quads, &texturas[28]);
                }
                contagemBlocoMoeda++;
        }
        else if(tileNumber == 9){
            if(colisaoMoeda[contagemMoedas] == 0){
                sf::Vertex* quad = &vertices[i * 4];
                switch(tempoMoeda){
                    case 0:
                        janela.draw(quad, 4, sf::Quads, &texturas[9]);
                        break;
                    case 1:
                        janela.draw(quad, 4, sf::Quads, &texturas[29]);
                        break;
                    case 2:
                        janela.draw(quad, 4, sf::Quads, &texturas[30]);
                        break;
                    case 3:
                        janela.draw(quad, 4, sf::Quads, &texturas[31]);
                        break;
                    case 4:
                        janela.draw(quad, 4, sf::Quads, &texturas[32]);
                        break;
                    case 5:
                        janela.draw(quad, 4, sf::Quads, &texturas[33]);
                        break;
                    case 6:
                        janela.draw(quad, 4, sf::Quads, &texturas[34]);
                        break;
                    case 7:
                        janela.draw(quad, 4, sf::Quads, &texturas[35]);
                        break;
                }
            }
            contagemMoedas++;
        }
    }
}
void Mapa::aplicarColisaoMoeda(float x, float y) {
    int contagemMoeda = 0;

    // Convertendo coordenadas para índices
    unsigned int indiceX = static_cast<unsigned int>(x / tileSize);
    unsigned int indiceY = static_cast<unsigned int>(y / tileSize);
    
    // Calculando o índice na matriz
    unsigned int indice = indiceY * larguraTileset + indiceX;

    for (unsigned int i = 0; i < tileData.size(); i++) {
        if (tileData[i] == 9) {
            if (i == indice) {
                colisaoMoeda[contagemMoeda] = 1;
                break;
            }
            contagemMoeda++;
        }
    }
}

void Mapa::aplicarColisaoBlocoMoeda(float x, float y) {
    int contagemBlocoMoeda = 0;

    // Convertendo coordenadas para índices
    unsigned int indiceX = static_cast<unsigned int>(x / tileSize);
    unsigned int indiceY = static_cast<unsigned int>(y / tileSize);
    
    // Calculando o índice na matriz
    unsigned int indice = indiceY * larguraTileset + indiceX;

    for (unsigned int i = 0; i < tileData.size(); i++) {
        if (tileData[i] == 2) {
            if (i == indice) {
                colisaoBlocoMoeda[contagemBlocoMoeda] = 1;
                break;
            }
            contagemBlocoMoeda++;
        }
    }
}

int Mapa::getColisaoBlocoMoeda(float x, float y) {
    int contagemBlocoMoeda = 0;

    // Convertendo coordenadas para índices
    unsigned int indiceX = static_cast<unsigned int>(x / tileSize);
    unsigned int indiceY = static_cast<unsigned int>(y / tileSize);
    
    // Calculando o índice na matriz
    unsigned int indice = indiceY * larguraTileset + indiceX;

    for (unsigned int i = 0; i < tileData.size(); i++) {
        if (tileData[i] == 2) {
            if (i == indice) {
                return colisaoBlocoMoeda[contagemBlocoMoeda];
            }
            contagemBlocoMoeda++;
        }
    }
    return -1;
}