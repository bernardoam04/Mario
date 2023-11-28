    #ifndef JOGADOR_HPP
    #define JOGADOR_HPP
    #include "../include/Personagem.hpp"

    class Jogador : public Personagem {
    private: 
        int vida;
        int moedas;
        bool ativarPoder;
        unsigned int alturaJogador;
        unsigned int larguraJogador;

        //Verificações
        bool movendoDireita;
        bool movendoEsquerda;
        bool pulando;
        bool colisaoCabeca = false;

    public:
        Jogador(Colisao &colisao);
        Jogador& operator=(const Jogador& other);
        virtual ~Jogador();
        void modificarPosicao(sf::Time deltaTime, int larguraMapa) override;
        bool verificarColisaoDistanciaX(float x, float y, float largura);
        bool verificarColisaoDistanciaY(float x, float y, float altura);

        // Métodos para obter o estado dos movimentos
        bool estaMovendoDireita() const { return movendoDireita; }
        bool estaMovendoEsquerda() const { return movendoEsquerda; }
        bool estaPulando() const { return pulando; }

        //Getters
        int getLarguraJogador();


        // Métodos para definir o estado dos movimentos
        void setMovendoDireita(bool movendo);
        void setMovendoEsquerda(bool movendo);
        void setPulando(bool pulo);
        void atualizarColisao(Mapa &mapa);
    };
    #endif