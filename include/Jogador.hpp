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

    public:
        Jogador(Colisao &colisao);
        Jogador& operator=(const Jogador& other);
        virtual ~Jogador();
        void modificarPosicao(sf::Time deltaTime, int larguraMapa) override;
};
#endif