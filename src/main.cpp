#include "../include/GerenciadorGeral.hpp"

/*
g++ -Wall -Wextra -Werror main.cpp GerenciadorGeral.cpp Mapa.cpp PoderesEspeciais.cpp Camera.cpp Colisao.cpp -o app.exe -lsfml-graphics -lsfml-window -lsfml-system tinyxml2.cpp
.\app.exe
*/

int main() {
    
    //Inicializa o gerenciador do jogo    
    GerenciadorGeral jogo;

    sf::Clock timer;

    while (jogo.janelaAberta()) {
        sf::Time deltaTime = timer.restart(); 
        //Atualiza o jogo
        jogo.atualizar(deltaTime);

        //Desenha o jogo
        jogo.renderizar();

    }
    return 0;
}