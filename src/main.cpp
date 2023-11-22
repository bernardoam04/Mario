#include "../include/GerenciadorGeral.hpp"

/*
g++ -Wall -Wextra main.cpp GerenciadorGeral.cpp Mapa.cpp PoderesEspeciais.cpp Camera.cpp Colisao.cpp -o app.exe -lsfml-graphics -lsfml-window -lsfml-system tinyxml2.cpp
.\app.exe
*/

int main() {
    
    //Inicializa o gerenciador do jogo    
    GerenciadorGeral jogo;

    sf::Clock timer;
    sf::Clock timer2;

    sf::Time deltaTime;

    timer.restart();

    while (jogo.janelaAberta()) {

        //Calcula o tempo passado entre cada iteração
        sf::Time deltaTime = timer2.restart(); 

        // Calcula o tempo que passou desde o início do jogo
        sf::Time tempoAtual = timer.getElapsedTime();
        
        //Atualiza o jogo
        jogo.atualizar(tempoAtual, deltaTime);

        //Desenha o jogo
        jogo.renderizar(tempoAtual);

    }
    return 0;
}