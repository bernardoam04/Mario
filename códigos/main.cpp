#include "GerenciadorGeral.hpp"


/*
g++ -Wall -Wextra -Werror main.cpp GerenciadorGeral.cpp -o app.exe -lsfml-graphics -lsfml-window -lsfml-system
.\app.exe
*/

int main() {

    //Inicializa o gerenciador do jogo
    GerenciadorGeral jogo;

    sf::Clock timer;

    while (jogo.janelaAberta()) {
        
        jogo.atualizar();

        jogo.renderizar();

    }

    return 0;
}