#include "../include/GerenciadorGeral.hpp"
#include "GameOver.hpp"

const float alturaTela = 640;
const float larguraTela = 640;

enum EstadoJogo {
    MENU,
    JOGO,
    GAMEOVER
};

int main() {

    //Inicializa a tela com tamanho constante
    sf::VideoMode tela;
    tela.height = alturaTela;
    tela.width = larguraTela;

    //Inicializa a janela
    std::shared_ptr<sf::RenderWindow> janela = std::make_shared<sf::RenderWindow>(tela, "Mario!");

    //Inicializa 2 timers, um para contar o deltaTime, outro pra contar o tempo de jogo
    sf::Clock timer;
    sf::Clock timer2;

    sf::Time deltaTime;

    EstadoJogo estadoAtual = EstadoJogo::JOGO; 

    //Carregamento da fonte do MENU(provavelmente vai ser trocada por imagens)
    sf::Font fonte;
    if (!fonte.loadFromFile("../imagens/font.ttf")) {
        exit(1);
    }
    // Inicializa o gerenciador do jogo    
    std::shared_ptr <GerenciadorGeral> jogo = std::make_shared <GerenciadorGeral>(janela, fonte);
    GameOver gameOver(janela, fonte);
    

    sf::Text textoMenu("Aperte qualquer tecla para ir para o jogo", fonte, 15);
    textoMenu.setFillColor(sf::Color::White);
    textoMenu.setPosition(30, 300);

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

        else if (estadoAtual == EstadoJogo::JOGO) {

            // Calcula o tempo que passou desde o início do jogo
            sf::Time tempoAtual = timer.getElapsedTime();
            
            //Limpa a janela com cor de fundo azul
            janela->clear(sf::Color::Blue);

            // Atualiza o jogo principal
            bool jogoAtivo = jogo->atualizar(tempoAtual, deltaTime, ev);

            if(jogoAtivo == false){
                estadoAtual = EstadoJogo::GAMEOVER;
            }

            //Desenha o jogo principal
            jogo->renderizar(tempoAtual);
        }

        else if (estadoAtual == EstadoJogo::GAMEOVER) {
            
            janela->clear(sf::Color::Black);

            bool jogoEmGameOver = gameOver.atualizar(ev, jogo->getViewCamera());  

            if (jogoEmGameOver == false) {
                jogo = std::make_shared <GerenciadorGeral>(janela, fonte);
                timer.restart();
                estadoAtual = EstadoJogo::JOGO;
            }

            // Desenho do Game Over
            gameOver.desenharTela(jogo->getPontuacaoTotal(),jogo->getViewCamera());

            janela->display();
        }    
    }

    return 0;
}
