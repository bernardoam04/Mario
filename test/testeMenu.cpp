#include "doctest.h"
#include "../include/Menu.hpp"


 TEST_CASE("Teste de inicialização e desativação do som") {
    sf::RenderWindow janela;
    sf::Font fonte;
    Menu menu(std::make_shared<sf::RenderWindow>(janela), fonte);

    SUBCASE("Verificar inicialização padrão do som") {
        CHECK(menu.getSomAtivo() == true);  // Certifique-se de que o som está ativado por padrão
    }

    SUBCASE("Desativar som") {
        menu.tratarCliqueMouse();  // Simula um clique para desativar o som
        CHECK(menu.getSomAtivo() == false);  // Certifique-se de que o som foi desativado
    }

    SUBCASE("Ativar som") {
        menu.tratarCliqueMouse();  // Simula um clique para desativar o som
        menu.tratarCliqueMouse();  // Simula outro clique para ativar o som
        CHECK(menu.getSomAtivo() == true);  // Certifique-se de que o som foi ativado
    }

    }