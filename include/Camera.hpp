#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Camera {
private:
    sf::View view;
    const float velocidadeCamera = 2.3f;
public:
    //Construtor
    Camera(float largura, float altura);

    //Métodos de atualização
    void setCenter(const sf::Vector2f& center);
    void atualizarPosicao(sf::Vector2f posicaoPersonagem);

    //Getters
    float getVelocidadeCamera();
    const sf::View& getView() const;
};

#endif
