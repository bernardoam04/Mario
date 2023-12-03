#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include "../include/Personagem.hpp"
#include <SFML/Graphics.hpp>

class Jogador : public Personagem {
private: 
    //Atributos
    const float alturaTela;
    int contadorAndadaDir;
    int contadorAndadaEsq;
    unsigned int vida = 1;
    unsigned int alturaJogador;
    unsigned int larguraJogador;
    int moedas;

    std::shared_ptr <sf::RenderWindow> janela;

    //Texturas
    std::vector<sf::Texture> mariosDireita;
    std::vector<sf::Texture> mariosEsquerda;
    std::vector<sf::Texture> mariosPequenosEsquerda;
    std::vector<sf::Texture> mariosPequenosDireita;

    //Temporizador
    sf::Clock temporizadorInvencivel;

    //Verificações
    bool movendoDireita;
    bool movendoEsquerda;
    bool pulando;
    bool colisaoCabeca;
    bool ganhou;
    bool perdeu;
    bool ativarPoder;
    bool puloemGoomba;
    bool invencivel;
    bool pegouEstrela;
    bool subindo;

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
    bool estaInvencivel();
    bool estaSubindo();

    // Métodos para definir o estado dos movimentos
    void setMovendoDireita(bool movendo);
    void setMovendoEsquerda(bool movendo);
    void setPulando(bool pulo);
    void setPuloEmGoomba(bool pulo);
    void ficarInvencivel();
    void pegarEstrela();
    void atualizarColisao(Mapa &mapa);
};
#endif