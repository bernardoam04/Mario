#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <SFML/Graphics.hpp>
#include "../include/Mapa.hpp"
#include "../include/Camera.hpp"
#include "../include/PoderesEspeciais.hpp"
#include "../include/Colisao.hpp"


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

        // Métodos get
        sf::Vector2f getPosicao() const;
        float getVelocidadeHorizontal() const;
        float getVelocidadeVertical() const;
        bool getEstaNoAr() const;

        // Métodos set
        void setPosicao(const sf::Vector2f& posicao);
        void setVelocidadeHorizontal(float velocidade);
        void setVelocidadeVertical(float velocidade);
        void setEstaNoAr(bool estado);


};
#endif