#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/Graphics.hpp>

class Camera {
private:
    sf::View view;
    const float velocidadeCamera = 5.0f;
public:
    //Construtor
    Camera(float largura, float altura);

    //Métodos de atualização
    void movimentarCameraDireita(int larguraMapa, int larguraTela);
    void movimentarCameraEsquerda(int larguraTela);
    void setCenter(const sf::Vector2f& center);

    //Getters
    float getVelocidadeCamera();
    const sf::View& getView() const;
};

#endif
