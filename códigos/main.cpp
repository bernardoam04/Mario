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

    std::cout<< colisao1.verificarColisao(3,3)<<std::endl;
    std::cout<< colisao1.verificarColisao(208,560)<<std::endl;
    std::cout<< colisao1.verificarColisao(208,637)<<std::endl;
    std::cout<< colisao1.verificarColisao(34,637)<<std::endl;
    std::cout<< colisao1.verificarColisao(208,560)<<std::endl;

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