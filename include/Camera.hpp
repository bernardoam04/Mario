#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * @brief Classe que representa a Câmera visualizada pelo jogador
*/

class Camera {
private:
    sf::View view; ///< Objeto view do SFML que representa a vista da câmera.
    sf::Vector2f centro; ///< Vetor que armazena a posição central da câmera.
    const float velocidadeCamera = 2.3f; ///< Velocidade que a câmera se movimenta.

public:
    /**
     * @brief Construtor da classe Câmera
     * @param largura Largura da câmera da janela de visualização
     * @param altura Altura da câmera da janela de visualização
    */
    Camera(float largura, float altura);

    //Métodos de atualização
    /** @brief Define o centro da câmera
    * @param center Vetor que representará a posição central
    */
    void setCenter(const sf::Vector2f& center);

    /** @brief Atualiza a posição da câmera com base na posição do personagem
    * @param posicaoPersonagem Vetor com a posição que o personagem se encontra
    */
    void atualizarPosicao(sf::Vector2f posicaoPersonagem);

    //Getters
    /** @brief Obtém a velocidade da câmera
    * @return Velocidade atual da câmera
    */
    float getVelocidadeCamera();

    /** @brief Obtém a visualização da câmera
    * @return Objeto do SFML contendo a view da câmera
    */ 
    const sf::View& getView() const;

    /** @brief Obtém o centro da câmera
     * @return Vetor bidimensional contendo a posição central da câmera
    */
    sf::Vector2f getCenter();
};

#endif
