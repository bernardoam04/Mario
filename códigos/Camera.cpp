#include "Camera.hpp"

Camera::Camera(float largura, float altura) {
    // Configuração inicial da câmera (pode ser ajustada conforme necessário)
    view.setSize(largura, altura);
    view.setCenter(largura/2, altura/2);
}

void Camera::setCenter(const sf::Vector2f& center) {
    view.setCenter(center);
}

float Camera::getVelocidadeCamera()
{
    return this->velocidadeCamera;
}

const sf::View& Camera::getView() const {
    return view;
}
