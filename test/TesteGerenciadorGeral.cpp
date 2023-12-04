#include "doctest.h"
#include "../include/GerenciadorGeral.hpp"
#include "../include/SoundManager.hpp" //

TEST_CASE("Teste inicialização e atualização") {
    auto janela = std::make_shared<sf::RenderWindow>();
    sf::Font fonte;
    auto sounds = std::make_shared<SoundManager>();

    // Criar instância de GerenciadorGeral
    GerenciadorGeral gerenciador(janela, fonte, sounds);

    // Chamar atualizar e verificar se não há exceções
    sf::Event ev;
    CHECK_NOTHROW(gerenciador.atualizar(sf::Time(), sf::Time(), ev));
}

TEST_CASE("Teste eventos do teclado") {
    auto janela = std::make_shared<sf::RenderWindow>();
    sf::Font fonte;
    auto sounds = std::make_shared<SoundManager>();

    // Criar instância de GerenciadorGeral
    GerenciadorGeral gerenciador(janela, fonte, sounds);

    // Simular pressionar a tecla 'Right'
    sf::Event ev;
    ev.type = sf::Event::KeyPressed;
    ev.key.code = sf::Keyboard::Right;
    CHECK_NOTHROW(gerenciador.atualizar(sf::Time(), sf::Time(), ev));

    // Simular pressionar a tecla 'Left'
    ev.key.code = sf::Keyboard::Left;
    CHECK_NOTHROW(gerenciador.atualizar(sf::Time(), sf::Time(), ev));

    // Simular liberar a tecla 'Up'
    ev.type = sf::Event::KeyReleased;
    ev.key.code = sf::Keyboard::Up;
    CHECK_NOTHROW(gerenciador.atualizar(sf::Time(), sf::Time(), ev));
}

TEST_CASE("Teste colisão com PoderesEspeciais") {
    auto janela = std::make_shared<sf::RenderWindow>();
    sf::Font fonte;
    auto sounds = std::make_shared<SoundManager>();

    // Criar instância de GerenciadorGeral
    GerenciadorGeral gerenciador(janela, fonte, sounds);

    // Adicionar PoderesEspeciais no mapa (simulando inicialização)
    gerenciador.InicializarPoderesEspeciais();

    // Simular a posição do jogador para colidir com PoderesEspeciais
    gerenciador.getMario()->setPosicao(32.0f, 32.0f); // Supondo posição inicial do jogador

    // Chamar atualizar e verificar se PoderesEspeciais são detectados e removidos
    sf::Event ev;
    CHECK_NOTHROW(gerenciador.atualizar(sf::Time(), sf::Time(), ev));

    // Verificar que a contagem de PoderesEspeciais é reduzida
    CHECK(gerenciador.getContagemPoderesEspeciais() == 0);
}

TEST_CASE("Teste inicialização e atualização com som desativado") {
    auto janela = std::make_shared<sf::RenderWindow>();
    sf::Font fonte;
    auto sounds = std::make_shared<SoundManager>();
    sounds->desativarSom();  // Desativar som

    // Criar instância de GerenciadorGeral
    GerenciadorGeral gerenciador(janela, fonte, sounds);

    // Chamar atualizar e verificar se não há exceções
    sf::Event ev;
    CHECK_NOTHROW(gerenciador.atualizar(sf::Time(), sf::Time(), ev));
}

TEST_CASE("Teste colisão com Goomba") {
    auto janela = std::make_shared<sf::RenderWindow>();
    sf::Font fonte;
    auto sounds = std::make_shared<SoundManager>();

    // Criar instância de GerenciadorGeral
    GerenciadorGeral gerenciador(janela, fonte, sounds);

    // Colocar o jogador em uma posição onde haja um Goomba
    gerenciador.getMario()->setPosicao(1000.0f, 544.0f);  // Posição do Goomba no seu código

    // Chamar atualizar e verificar se Goomba é detectado e jogador perde
    sf::Event ev;
    CHECK_FALSE(gerenciador.atualizar(sf::Time(), sf::Time(), ev));  // Deve retornar falso (jogo encerrado)
    CHECK(gerenciador.getGamerOver());  // O jogo deve estar encerrado
}

TEST_CASE("Teste vitória do jogador") {
    auto janela = std::make_shared<sf::RenderWindow>();
    sf::Font fonte;
    auto sounds = std::make_shared<SoundManager>();

    // Criar instância de GerenciadorGeral
    GerenciadorGeral gerenciador(janela, fonte, sounds);

    // Posicionar o jogador em uma posição onde a vitória seja alcançada
    gerenciador.getMario()->setPosicao(6000.0f, 544.0f);  // Posição do ponto final no seu código

    // Chamar atualizar e verificar se o jogador ganhou
    sf::Event ev;
    CHECK_FALSE(gerenciador.atualizar(sf::Time(), sf::Time(), ev));  // Deve retornar falso (jogo encerrado)
    CHECK(gerenciador.getGamerOver());  // O jogo deve estar encerrado
    CHECK(gerenciador.getMario()->getGanhou());  // O jogador deve ter ganho
}


