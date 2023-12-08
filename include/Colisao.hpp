#ifndef COLISAO_HPP
#define COLISAO_HPP

#include "../include/Mapa.hpp"
#include <vector>

/**
 * @brief Classe que lida com detecção de colisão em um mapa.
 */
class Colisao {
private:
    // Dados do mapa
    const std::vector<std::vector<int>> dadosMapa; ///< Dados do mapa representados por uma matriz de inteiros.
    const int tileSize; ///< Tamanho do bloco no mapa.

    // Tipos de bloco
    static const int BLOCO_CHAO = 1; ///< Identificador para bloco de chão.
    static const int BLOCO_MOEDA = 2; ///< Identificador para bloco de moeda.
    static const int BLOCO_NORMAL = 3; ///< Identificador para bloco normal.
    static const int CANO_INFERIOR_ESQUERDO = 4; ///< Identificador para canto inferior esquerdo de um cano.
    static const int CANO_INFERIOR_DIREITO = 5; ///< Identificador para canto inferior direito de um cano.
    static const int CANO_SUPERIOR_DIREITO = 6; ///< Identificador para canto superior direito de um cano.
    static const int CANO_SUPERIOR_ESQUERDO = 7; ///< Identificador para canto superior esquerdo de um cano.
    static const int BLOCO_ESCADA = 8; ///< Identificador para bloco de escada.
    static const int MOEDA = 9; ///< Identificador para moeda.

public:
    /**
     * @brief Construtor da classe Colisao.
     * @param dadosMapa Dados do mapa representados por uma matriz de inteiros.
     * @param tileSize Tamanho do bloco no mapa.
     */
    Colisao(const std::vector<std::vector<int>> dadosMapa, int tileSize);

    /**
     * @brief Verifica a colisão em uma posição específica no mapa.
     * @param x Posição horizontal.
     * @param y Posição vertical.
     * @return Identificador do tipo de bloco com o qual ocorreu a colisão.
     */
    int verificarColisao(float x, float y);
};

#endif 
