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
        sf::Vector2f posicaoPersonagem; 
        float velocidadeVertical;
        float velocidadeHorizontal;
        //Verificacoes
        //bool vivo; (Nao esta sendo utilizado ainda)
        bool estaNoAr;
        bool movEsquerda;
        bool movDireita;

        //Constantes
        const float tileSize=32;
        const float aceleracaoGravidade = 10.0f;
        const float alturaChao = 640.0 - 156.0;

    protected:
        sf::Sprite personagemSprite;
        sf::Texture personagemTexture;
        Colisao &colisao;

    public:

        Personagem(Colisao &colisao);
        //virtual void desenharPersonagem(sf::Vector2f posicao, sf::RenderWindow janela);
        virtual void modificarPosicao(sf::Time deltaTime, int larguraMapa);
        

        // Métodos get
        sf::Vector2f getPosicao() const;
        float getVelocidadeHorizontal() const;
        float getVelocidadeVertical() const;
        float getAceleracaoGravidade() const;
        bool getMovEsquerda() const;
        bool getMovDireita() const;
        float getAlturaChao() const;
        bool getEstaNoAr() const;
        float getTileSize() const;
        sf::Texture getTexture() const;

        // Métodos set
        void setPosicaoPersonagem(const sf::Vector2f& posicao);
        void setVelocidadeHorizontal(float velocidade);
        void setVelocidadeVertical(float velocidade);
        void setMovEsquerda(bool movimento);
        void setMovDireita(bool movimento);
        void setEstaNoAr(bool estado);

};
#endif