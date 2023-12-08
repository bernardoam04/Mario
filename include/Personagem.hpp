#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <SFML/Graphics.hpp>
#include "../include/Mapa.hpp"
#include "../include/Camera.hpp"
#include "../include/PoderesEspeciais.hpp"
#include "../include/Colisao.hpp"

/**
 * @brief Classe base que representa um personagem no jogo (interface).
 */
class Personagem {
private:
    // Texturas, Posição e Modificadores
    sf::Vector2f posicaoPersonagem; 
    float velocidadeVertical;
    float velocidadeHorizontal;
    unsigned int alturaPersonagem;
    unsigned int larguraPersonagem;

    // Verificações
    bool vivo = true;
    bool estaNoAr;
    bool movEsquerda;
    bool movDireita;

    // Constantes
    const float tileSize = 32;
    const float aceleracaoGravidade = 10.0f;
    const float alturaChao = 640.0 - 64.0;

protected:
    sf::Sprite personagemSprite;
    sf::Sprite personagemMorreuSprite;
    sf::Texture personagemTexture;
    sf::Texture personagemMorreuTexture;
    Colisao &colisao;

public:
    // Construtor
    /**
     * @brief Constrói um objeto da classe Personagem.
     * @param colisao Referência para o objeto de colisão.
     */
    Personagem(Colisao &colisao);

    /**
     * @brief Modifica a posição do personagem com base no tempo delta e na largura do mapa.
     * @param deltaTime Tempo decorrido desde a última atualização.
     * @param larguraMapa Largura do mapa do jogo.
     */
    virtual void modificarPosicao(sf::Time deltaTime, int larguraMapa);

    /**
     * @brief Carrega uma textura a partir de um arquivo.
     * @param filename Nome do arquivo da textura.
     * @return Textura carregada.
     */
    sf::Texture loadTexture(const std::string& filename);
    
    //Getters
    sf::Vector2f getPosicao() const;
    float getVelocidadeHorizontal() const;
    float getVelocidadeVertical() const;
    float getAceleracaoGravidade() const;
    bool getMovEsquerda() const;
    bool getMovDireita() const;
    float getAlturaChao() const;
    bool getEstaNoAr() const;
    float getTileSize() const;
    bool getVivo() const;
    sf::Texture getTexture() const;
    unsigned int getAlturaPersonagem() const;
    unsigned int getLarguraPersonagem() const;

    //Setters
    void setPosicaoPersonagem(const sf::Vector2f& posicao);
    void setVelocidadeHorizontal(float velocidade);
    void setVelocidadeVertical(float velocidade);
    void setMovEsquerda(bool movimento);
    void setMovDireita(bool movimento);
    void setEstaNoAr(bool estado);
    void setVivo(bool vivoAtual);
    void setAlturaPersonagem(unsigned int altura);
    void setLarguraPersonagem(unsigned int largura);

};
#endif