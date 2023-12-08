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

    std::set<int> colisaoEspecial = {NULO, SURPRESA, MOEDA}; ///< Conjunto de valores que representam blocos com colisão especial no mapa.

    // Dados utilizados para desenhar o mapa
    std::unordered_map<int, sf::Texture> texturas; ///< Mapeamento de texturas associadas aos tipos de blocos no mapa.
    sf::VertexArray vertices; ///< Vetor de vértices para renderizar o mapa.
    std::vector<std::pair<int,bool>> tileData; ///< Dados dos blocos e se houve colisao em caso de blocos que têm tratamento diferente na colisão.

    // Som
    std::shared_ptr<SoundManager> _sounds; ///< Smart Pointer para a instância do gerenciador de som.

    // Constantes
    const int tileSize = 32; ///< Tamanho de cada bloco no mapa.
    const int larguraTileset = 280; ///< Largura total do tileset.
    const int alturaTileset = 20; ///< Altura total do tileset.

    // Dados de Verificação
    std::vector<int> colisaoBlocoMoeda; ///< Dados de colisão específicos para blocos de moedas.
    std::vector<int> colisaoMoeda; ///< Dados de colisão específicos para moedas.

    // Contagem 
    int contagemMoeda = 0; ///< Contagem total de moedas coletadas.
    int contagemPoderEspecial = 0; ///< Contagem total de poderes especiais coletados.


public:
    /**
     * @brief Construtor padrão da classe Mapa.
     */
    Mapa();

    /**
     * @brief Inicializa as colisões do mapa.
     */
    void inicializarColisoes();

    /**
     * @brief Carrega o mapa a partir de um arquivo tmx.
     * @param arquivoMapa Caminho do arquivo do mapa (deve ser um arquivo tmx).
     */
    void carregarMapa(const std::string& arquivoMapa);

    /**
     * @brief Renderiza o mapa na janela.
     * @param janela Referência para a janela SFML.
     * @param tempoAtual Tempo atual do jogo.
     * @param x Posição horizontal da câmera.
     */
    void renderizar(sf::RenderWindow& janela, sf::Time tempoAtual, float x);

    /**
     * @brief Aplica colisões a partir de posições que o jogador se encontra.
     * @param posicoes Vetor de pares (x, y) representando as posições de colisão.
     */
    void aplicarColisao(std::vector<std::pair<int,int>> posicoes);

    /**
     * @brief Obtém a colisão com bloco de moeda (com ?) em uma posição específica.
     * @param x Posição horizontal.
     * @param y Posição vertical.
     * @return Verdadeiro se houver colisão com bloco de moeda (com ?); falso caso contrário.
     */
    bool getColisaoBlocoMoeda(float x, float y);

    // Getters

    /**
     * @brief Obtém os dados do mapa.
     * @return Vetor bidimensional contendo os dados do mapa.
     */
    std::vector<std::vector<int>> getDadosMapa();

    /**
     * @brief Obtém o tamanho do bloco no mapa.
     * @return Tamanho do bloco.
     */
    int getTileSize();

    /**
     * @brief Obtém a largura do tileset.
     * @return Largura do tileset.
     */
    int getLarguraTileset();

    /**
     * @brief Obtém a altura do tileset.
     * @return Altura do tileset.
     */
    int getAlturaTileset();

    /**
     * @brief Obtém a largura do mapa.
     * @return Largura do mapa.
     */
    int getLarguraMapa();

    /**
     * @brief Obtém a contagem total de moedas.
     * @return Contagem total de moedas.
     */
    int getContagemMoeda();

    /**
     * @brief Obtém a contagem total de poderes especiais.
     * @return Contagem total de poderes especiais.
     */
    int getContagemPoderEspecial();

    // Setters

    /**
     * @brief Atualiza a contagem de moedas.
     * @param contagemMoedasMisteriosas Contagem de moedas misteriosas.
     */
    void atualizarContagemMoeda(int contagemMoedasMisteriosas);

    /**
     * @brief Atualiza a contagem de poderes especiais.
     * @param contagemPoderes Contagem de poderes especiais.
     */
    void atualizarContagemPoderes(int contagemPoderes);

    /**
     * @brief Define o gerenciador de som para a instância atual.
     * @param sounds Smart Pointer para o gerenciador de som.
     */
    void setSound(std::shared_ptr<SoundManager> sounds);

};  
#endif