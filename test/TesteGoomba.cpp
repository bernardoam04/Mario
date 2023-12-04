#include "doctest.h"
#include "../include/Goomba.hpp"

TEST_CASE("Testando a classe Goomba") {
    SUBCASE("Construtor") {
        // Teste para garantir que o Goomba é inicializado corretamente
        Colisao colisao({{1, 1}, {1, 1}}, 32);  // Exemplo de dados do mapa e tamanho do bloco
        auto janela = std::make_shared<sf::RenderWindow>();
        Goomba goomba(colisao, janela, 0.0f, 0.0f);

        CHECK(goomba.getVivo() == true);
        CHECK(goomba.getMovDireita() == false);
        CHECK(goomba.getMovEsquerda() == true);
        CHECK(goomba.getVelocidadeVertical() == 0);
        CHECK(goomba.getEstaNoAr() == false);
    }

    SUBCASE("Atacar") {
        // Teste para verificar se o método de ataque funciona corretamente
        Colisao colisao({{1, 1}, {1, 1}}, 32);  // Exemplo de dados do mapa e tamanho do bloco
        auto janela = std::make_shared<sf::RenderWindow>();
        Goomba goomba(colisao, janela, 0.0f, 0.0f);
        auto mario = std::make_shared<Jogador>(colisao, 640, 640, janela);

        goomba.atacar(mario);
        CHECK(mario->getVida() == 0);  
    }

    SUBCASE("Verificar Colisão com Goomba") {
        // Teste para verificar a detecção de colisões com o método verificarColisaoComGoomba
        Colisao colisao({{1, 1}, {1, 1}}, 32);  // Exemplo de dados do mapa e tamanho do bloco
        auto janela = std::make_shared<sf::RenderWindow>();
        Goomba goomba(colisao, janela, 0.0f, 0.0f);
        auto mario = std::make_shared<Jogador>(colisao, 640, 640, janela);

        mario->setPosicao(0.0f, 0.0f);
        CHECK(goomba.verificarColisaoComGoomba(mario) == true);
    }

    SUBCASE("Movimento e Colisão") {
        Colisao colisao({{1, 1}, {1, 1}}, 32);
        auto janela = std::make_shared<sf::RenderWindow>();
        Goomba goomba(colisao, janela, 0.0f, 0.0f);

        // Teste para verificar o movimento e a colisão do Goomba
        goomba.modificarPosicao(sf::seconds(1.0f), 800);

        CHECK((goomba.getMovDireita() || goomba.getMovEsquerda()) == true);
        CHECK(goomba.getEstaNoAr() == true || goomba.getVelocidadeVertical() == 0);
        CHECK(goomba.getPosicao().x >= 0 && goomba.getPosicao().x <= 800);
        CHECK(goomba.getPosicao().y >= 0 && goomba.getPosicao().y <= 640);
    }
}

#include "doctest.h"
#include "../include/Goomba.hpp"

TEST_CASE("Testando a classe Goomba") {
    SUBCASE("Construtor") {
        // Teste para garantir que o Goomba é inicializado corretamente
        Colisao colisao({{1, 1}, {1, 1}}, 32);  // Exemplo de dados do mapa e tamanho do bloco
        auto janela = std::make_shared<sf::RenderWindow>();
        Goomba goomba(colisao, janela, 0.0f, 0.0f);

        CHECK(goomba.getVivo() == true);
        CHECK(goomba.getMovDireita() == false);
        CHECK(goomba.getMovEsquerda() == true);
        CHECK(goomba.getVelocidadeVertical() == 0);
        CHECK(goomba.getEstaNoAr() == false);
        CHECK(goomba.getVelocidadeHorizontal() == 30.0f);
        CHECK(goomba.getAceleracaoGravidade() == 9.8f);
        CHECK(goomba.getTileSize() == 32);
    }

    SUBCASE("Atacar") {
        // Teste para verificar se o método de ataque funciona corretamente
        Colisao colisao({{1, 1}, {1, 1}}, 32);  
        auto janela = std::make_shared<sf::RenderWindow>();
        Goomba goomba(colisao, janela, 0.0f, 0.0f);
        auto mario = std::make_shared<Jogador>(colisao, 640, 640, janela);

        goomba.atacar(mario);
        CHECK(mario->getVida() == 0);  
    }

    SUBCASE("Verificar Colisão com Goomba") {
        // Teste para verificar a detecção de colisões com o método verificarColisaoComGoomba
        Colisao colisao({{1, 1}, {1, 1}}, 32); 
        auto janela = std::make_shared<sf::RenderWindow>();
        Goomba goomba(colisao, janela, 0.0f, 0.0f);
        auto mario = std::make_shared<Jogador>(colisao, 640, 640, janela);

        mario->setPosicao(0.0f, 0.0f);
        CHECK(goomba.verificarColisaoComGoomba(mario) == true);
    }

    SUBCASE("Movimento e Colisão") {
        Colisao colisao({{1, 1}, {1, 1}}, 32);
        auto janela = std::make_shared<sf::RenderWindow>();
        Goomba goomba(colisao, janela, 0.0f, 0.0f);

        // Teste para verificar o movimento e a colisão do Goomba
        goomba.modificarPosicao(sf::seconds(1.0f), 800);

        CHECK((goomba.getMovDireita() || goomba.getMovEsquerda()) == true);
        CHECK(goomba.getEstaNoAr() == true || goomba.getVelocidadeVertical() == 0);
        CHECK(goomba.getPosicao().x >= 0 && goomba.getPosicao().x <= 800);
        CHECK(goomba.getPosicao().y >= 0 && goomba.getPosicao().y <= 640);
        CHECK(goomba.getVelocidadeVertical() == 0 || goomba.getEstaNoAr());
    }
}
