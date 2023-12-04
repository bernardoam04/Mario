#include "doctest.h"
#include "../include/GameOver.hpp"

TEST_CASE("Teste construtor e desenharTela") {

    // Criar instância de GameOver
    sf::RenderWindow janela;
    sf::Font fonte;
    GameOver gameover(std::make_shared<sf::RenderWindow>(janela), fonte);

    // Chamar desenharTela e verificar se não há exceções
    CHECK_NOTHROW(gameover.desenharTela(100, sf::View()));
}

TEST_CASE("Teste atualizar e atualizarPosicaoTextos") {

    // Criar instância de GameOver
    sf::RenderWindow janela;
    sf::Font fonte;
    GameOver gameover(std::make_shared<sf::RenderWindow>(janela), fonte);

    // Criar um evento para simular ações do usuário
    sf::Event ev;
    ev.type = sf::Event::Closed;

    // Chamar atualizar e verificar se não há exceções
    CHECK_NOTHROW(gameover.atualizar(ev, sf::View()));

    // Chamar atualizarPosicaoTextos e verificar se não há exceções
    CHECK_NOTHROW(gameover.atualizarPosicaoTextos(sf::View()));
}

TEST_CASE("Teste atualizar com clique fora da área desejada") {

    // Criar instância de GameOver
    sf::RenderWindow janela;
    sf::Font fonte;
    GameOver gameover(std::make_shared<sf::RenderWindow>(janela), fonte);

    // Simular um clique fora da área desejada
    sf::Event ev;
    ev.type = sf::Event::MouseButtonPressed;
    ev.mouseButton.x = 100;
    ev.mouseButton.y = 100;

    // Chamar atualizar e verificar se retorna true (sem clicar no botão)
    CHECK(gameover.atualizar(ev, sf::View()) == true);
}

TEST_CASE("Teste atualizar com clique dentro da área desejada") {

    // Criar instância de GameOver
    sf::RenderWindow janela;
    sf::Font fonte;
    GameOver gameover(std::make_shared<sf::RenderWindow>(janela), fonte);

    // Simular um clique dentro da área desejada
    sf::Event ev;
    ev.type = sf::Event::MouseButtonPressed;
    ev.mouseButton.x = 400; // Supondo que a área desejada esteja centrada em x=400
    ev.mouseButton.y = 300; // Supondo que a área desejada esteja centrada em y=300

    // Chamar atualizar e verificar se retorna false (clicou no botão)
    CHECK(gameover.atualizar(ev, sf::View()) == false);
}
