#include "../include/Colisao.hpp"

Colisao::Colisao(const std::vector<std::vector<int>> dadosMapa, int tileSize)
    : dadosMapa(dadosMapa), tileSize(tileSize) {}

int Colisao::verificarColisao(float x, float y) {
    try {
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
                    return 0; // Retorna 0 se não tiver bloco ou o bloco não tiver colisão
            }
        } else {
            // Trata exceção caso as coordenadas estejam fora dos limites da matriz
            throw std::out_of_range("Coordenadas fora dos limites da matriz");
        }
    } catch (const std::exception& e) {
        return 0; // Retorna 0 em caso de erro
    }
}
