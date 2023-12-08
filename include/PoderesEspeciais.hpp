#ifndef PODERESESPECIAIS_HPP
#define PODERESESPECIAIS_HPP

#include <SFML/Graphics.hpp>
#include "../include/Colisao.hpp"
#include "../lib/tinyxml2.hpp"

/**
 * @brief Classe que representa os poderes especiais no jogo.
 */
class PoderesEspeciais  {
private:
    // Texturas e Posições
    std::vector<sf::Texture> cogumeloTextures; 
    std::vector<sf::Texture> estrelaTextures; 
    std::vector<sf::Texture> moedaTextures; 
    sf::Sprite poderSprite;  
    sf::Vector2f posicaoInicial; 
    sf::Vector2f posicao; 
    int tipo;

    // Constantes
    const float aceleracaoGravidadeMoeda = 40.8f;
    const float aceleracaoGravidade = 4.8f;
    static const int COGUMELO = 1; 
    static const int ESTRELA = 2; 
    static const int MOEDA = 3; 
    const float tileSize = 32;

    // Modificáveis
    float velocidadeVertical = 0.0f;
    float velocidadeHorizontal = 50.0f;
    float velocidadeInicialPulo = 1000.0f;

    // Verificações
    bool moedaColetada = false;
    bool puloIniciado = false;
    bool estaNoAr = false;
    bool movDireita = true;
    bool movEsquerda = false;
    bool existe = false;

    Colisao &colisao;

public:
    // Construtor
    /**
     * @brief Constrói um objeto PoderesEspeciais.
     * @param colisao Referência para o objeto de colisão.
     */
    PoderesEspeciais(Colisao &colisao);  

    // Carregamento
    /**
     * @brief Carrega as texturas para as moedas.
     */
    void carregarMoedas();

    /**
     * @brief Carrega as texturas para os poderes.
     */
    void carregarPoderes();

    // Métodos usados diretamente
    /**
     * @brief Gera um tipo aleatório para o poder especial.
     * @return Tipo gerado aleatoriamente.
     */
    int gerarTipoAleatorio();

    /**
     * @brief Inicializa o poder especial no mapa.
     * @param mapa Referência para o objeto de mapa.
     * @return True se a inicialização foi bem-sucedida, caso contrário, false.
     */
    bool inicializarNoMapa(Mapa& mapa);

    /**
     * @brief Inicializa as propriedades do poder especial.
     * @param x Posição inicial X.
     * @param y Posição inicial Y.
     */
    void inicializar(float x, float y);

    /**
     * @brief Desenha o poder especial na janela.
     * @param janela Referência para a janela do jogo.
     */
    void desenhar(sf::RenderWindow& janela);

    /**
     * @brief Modifica a posição do poder especial com base no tempo delta.
     * @param deltaTime Tempo decorrido desde a última atualização.
     */
    void ModificacaoPosicaoPoderes(sf::Time deltaTime);

    /**
     * @brief Modifica a posição da moeda com base no tempo delta.
     * @param deltaTime Tempo decorrido desde a última atualização.
     */
    void ModificacaoPosicaoMoeda(sf::Time deltaTime);

    /**
     * @brief Atualiza o estado do poder especial.
     * @param deltaTime Tempo decorrido desde a última atualização.
     * @param tempoAtual Tempo atual do jogo.
     */
    void atualizar(sf::Time deltaTime, sf::Time tempoAtual);

    /**
     * @brief Retorna o poder especial para a posição inicial.
     */
    void voltarPosicaoInicial();

    // Verificação
    /**
     * @brief Verifica se há colisão com o poder especial.
     * @param posicaoPersonagem Posição do personagem.
     * @param altura Altura do personagem.
     * @param largura Largura do personagem.
     * @return True se houver colisão, caso contrário, false.
     */
    bool verificarColisao(sf::Vector2f posicaoPersonagem, int altura, int largura);

    // Getters
    /**
     * @brief Obtém a posição inicial do poder especial.
     * @return Posição inicial.
     */
    sf::Vector2f getPosicaoInicial();

    /**
     * @brief Obtém o tipo do poder especial.
     * @return Tipo do poder especial.
     */
    int getTipo();

    /**
     * @brief Obtém a posição atual do poder especial.
     * @return Posição atual.
     */
    sf::Vector2f getPosicaoAtual();
};

#endif
