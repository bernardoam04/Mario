#ifndef COLISAO_HPP
#define COLISAO_HPP

#include "Mapa.hpp"
#include <vector>

class Colisao {
private:
    //Dados do mapa
    const std::vector<std::vector<int>> dadosMapa;
    const int tileSize;

    //Tipos de bloco
    static const int BLOCO_CHAO = 1; 
    static const int BLOCO_MOEDA = 2; 
    static const int BLOCO_NORMAL = 3; 
    static const int CANO_INFERIOR_ESQUERDO = 4; 
    static const int CANO_INFERIOR_DIREITO = 5; 
    static const int CANO_SUPERIOR_DIREITO = 6; 
    static const int CANO_SUPERIOR_ESQUERDO = 7; 
    static const int BLOCO_ESCADA = 8; 
    static const int MOEDA = 9; 
public:
    //Construtor
    Colisao(const std::vector<std::vector<int>> dadosMapa, int tileSize);

    //Método de verificação
    int verificarColisao(float x, float y);
};

#endif 
