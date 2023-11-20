#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/Graphics.hpp>

class Camera {
private:
    sf::View view;
    const float velocidadeCamera = 5.0f;
public:
    Camera(float largura, float altura);
    // Configure a posição central da câmera
    void setCenter(const sf::Vector2f& center);

    float getVelocidadeCamera();

    void movimentarCameraDireita(int larguraMapa, int larguraTela);
    void movimentarCameraEsquerda(int larguraTela);

    // Obtenha a visão da câmera
    const sf::View& getView() const;
};

#endif
