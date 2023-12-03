#include "../include/GerenciadorGeral.hpp"
#include "../include/GameOver.hpp"
#include "../include/Menu.hpp"
#include "../include/Jogador.hpp"

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

    //Inicializa a janela e os sons do jogo
    std::shared_ptr<sf::RenderWindow> janela = std::make_shared<sf::RenderWindow>(tela, "Mario!",sf::Style::Titlebar | sf::Style::Close);
    std::shared_ptr<SoundManager> sounds = std::make_shared<SoundManager>();
    janela->setFramerateLimit(60);

    //Inicializa 2 timers, um para contar o deltaTime, outro pra contar o tempo de jogo
    sf::Clock timer;
    sf::Clock timer2;

    sf::Time deltaTime;

    EstadoJogo estadoAtual = EstadoJogo::MENU; 

    //Carregamento da fonte principal
    sf::Font fonte;
    if (!fonte.loadFromFile("../imagens/font.ttf")) {
        exit(1);
    }
    // Inicializa as classes dos estados de jogo
    std::shared_ptr <GerenciadorGeral> jogo = std::make_shared <GerenciadorGeral> (janela, fonte, sounds);
    GameOver gameOver(janela, fonte);
    Menu menu(janela, fonte);

    while (janela->isOpen()) {
        

        sf::Event ev;

        // Calcula o tempo passado entre cada iteração
        sf::Time deltaTime = timer2.restart(); 
        
        //Menu de inicio de jogo
        if (estadoAtual == EstadoJogo::MENU) {

            // Calcula o tempo que passou desde o início do jogo
            sf::Time tempoAtual = timer.getElapsedTime();

           janela->clear(sf::Color(132, 112, 255));

           //Desenha o mapa de fundo
           jogo->desenharMapa(tempoAtual);

            bool menuAtivo = menu.atualizar(ev);  

            if(!menu.getSomAtivo()){
                jogo->desativarSom();
            }


            //Ida para o jogo
            if (menuAtivo == false) {
                timer.restart();
                estadoAtual = EstadoJogo::JOGO;
            }
            // Desenho do menu completo
            menu.desenharTela();

            janela->display();
        }

        else if (estadoAtual == EstadoJogo::JOGO) {

            // Calcula o tempo que passou desde o início do jogo
            sf::Time tempoAtual = timer.getElapsedTime();

            //Limpa a janela
            janela->clear(sf::Color(132, 112, 255));

            // Atualiza o jogo principal
            bool jogoAtivo = jogo->atualizar(tempoAtual, deltaTime, ev);

            //Ida para o game over
            if(jogoAtivo == false || jogo->getGamerOver() == true){
                estadoAtual = EstadoJogo::GAMEOVER;
            }

            //Desenha o jogo principal
            jogo->renderizar(tempoAtual);
        }

        else if (estadoAtual == EstadoJogo::GAMEOVER) {
            
            //Limpa a tela preta
            janela->clear(sf::Color::Black);

            bool jogoEmGameOver = gameOver.atualizar(ev, jogo->getViewCamera());  

            //Reinicio do jogo
            if (jogoEmGameOver == false) {
                jogo = std::make_shared <GerenciadorGeral>(janela, fonte, sounds);
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
