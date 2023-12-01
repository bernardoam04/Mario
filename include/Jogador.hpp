    #ifndef JOGADOR_HPP
    #define JOGADOR_HPP
    #include "../include/Personagem.hpp"
    #include <SFML/Graphics.hpp>

    class Jogador : public Personagem {
    private: 
        unsigned int vida = 1;
        int moedas;
        bool ativarPoder;
        unsigned int alturaJogador;
        unsigned int larguraJogador;
        std::shared_ptr <sf::RenderWindow> janela;
        const float alturaTela;
        int contadorAndadaDir;
        int contadorAndadaEsq;
        std::vector<sf::Texture> mariosDireita;
        std::vector<sf::Texture> mariosEsquerda;

        //Verificações
        bool movendoDireita;
        bool movendoEsquerda;
        bool pulando;
        bool colisaoCabeca;
        bool ganhou;
        bool perdeu;

    public:
        //Construtor
        Jogador(Colisao &colisao, const float larguraTela, const float alturaTelaJogo, std::shared_ptr <sf::RenderWindow> janela1);
        Jogador& operator=(const Jogador& other);

        //Inicialização
        void inicializarBooleanos();
        
        //Destrutor
        virtual ~Jogador();

        //Métodos diretamente aplicados
        void dobrarAltura();
        void modificarPosicao(sf::Time deltaTime, int larguraMapa) override;
        void desenhar();
        void perderVida();
        void perdeuMudarTextura();

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
        bool getPerdeu();

        //Setters
        void setPerdeu(bool estado);

        // Métodos para definir o estado dos movimentos
        void setMovendoDireita(bool movendo);
        void setMovendoEsquerda(bool movendo);
        void setPulando(bool pulo);
        void atualizarColisao(Mapa &mapa);
    };
    #endif