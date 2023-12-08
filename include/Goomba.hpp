#ifndef GOOMBA_HPP
#define GOOMBA_HPP

#include <SFML/Graphics.hpp>
#include "Personagem.hpp"
#include "Jogador.hpp"

/**
 * @brief Representa a classe Goomba, um inimigo no jogo.
 */
class Goomba : public Personagem {
private:
    std::shared_ptr<sf::RenderWindow> janela; ///< Ponteiro compartilhado para a janela do jogo.
    int alturaGoomba;
    int larguraGoomba;

    // Temporizador
    sf::Clock temporizadorMorte;

public:
    // Construtor
    /**
     * @brief Constrói um objeto Goomba.
     * @param colisao Referência para o objeto de colisão.
     * @param janela1 Ponteiro compartilhado para a janela do jogo.
     * @param x Posição inicial X do Goomba.
     * @param y Posição inicial Y do Goomba.
     */
    Goomba(Colisao& colisao, std::shared_ptr<sf::RenderWindow> janela1, float x, float y);

    // Destrutor virtual
    /**
     * @brief Destrói o objeto Goomba.
     */
    virtual ~Goomba();

    // Métodos de Uso Direto
    /**
     * @brief Inicializa os Goombas, controlando o aparecimento.
     */
    void inicializarGoombas();

    /**
     * @brief Ataca o jogador.
     * @param mario Ponteiro compartilhado para o jogador.
     */
    void atacar(std::shared_ptr<Jogador> mario);

    /**
     * @brief Modifica a posição do Goomba com base no tempo delta e na largura do mapa.
     * @param deltaTime Tempo decorrido desde a última atualização.
     * @param larguraMapa Largura do mapa do jogo.
     */
    void modificarPosicao(sf::Time deltaTime, int larguraMapa) override;

    /**
     * @brief Faz o Goomba morrer.
     */
    void morrer();

    /**
     * @brief Desenha o Goomba na tela.
     * @param x Posição X para desenhar o Goomba.
     */
    void desenharGoomba(float x);

    // Métodos de Verificação
    /**
     * @brief Verifica a colisão do Goomba.
     * @return True se houver colisão, caso contrário, false.
     */
    bool verificarColisao();

    /**
     * @brief Verifica a colisão no eixo X dentro de uma distância especificada.
     * @param x Coordenada X do objeto a ser verificado.
     * @param y Coordenada Y do objeto a ser verificado.
     * @param largura Largura do objeto a ser verificado.
     * @return True se houver colisão, caso contrário, false.
     */
    bool verificarColisaoDistanciaX(float x, float y, float largura);

    /**
     * @brief Verifica a colisão no eixo Y dentro de uma distância especificada.
     * @param x Coordenada X do objeto a ser verificado.
     * @param y Coordenada Y do objeto a ser verificado.
     * @param altura Altura do objeto a ser verificado.
     * @return True se houver colisão, caso contrário, false.
     */
    bool verificarColisaoDistanciaY(float x, float y, float altura);

    /**
     * @brief Verifica a colisão do Goomba com o jogador.
     * @param mario Ponteiro compartilhado para o jogador.
     * @return True se houver colisão, caso contrário, false.
     */
    bool verificarColisaoComGoomba(std::shared_ptr<Jogador> mario);

    /**
     * @brief Verifica a colisão lateral do Goomba com o jogador.
     * @param mario Ponteiro compartilhado para o jogador.
     * @return True se houver colisão lateral, caso contrário, false.
     */
    bool verificarColisaoLateralComGoomba(std::shared_ptr<Jogador> mario);

    /**
     * @brief Verifica a colisão lateral direita do Goomba com o jogador.
     * @param mario Ponteiro compartilhado para o jogador.
     * @return True se houver colisão lateral direita, caso contrário, false.
     */
    bool verificarColisaoLateralComGoombaDireita(std::shared_ptr<Jogador> mario);

    /**
     * @brief Verifica a colisão lateral esquerda do Goomba com o jogador.
     * @param mario Ponteiro compartilhado para o jogador.
     * @return True se houver colisão lateral esquerda, caso contrário, false.
     */
    bool verificarColisaoLateralComGoombaEsquerda(std::shared_ptr<Jogador> mario);

};

#endif
