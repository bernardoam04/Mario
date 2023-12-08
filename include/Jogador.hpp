#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "../include/Personagem.hpp"
#include <SFML/Graphics.hpp>

/**
 * @brief Representa o personagem jogador no jogo.
 */
class Jogador : public Personagem {
private:
    // Atributos
    const float alturaTela; ///< Altura da tela.
    int contadorAndadaDir;
    int contadorAndadaEsq;
    unsigned int vida = 1; ///< Contagem de vidas do jogador.
    unsigned int alturaJogador;
    unsigned int larguraJogador;
    int moedas;

    std::shared_ptr<sf::RenderWindow> janela; ///< Ponteiro para a janela do jogo.

    // Texturas
    std::vector<sf::Texture> mariosDireita;
    std::vector<sf::Texture> mariosEsquerda;
    std::vector<sf::Texture> mariosPequenosEsquerda;
    std::vector<sf::Texture> mariosPequenosDireita;

    // Temporizador
    sf::Clock temporizadorInvencivel;

    // Verificações
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
    // Construtor
    /**
     * @brief Constrói um objeto Jogador.
     * @param colisao Referência para o objeto de colisão.
     * @param larguraTela Largura da tela.
     * @param alturaTelaJogo Altura da tela do jogo.
     * @param janela1 Ponteiro compartilhado para a janela do jogo.
     */
    Jogador(Colisao& colisao, const float larguraTela, const float alturaTelaJogo, std::shared_ptr<sf::RenderWindow> janela1);

    /**
     * @brief Operador de atribuição por cópia.
     * @param other Outro objeto Jogador para copiar.
     * @return Referência para o objeto Jogador atribuído.
     */
    Jogador& operator=(const Jogador& other);

    // Inicialização
    /**
     * @brief Inicializa atributos booleanos.
     */
    void inicializarBooleanos();

    // Destrutor
    /**
     * @brief Destrói o objeto Jogador.
     */
    virtual ~Jogador();

    // Métodos Aplicados Diretamente
    /**
     * @brief Dobra a altura do personagem jogador.
     */
    void dobrarAltura();

    /**
     * @brief Modifica a posição do personagem jogador com base no tempo delta e na largura do mapa.
     * @param deltaTime Tempo decorrido desde a última atualização.
     * @param larguraMapa Largura do mapa do jogo.
     */
    void modificarPosicao(sf::Time deltaTime, int larguraMapa) override;

    /**
     * @brief Desenha o personagem jogador na tela.
     */
    void desenhar();

    /**
     * @brief Diminui a contagem de vidas do jogador.
     */
    void perderVida();

    /**
     * @brief Altera a textura do personagem jogador ao perder o jogo.
     */
    void perdeuMudarTextura();

    // Métodos de Verificação
    /**
     * @brief Verifica se o personagem jogador está se movendo para a direita.
     * @return True se estiver se movendo para a direita, caso contrário, false.
     */
    bool estaMovendoDireita() const { return movendoDireita; }

    /**
     * @brief Verifica se o personagem jogador está se movendo para a esquerda.
     * @return True se estiver se movendo para a esquerda, caso contrário, false.
     */
    bool estaMovendoEsquerda() const { return movendoEsquerda; }

    /**
     * @brief Verifica se o personagem jogador está pulando.
     * @return True se estiver pulando, caso contrário, false.
     */
    bool estaPulando() const { return pulando; }

    /**
     * @brief Verifica colisão no eixo X dentro de uma distância especificada.
     * @param x Coordenada X do objeto a ser verificado.
     * @param y Coordenada Y do objeto a ser verificado.
     * @param largura Largura do objeto a ser verificado.
     * @return True se uma colisão for detectada, caso contrário, false.
     */
    bool verificarColisaoDistanciaX(float x, float y, float largura);

    /**
     * @brief Verifica colisão no eixo Y dentro de uma distância especificada.
     * @param x Coordenada X do objeto a ser verificado.
     * @param y Coordenada Y do objeto a ser verificado.
     * @param altura Altura do objeto a ser verificado.
     * @return True se uma colisão for detectada, caso contrário, false.
     */
    bool verificarColisaoDistanciaY(float x, float y, float altura);

    // Getters
    /**
     * @brief Obtém a largura do personagem jogador.
     * @return Largura do personagem jogador.
     */
    int getLarguraJogador();

    /**
     * @brief Obtém a altura do personagem jogador.
     * @return Altura do personagem jogador.
     */
    int getAlturaJogador();

    /**
     * @brief Verifica se o personagem jogador venceu o jogo.
     * @return True se o personagem jogador venceu, caso contrário, false.
     */
    bool getGanhou();

    /**
     * @brief Verifica se o personagem jogador perdeu o jogo.
     * @return True se o personagem jogador perdeu, caso contrário, false.
     */
    bool getPerdeu();

    /**
     * @brief Verifica se o personagem jogador está invencível.
     * @return True se estiver invencível, caso contrário, false.
     */
    bool estaInvencivel();

    /**
     * @brief Verifica se o personagem jogador está se movendo para cima.
     * @return True se estiver se movendo para cima, caso contrário, false.
     */
    bool estaSubindo();

    /**
     * @brief Obtém a contagem atual de vidas do personagem jogador.
     * @return Contagem atual de vidas.
     */

    // Métodos para definir o estado dos movimentos
    void setMovendoDireita(bool movendo);
    void setMovendoEsquerda(bool movendo);
    void setPulando(bool pulo);
    void setPuloEmGoomba(bool pulo);
    void ficarInvencivel();
    void pegarEstrela();
    void atualizarColisao(Mapa &mapa);
    void setPosicao(float x, float y);
};
#endif