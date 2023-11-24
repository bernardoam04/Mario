#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <SFML/Graphics.hpp>
#include "Mapa.hpp"
#include "Camera.hpp"
#include "PoderesEspeciais.hpp"
#include "Colisao.hpp"


class Personagem {
    private:
        //Texturas, Posicao e modificadores
        sf::Sprite personagemSprite;  
        sf::Vector2f posicaoPersonagem; 
        float velocidadeVertical;
        float velocidadeHorizontal;

        //Verificacoes
        //bool vivo; Nao esta sendo utilizado ainda
        bool estaNoAr;

        //Colisao
        //Colisao &colisao;

    public:

        virtual void inicializarPersonagem(float x, float y);
        virtual void desenharPersonagem(sf::RenderWindow& janela);
        virtual void modificarPosicao(sf::Time deltaTime);


};
#endif