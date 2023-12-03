#ifndef GOOMBA_HPP
#define GOOMBA_HPP
#include <SFML/Graphics.hpp>
#include "Personagem.hpp"
#include "Jogador.hpp"

class Goomba : public Personagem {
private:
    std::shared_ptr <sf::RenderWindow> janela;//Talvez colocar como protected em personagem para evitar repeticao
    int alturaGoomba;
    int larguraGoomba;

    //Temporizador
    sf::Clock temporizadorMorte;
public:
    //Construtor
    Goomba(Colisao &colisao, std::shared_ptr <sf::RenderWindow> janela1, float x, float y);

    //Destrutor virtual
    virtual ~Goomba();

    //Métodos de uso direto
    void inicializarGoombas();//Controlar o aparecimento de Goombas
    void atacar(std::shared_ptr <Jogador> mario);
    void modificarPosicao(sf::Time deltaTime, int larguraMapa) override;
    void morrer();
    void desenharGoomba();

    //Métodos de verificacao
    bool verificarColisao();
    bool verificarColisaoDistanciaX(float x, float y, float largura);
    bool verificarColisaoDistanciaY(float x, float y, float altura);
    bool verificarColisaoComGoomba(std::shared_ptr <Jogador> mario);
    bool verificarColisaoLateralComGoomba(std::shared_ptr <Jogador> mario);
    bool verificarColisaoLateralComGoombaDireita(std::shared_ptr <Jogador> mario);
    bool verificarColisaoLateralComGoombaEsquerda(std::shared_ptr <Jogador> mario);
        
};

#endif