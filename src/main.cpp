#include "../include/GerenciadorGeral.hpp"

const float alturaTela = 640;
const float larguraTela = 640;

enum EstadoJogo {
    MENU,
    JOGO
};

int main() {

    //Inicializa a tela com tamanho constante
    sf::VideoMode tela;
    tela.height = alturaTela;
    tela.width = larguraTela;

    //Inicializa a janela
    sf::RenderWindow* janela = new sf::RenderWindow(tela, "Mario!");

    // Inicializa o gerenciador do jogo    
    GerenciadorGeral jogo(janela);

    //Inicializa 2 timers, um para contar o deltaTime, outro pra contar o tempo de jogo
    sf::Clock timer;
    sf::Clock timer2;

    sf::Time deltaTime;

    EstadoJogo estadoAtual = EstadoJogo::MENU; 

    //Carregamento da fonte do MENU(provavelmente vai ser trocada por imagens)
    sf::Font fonte;
    if (!fonte.loadFromFile("../imagens/arial.ttf")) {
        exit(1);
    }
    sf::Text textoMenu("Aperte qualquer tecla para ir para o jogo", fonte, 20);
    textoMenu.setFillColor(sf::Color::White);
    textoMenu.setPosition(100, 300);
    //Fim do texto do carregamento do texto do


    while (janela->isOpen()) {

        sf::Event ev;

        // Calcula o tempo passado entre cada iteração
        sf::Time deltaTime = timer2.restart(); 
        
        //IMPLEMENTAR MENU NESSE IF
        if (estadoAtual == EstadoJogo::MENU) {
            while (janela->pollEvent(ev)) {
                if (ev.type == sf::Event::Closed) {
                    janela->close();
                }
                if (ev.type == sf::Event::KeyPressed) {
                    timer.restart();
                    estadoAtual = EstadoJogo::JOGO;
                }
            }
        janela->clear(sf::Color::Blue);

        // Desenho do texto do menu inicial
        janela->draw(textoMenu);

        janela->display();
        }
        //MENU ACABA AQUI

        if (estadoAtual == EstadoJogo::JOGO) {

            // Calcula o tempo que passou desde o início do jogo
            sf::Time tempoAtual = timer.getElapsedTime();
            
            //Limpa a janela com cor de fundo azul
            janela->clear(sf::Color::Blue);

            // Atualiza o jogo principal
            jogo.atualizar(tempoAtual, deltaTime, ev);

            //Desenha o jogo principal
            jogo.renderizar(tempoAtual);
        }    
    }
    
    delete janela;
    return 0;
}
