    #ifndef JOGADOR_HPP
    #define JOGADOR_HPP
    #include "../include/Personagem.hpp"
    #include <SFML/Graphics.hpp>

    class Jogador : public Personagem {
    private: 
        int vida;
        int moedas;
        bool ativarPoder;
        unsigned int alturaJogador;
        unsigned int larguraJogador;
        std::shared_ptr <sf::RenderWindow> janela;



        //Verificações
        bool movendoDireita;
        bool movendoEsquerda;
        bool pulando;
        bool colisaoCabeca = false;

    public:
        Jogador(Colisao &colisao, const float larguraTela,std::shared_ptr <sf::RenderWindow> janela1);
        Jogador& operator=(const Jogador& other);
        virtual ~Jogador();
        void modificarPosicao(sf::Time deltaTime, int larguraMapa) override;
        bool verificarColisaoDistanciaX(float x, float y, float largura);
        bool verificarColisaoDistanciaY(float x, float y, float altura);
        void desenhar();

        // Métodos para obter o estado dos movimentos
        bool estaMovendoDireita() const { return movendoDireita; }
        bool estaMovendoEsquerda() const { return movendoEsquerda; }
        bool estaPulando() const { return pulando; }

        //Getters
        int getLarguraJogador();
        int getAlturaJogador();

        // Métodos para definir o estado dos movimentos
        void setMovendoDireita(bool movendo);
        void setMovendoEsquerda(bool movendo);
        void setPulando(bool pulo);
        void atualizarColisao(Mapa &mapa);
    };
    #endif