#include "doctest.h"
#include "../include/Camera.hpp"

TEST_CASE("Teste Construtor e getView") {
    Camera camera(800.0f, 600.0f);
    
    // Verifica se o tamanho da view foi configurado corretamente
    CHECK(camera.getView().getSize() == sf::Vector2f(800.0f, 600.0f));

    // Verifica se o centro da view foi configurado corretamente
    CHECK(camera.getView().getCenter() == sf::Vector2f(400.0f, 300.0f));
}

TEST_CASE("Teste setCenter e atualizarPosicao") {
    Camera camera(800.0f, 600.0f);

    // Testa setCenter
    sf::Vector2f novoCentro(100.0f, 200.0f);
    camera.setCenter(novoCentro);
    CHECK(camera.getView().getCenter() == novoCentro);

    // Testa atualizarPosicao
    sf::Vector2f posicaoPersonagem(300.0f, 400.0f);
    camera.atualizarPosicao(posicaoPersonagem);
    CHECK(camera.getView().getCenter().x == posicaoPersonagem.x);
    CHECK(camera.getView().getCenter().y == 300.0f); // Y deve permanecer inalterado
}

TEST_CASE("Teste getVelocidadeCamera") {
    Camera camera(800.0f, 600.0f);

    // Verifica se a velocidade da câmera é retornada corretamente
    CHECK(camera.getVelocidadeCamera() == 0.0f);
}
