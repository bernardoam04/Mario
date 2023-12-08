#ifndef GERENCIADORGERAL_HPP
#define GERENCIADORGERAL_HPP

#include "../include/Mapa.hpp"
#include "../include/Camera.hpp"
#include "../include/Colisao.hpp"
#include "../include/PoderesEspeciais.hpp"
#include "../include/Pontuacao.hpp"
#include "../include/SoundManager.hpp"
#include "Jogador.hpp"
#include "Goomba.hpp"
#include <set>

/**
 * @brief Classe que gerencia o estado geral do jogo.
 */
class GerenciadorGeral {
private:
    // Informações da tela (mesma do main)
    const float alturaTela = 640;
    const float larguraTela = 640;

    // Tipos Abstratos
    std::shared_ptr<sf::RenderWindow> janela;
    std::shared_ptr<Pontuacao> pontuacao;
    Mapa mapa;
    std::shared_ptr<Camera> camera;
    std::shared_ptr<Colisao> colisao;
    std::vector<std::shared_ptr<PoderesEspeciais>> vetorPoderesEspeciais;
    std::vector<std::shared_ptr<Goomba>> goombas;
    std::shared_ptr<SoundManager> _sounds;
    std::shared_ptr<Jogador> mario;
    std::set<unsigned int> indicesComColisao;
    std::set<unsigned int> indicesPoderesEspeciais;
    std::shared_ptr<Goomba> goomba;

    // Textos da pontuação
    sf::Text textoMaisCem;
    sf::Text textoMaisMil;
    sf::Text textoGanhou;
    sf::Clock temporizadorTexto;
    sf::Time duracaoTexto = sf::seconds(0.5f);

    // Métodos privados
    void inicializarVariaveis();
    void InicializarGoombas();
    void inicializarTextos(sf::Font &fonte);
    void atualizarPosicaoTexto(sf::Text &texto);

    // Verificações
    bool puloHabilitado;
    bool gameOver;
    bool somAtivo = true;
    std::vector<int> contagemDesenhoPoderes;

    // Contador
    int contadorPerdeu = 0;
    int contadorInvencivel;
    int contagemMoedasMisteriosas = 0;

public:    

    // Construtor e Destrutor
    /**
     * @brief Constrói um objeto GerenciadorGeral.
     * @param janela1 Ponteiro compartilhado para a janela do jogo.
     * @param fonte Fonte utilizada para os textos no jogo.
     * @param sounds Gerenciador de som.
     */
    GerenciadorGeral(std::shared_ptr<sf::RenderWindow> janela1, sf::Font &fonte, std::shared_ptr<SoundManager> sounds);

    // Métodos de Verificação
    /**
     * @brief Verifica se há colisão em uma posição específica.
     * @param x Coordenada X.
     * @param y Coordenada Y.
     * @return Índice da colisão se houver, caso contrário, -1.
     */
    int verificarColisao(float x, float y) const;

    /**
     * @brief Verifica se a janela do jogo está aberta.
     * @return True se a janela estiver aberta, caso contrário, false.
     */
    bool janelaAberta() const;

    // Métodos utilizados no jogo diretamente
    /**
     * @brief Inicializa os poderes especiais no jogo.
     */
    void InicializarPoderesEspeciais();

    /**
     * @brief Atualiza o estado do jogo.
     * @param tempoAtual Tempo atual do jogo.
     * @param deltaTime Tempo decorrido desde a última atualização.
     * @param ev Evento do SFML para tratar eventos de entrada.
     * @return True se o jogo deve continuar, caso contrário, false.
     */
    bool atualizar(sf::Time tempoAtual, sf::Time deltaTime, sf::Event ev);

    /**
     * @brief Atualiza os eventos do jogo.
     * @param ev Evento do SFML para tratar eventos de entrada.
     * @return True se um evento foi tratado, caso contrário, false.
     */
    bool atualizarEventos(sf::Event ev);

    /**
     * @brief Renderiza o estado atual do jogo.
     * @param tempoAtual Tempo atual do jogo.
     */
    void renderizar(sf::Time tempoAtual);

    /**
     * @brief Desenha os poderes especiais na janela.
     */
    void desenharPoderesEspeciais();

    /**
     * @brief Desenha o mapa na janela.
     * @param tempoAtual Tempo atual do jogo.
     */
    void desenharMapa(sf::Time tempoAtual);

    /**
     * @brief Desativa o som no jogo.
     */
    void desativarSom();

    /**
     * @brief Ativa o som no jogo.
     */
    void ativarSom();

    //Getters
    float getAlturaTela() const;
    float getLarguraTela() const;
    int getPontuacaoTotal() const;
    const sf::View& getViewCamera() const;
    bool getGamerOver();
    std::shared_ptr<Jogador> getMario() const;
    int getContagemPoderesEspeciais() const;

};

#endif
