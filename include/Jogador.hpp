#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include "Personagem.hpp"

class Jogador : public Personagem {
    private: 
        sf::Texture jogadorTexture;
        //int vida;
        //int moedas;
        //bool ativarPoder;

    public:
        Jogador();
        void modificarPosicao(sf::Time deltaTime) override;

};
#endif