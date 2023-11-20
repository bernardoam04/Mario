#include "../include/Colisao.hpp"

Colisao::Colisao(const std::vector<std::vector<int>> dadosMapa, int tileSize)
    : dadosMapa(dadosMapa), tileSize(tileSize) {}

int Colisao::verificarColisao(float x, float y) {
    // Converte as coordenadas para índices da matriz
    unsigned int coluna = static_cast<int>(x / tileSize);
    unsigned int linha = static_cast<int>(y / tileSize);

    // Verifica se está dentro dos limites da matriz
    if (linha < dadosMapa.size() && coluna < dadosMapa[0].size()) {
        int tipoBloco = dadosMapa[linha][coluna];

        // Verifica se é um bloco sólido
        switch (tipoBloco) {
            case BLOCO_CHAO:
            case BLOCO_MOEDA:
            case BLOCO_NORMAL:
            case CANO_INFERIOR_ESQUERDO:
            case CANO_INFERIOR_DIREITO:
            case CANO_SUPERIOR_DIREITO:
            case CANO_SUPERIOR_ESQUERDO:
            case BLOCO_ESCADA:
            case MOEDA:
                return tipoBloco; // Retorna o número do tipo de bloco
            default:
                return 0; //retorna 0 se não tiver bloco ou o bloco nao tiver colisao
        }
    }

    return 0;
}
