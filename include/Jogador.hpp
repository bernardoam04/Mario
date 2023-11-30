    #ifndef JOGADOR_HPP
    #define JOGADOR_HPP
    #include "../include/Personagem.hpp"
    #include <SFML/Graphics.hpp>

    class Jogador : public Personagem {
    private: 
        int vida = 1;
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
        bool ganhou = false;

    public:
        //Construtor
        Jogador(Colisao &colisao, const float larguraTela,std::shared_ptr <sf::RenderWindow> janela1);
        Jogador& operator=(const Jogador& other);
        
        //Destrutor
        virtual ~Jogador();

        //Métodos diretamente aplicados
        void dobrarAltura();
        void modificarPosicao(sf::Time deltaTime, int larguraMapa) override;
        void desenhar();

        // Métodos de verificação
        bool estaMovendoDireita() const { return movendoDireita; }
        bool estaMovendoEsquerda() const { return movendoEsquerda; }
        bool estaPulando() const { return pulando; }
        bool verificarColisaoDistanciaX(float x, float y, float largura);
        bool verificarColisaoDistanciaY(float x, float y, float altura);

        //Getters
        int getLarguraJogador();
        int getAlturaJogador();
        bool getGanhou();

        // Métodos para definir o estado dos movimentos
        void setMovendoDireita(bool movendo);
        void setMovendoEsquerda(bool movendo);
        void setPulando(bool pulo);
        void atualizarColisao(Mapa &mapa);
    };
    #endif