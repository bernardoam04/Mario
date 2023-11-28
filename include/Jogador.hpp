#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include "../include/Personagem.hpp"
#include "Mapa.hpp"
#include "Camera.hpp"

class Jogador : public Personagem {
    private: 
        int vida;
        int moedas;
        bool ativarPoder;
        unsigned int alturaJogador;
        unsigned int larguraJogador;

    public:
        Jogador(Colisao &colisao);
        Jogador& operator=(const Jogador& other);
        virtual ~Jogador();
        void modificarPosicao(sf::Time deltaTime, int larguraMapa) override;
        bool verificarColisaoDistanciaX(float x, float y, float largura);
        bool verificarColisaoDistanciaY(float x, float y, float altura);
};
#endif