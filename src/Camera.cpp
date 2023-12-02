#include "../include/Camera.hpp"
#include "Camera.hpp"

Camera::Camera(float largura, float altura) 
{
    view.setSize(largura, altura);
    view.setCenter(largura/2, altura/2);
}

void Camera::setCenter(const sf::Vector2f& center) {
    view.setCenter(center);
}

void Camera::atualizarPosicao(sf::Vector2f posicaoPersonagem)
{
    sf::Vector2f novaPosicao = view.getCenter();
    novaPosicao.x = posicaoPersonagem.x;
    setCenter(novaPosicao);
}

float Camera::getVelocidadeCamera()
{
    return this->velocidadeCamera;
}

const sf::View& Camera::getView() const {
    return view;
}
