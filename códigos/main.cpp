#include "GerenciadorGeral.hpp"


/*
g++ -Wall -Wextra -Werror main.cpp GerenciadorGeral.cpp Mapa.cpp -o app.exe -lsfml-graphics -lsfml-window -lsfml-system tinyxml2.cpp
.\app.exe
*/

int main() {

    //Inicializa o gerenciador do jogo
    GerenciadorGeral jogo;

    sf::Clock timer;

    while (jogo.janelaAberta()) {
        
        //Atualiza o jogo
        jogo.atualizar();

        //Desenha o jogo
        jogo.renderizar();

    }

    return 0;
}