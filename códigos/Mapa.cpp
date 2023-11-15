#include "Mapa.hpp"

Mapa::Mapa() {
    // Inicialize qualquer coisa necessária para o mapa
}

void Mapa::carregarMapa(const std::string& arquivoMapa) {
    // Carregue o arquivo TMX usando a biblioteca tinyxml2
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
    std::vector<int> tileData;
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

    // Obtém a textura do tileset
    const char* tilesetImage = doc.FirstChildElement("map")->FirstChildElement("tileset")->FirstChildElement("image")->Attribute("source");
    texturatileset.loadFromFile(tilesetImage);

    // Define o tamanho do tile (32x32 neste caso)
    const int tileSize = 32;
    const int largura_tileset= 280;

    // Configuração da cor preta para os quadrados onde o valor é zero
    sf::Color corPreta(0, 0, 0, 255);

    // Preenche o array de vértices com base nos dados do mapa
    for (size_t i = 0; i < tileData.size(); ++i) {
        int tileNumber = tileData[i] - 1; // Ajusta o índice do tile (começa em 1 no TMX)

        // Calcula as coordenadas do tile no tileset
        int tu = tileNumber % (texturatileset.getSize().x / tileSize);
        int tv = tileNumber / (texturatileset.getSize().x / tileSize);

        // Obtém o quad (quatro vértices) atual
        sf::Vertex* quad = &vertices[i * 4];

        // Define as posições dos vértices
        quad[0].position = sf::Vector2f((i % largura_tileset) * tileSize, (i / largura_tileset) * tileSize);
        quad[1].position = sf::Vector2f((i % largura_tileset + 1) * tileSize, (i / largura_tileset) * tileSize);
        quad[2].position = sf::Vector2f((i % largura_tileset + 1) * tileSize, (i / largura_tileset + 1) * tileSize);
        quad[3].position = sf::Vector2f((i % largura_tileset) * tileSize, (i / largura_tileset + 1) * tileSize);

        // Define as coordenadas de textura dos vértices
        quad[0].texCoords = sf::Vector2f(tu * tileSize, tv * tileSize);
        quad[1].texCoords = sf::Vector2f((tu+1) * tileSize, tv * tileSize);
        quad[2].texCoords = sf::Vector2f((tu+1) * tileSize, (tv + 1) * tileSize);
        quad[3].texCoords = sf::Vector2f(tu * tileSize, (tv + 1) * tileSize);

        tileNumber++;
        // Configura a cor dos vértices - preto se o valor for zero, caso contrário, cor padrão (branco)
        if(tileNumber==0){
        sf::Color corAtual = corPreta;

        quad[0].color = corAtual;
        quad[1].color = corAtual;
        quad[2].color = corAtual;
        quad[3].color = corAtual;
        }
        else if(tileNumber==2){
        sf::Color corAtual = sf::Color::Blue;  
        quad[0].color = corAtual;
        quad[1].color = corAtual;
        quad[2].color = corAtual;
        quad[3].color = corAtual;
        }
    }
}

void Mapa::renderizar(sf::RenderWindow& janela) {
    // Renderiza os vértices na janela
    janela.draw(vertices, &texturatileset);
}