#include "GerenciadorGeral.hpp"

/*
g++ -Wall -Wextra -Werror main.cpp GerenciadorGeral.cpp Mapa.cpp PoderesEspeciais.cpp Camera.cpp Colisao.cpp -o app.exe -lsfml-graphics -lsfml-window -lsfml-system tinyxml2.cpp
.\app.exe
*/

int main() {
    
    //Inicializa o gerenciador do jogo
    Mapa mapa;
    mapa.carregarMapa("cenario.tmx");

    Colisao colisao(mapa.getDadosMapa(), mapa.getTileSize());

    PoderesEspeciais poderesEspeciais(colisao);
    poderesEspeciais.inicializar(1,512,100);

    GerenciadorGeral jogo;

    sf::Clock timer;

    while (jogo.janelaAberta()) {
        sf::Time deltaTime = timer.restart(); 
        std::cout<<deltaTime.asSeconds()<<std::endl;
        //Atualiza o jogo
        jogo.atualizar();
        poderesEspeciais.atualizar(deltaTime);

        //Desenha o jogo
        jogo.renderizar(poderesEspeciais);

    }
    return 0;
}