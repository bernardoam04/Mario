#ifndef MENUOP_HPP
#define MENUOP_HPP
#include <SFML/Graphics.hpp>
#include "Menu.hpp"

class menuOp : public Menu {
public:
    enum opselect{
        volumemusic,
        volumeefect
    };
private:
    sf::Text volumemuTexto;
    sf::Text volumefTexto;
    sf::Text volumeMusicText;
    sf::Text volumeeffectText;    
    sf::Texture menuTexture;
    sf::Sprite menuSprite;
    opselect opcaoSelecionada;


public:
    menuOp(sf::Font& fonte1, std::shared_ptr<sf::RenderWindow> janela1);
    void desenharTela() override;
    bool atualizar(sf::Event ev) override;
    void atualizarPosicaoTextos() override;
    void atualizarOpcaoSelecionada() override;
    bool tratarCliqueMouse() override;


};

#endif