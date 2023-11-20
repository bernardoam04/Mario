#include "GerenciadorGeral.hpp"

/*
g++ -Wall -Wextra -Werror main.cpp GerenciadorGeral.cpp Mapa.cpp PoderesEspeciais.cpp Camera.cpp Colisao.cpp -o app.exe -lsfml-graphics -lsfml-window -lsfml-system tinyxml2.cpp
.\app.exe
*/

int main() {

    //Inicializa o gerenciador do jogo
    Mapa mapa1;
    mapa1.carregarMapa("cenario.tmx");

    Colisao colisao1(mapa1.getDadosMapa(), mapa1.getTileSize());

    PoderesEspeciais poderesEspeciais(colisao1);
    poderesEspeciais.inicializar(1,100,500);

    GerenciadorGeral jogo;

    sf::Clock timer;

    while (jogo.janelaAberta()) {
        sf::Time deltaTime = timer.restart(); 

        //Atualiza o jogo
        jogo.atualizar();
        poderesEspeciais.atualizar(deltaTime);

        //Desenha o jogo
        jogo.renderizar(poderesEspeciais);

    }

    return 0;
}