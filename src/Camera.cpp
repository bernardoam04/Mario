#include "../include/Camera.hpp"
#include "Camera.hpp"

Camera::Camera(float largura, float altura) {
    try {
        view.setSize(largura, altura);
        view.setCenter(largura / 2, altura / 2);
    } catch (const std::out_of_range& e) {
        std::cerr << "Erro ao inicializar a câmera: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        // Captura exceções gerais que não são std::out_of_range
        std::cerr << "Erro ao inicializar a câmera: " << e.what() << std::endl;
    }
}

void Camera::setCenter(const sf::Vector2f& center) {
    try {
        view.setCenter(center);
    } catch (const std::out_of_range& e) {
        std::cerr << "Erro ao definir o centro da câmera: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro ao definir o centro da câmera: " << e.what() << std::endl;
    }
}

void Camera::atualizarPosicao(sf::Vector2f posicaoPersonagem) {
    try {
        sf::Vector2f novaPosicao = view.getCenter();
        novaPosicao.x = posicaoPersonagem.x;
        setCenter(novaPosicao);
    } catch (const std::out_of_range& e) {
        std::cerr << "Erro ao atualizar a posição da câmera: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro ao atualizar a posição da câmera: " << e.what() << std::endl;
    }
}

float Camera::getVelocidadeCamera() {
    return this->velocidadeCamera;
}

const sf::View& Camera::getView() const {
    return view;
}
