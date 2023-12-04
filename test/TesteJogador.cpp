#include "doctest.h"
#include "../include/Jogador.hpp"

TEST_CASE("Testando a classe Jogador") {
    SUBCASE("Construtor e Configurações Iniciais") {
        Colisao colisao({{1, 1}, {1, 1}}, 32);
        auto janela = std::make_shared<sf::RenderWindow>();
        Jogador jogador(colisao, 800, 600, janela);

        CHECK(jogador.getVivo() == true);
        CHECK(jogador.getEstaNoAr() == false);
        CHECK(jogador.getVelocidadeVertical() == 0);
        CHECK(jogador.getAlturaJogador() > 0);
        CHECK(jogador.getLarguraJogador() > 0);
        CHECK(jogador.getVida() == 3);
        CHECK(jogador.getGanhou() == false);
        CHECK(jogador.getPerdeu() == false);
        CHECK(jogador.estaInvencivel() == false);
        CHECK(jogador.estaSubindo() == false);
    }

    SUBCASE("Movimento e Colisão") {
        Colisao colisao({{1, 1}, {1, 1}}, 32);
        auto janela = std::make_shared<sf::RenderWindow>();
        Jogador jogador(colisao, 800, 600, janela);

        // Teste para verificar o movimento e a colisão do Jogador
        jogador.modificarPosicao(sf::seconds(1.0f), 800);

        CHECK((jogador.estaMovendoDireita() || jogador.estaMovendoEsquerda()) == true);
        CHECK(jogador.getEstaNoAr() == true || jogador.getVelocidadeVertical() == 0);
        CHECK(jogador.getPosicao().x >= 0 && jogador.getPosicao().x <= 800);
        CHECK(jogador.getPosicao().y >= 0 && jogador.getPosicao().y <= 600);
        CHECK(jogador.getVelocidadeVertical() == 0 || jogador.getEstaNoAr());
        CHECK(jogador.estaSubindo() == (jogador.getVelocidadeVertical() < 0));
    }

    SUBCASE("Colisão com o Mapa") {
        Colisao colisao({{1, 1}, {1, 1}}, 32);
        auto janela = std::make_shared<sf::RenderWindow>();
        Jogador jogador(colisao, 800, 600, janela);
        Mapa mapa;

        jogador.atualizarColisao(mapa);

    }

    SUBCASE("Perder Vida e Estado após Perder Vida") {
        Colisao colisao({{1, 1}, {1, 1}}, 32);
        auto janela = std::make_shared<sf::RenderWindow>();
        Jogador jogador(colisao, 800, 600, janela);

        jogador.perderVida();

        CHECK(jogador.getVida() == 2);
        CHECK(jogador.estaInvencivel() == true);

        // Aguarda o tempo necessário para que a invencibilidade expire
        sf::Clock clock;
        while (clock.getElapsedTime().asSeconds() < 2.5) {
            // Aguarda...
        }

        CHECK(jogador.estaInvencivel() == false);
    }
}
