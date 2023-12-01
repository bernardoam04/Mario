#ifndef TARTARUGA_HPP
#define TARTARUGA_HPP
#include <SFML/Graphics.hpp>
#include "Personagem.hpp"

class Tartaruga : public Personagem {
    private:
        std::shared_ptr <sf::RenderWindow> janela;//Talvez colocar como protected em personagem para evitar repeticao

    public:
        //Construtor
        Tartaruga(Colisao &colisao, std::shared_ptr <sf::RenderWindow> janela1);

        //Destrutor virtual
        virtual ~Tartaruga();

        //Métodos de uso direto
        void inicializarTartarugas();//Controlar o aparecimento de tartarugas
        void atacar();
        void modificarPosicao(sf::Time deltaTime, int larguraMapa) override;
        void morrer();
        void desenharTartaruga();


        //Métodos de verificacao
        bool verificarColisao();
        bool verificarColisaoDistanciaX(float x, float y, float altura);
        
};

#endif