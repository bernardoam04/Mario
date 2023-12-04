#include "doctest.h"
#include "../include/Colisao.hpp"

TEST_CASE("Teste verificarColisao - Bloco Chão") {
    std::vector<std::vector<int>> dadosMapa = {{1}}; // BLOCO_CHAO = 1
    Colisao colisao(dadosMapa, 32);

    CHECK(colisao.verificarColisao(0.0f, 0.0f) == 1); // BLOCO_CHAO = 1
}

TEST_CASE("Teste verificarColisao - Bloco Moeda") {
    std::vector<std::vector<int>> dadosMapa = {{2}}; // BLOCO_MOEDA = 2
    Colisao colisao(dadosMapa, 32);

    CHECK(colisao.verificarColisao(0.0f, 0.0f) == 2); // BLOCO_MOEDA = 2
}

TEST_CASE("Teste verificarColisao - Bloco Normal") {
    std::vector<std::vector<int>> dadosMapa = {{3}}; // BLOCO_NORMAL = 3
    Colisao colisao(dadosMapa, 32);

    CHECK(colisao.verificarColisao(0.0f, 0.0f) == 3); // BLOCO_NORMAL = 3
}

TEST_CASE("Teste verificarColisao - Cano Inferior Esquerdo") {
    std::vector<std::vector<int>> dadosMapa = {{4}}; // CANO_INFERIOR_ESQUERDO = 4
    Colisao colisao(dadosMapa, 32);

    CHECK(colisao.verificarColisao(0.0f, 0.0f) == 4); // CANO_INFERIOR_ESQUERDO = 4
}

TEST_CASE("Teste verificarColisao - Cano Inferior Direito") {
    std::vector<std::vector<int>> dadosMapa = {{5}}; // CANO_INFERIOR_DIREITO = 5
    Colisao colisao(dadosMapa, 32);

    CHECK(colisao.verificarColisao(0.0f, 0.0f) == 5); // CANO_INFERIOR_DIREITO = 5
}

TEST_CASE("Teste verificarColisao - Bloco Escada") {
    std::vector<std::vector<int>> dadosMapa = {{8}}; // BLOCO_ESCADA = 8
    Colisao colisao(dadosMapa, 32);

    CHECK(colisao.verificarColisao(0.0f, 0.0f) == 8); // BLOCO_ESCADA = 8
}

TEST_CASE("Teste verificarColisao - Moeda") {
    std::vector<std::vector<int>> dadosMapa = {{9}}; // MOEDA = 9
    Colisao colisao(dadosMapa, 32);

    CHECK(colisao.verificarColisao(0.0f, 0.0f) == 9); // MOEDA = 9
}

TEST_CASE("Teste verificarColisao - Fora dos limites") {
    std::vector<std::vector<int>> dadosMapa(20, std::vector<int>(280, 1)); // BLOCO_CHAO = 1
    Colisao colisao(dadosMapa, 32);

    CHECK(colisao.verificarColisao(64.0f, 64.0f) == 0);
}

TEST_CASE("Teste verificarColisao - Tipo de bloco inválido") {
    std::vector<std::vector<int>> dadosMapa = {{10}}; // Tipo de bloco inválido
    Colisao colisao(dadosMapa, 32);

    CHECK(colisao.verificarColisao(0.0f, 0.0f) == 0);
}

TEST_CASE("Teste verificarColisao - Posição negativa") {
    std::vector<std::vector<int>> dadosMapa = {{1}}; // BLOCO_CHAO = 1
    Colisao colisao(dadosMapa, 32);

    CHECK(colisao.verificarColisao(-32.0f, -32.0f) == 0);
}
