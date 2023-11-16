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

void Camera::movimentarCameraDireita(int larguraMapa, int larguraTela )
{
    sf::Vector2f novaPosicao = getView().getCenter();

    if(novaPosicao.x < larguraMapa - larguraTela / 2){
        novaPosicao.x += velocidadeCamera;
        setCenter(novaPosicao);
    }
}

void Camera::movimentarCameraEsquerda(int larguraTela)
{
    sf::Vector2f novaPosicao = getView().getCenter();
    if(novaPosicao.x > larguraTela / 2){
        novaPosicao.x -= velocidadeCamera;
        setCenter(novaPosicao);
    }
}

const sf::View& Camera::getView() const {
    return view;
}
