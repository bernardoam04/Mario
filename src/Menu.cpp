#include "../include/Menu.hpp"
#include <iostream>
#include "Menu.hpp"

Menu::Menu(std::shared_ptr<sf::RenderWindow> janela1, sf::Font &fonte)
: iniciarJogoTexto("Iniciar Jogo", fonte, 30), sairTexto("Sair", fonte, 22), opcaoSelecionada(NenhumaSelecao), janela(janela1) 
{
    somAtivo = true;
    menuTexture.loadFromFile("../imagens/placaMenu.png");
    semSomTexture.loadFromFile("../imagens/semSom.png");

    menuSprite.setTexture(menuTexture);
    semSomSprite.setTexture(semSomTexture);
    ajustarPosicaoMenu();

    iniciarJogoTexto.setFillColor(sf::Color::White);
    opcoesTexto.setFillColor(sf::Color::White);
    sairTexto.setFillColor(sf::Color::White);

    ajustarPosicaoTextos();
}

void Menu::ajustarPosicaoMenu() {
    menuSprite.setScale(2.5, 2.5);
    menuSprite.setPosition((janela->getSize().x - (menuTexture.getSize().x * menuSprite.getScale().x)) / 2.0f,
                           (janela->getSize().y - (menuTexture.getSize().y * menuSprite.getScale().y)) / 5.0f);

    semSomSprite.setPosition((janela->getSize().x - (semSomTexture.getSize().x * semSomSprite.getScale().x))/2,
                           (janela->getSize().y - (semSomTexture.getSize().y * semSomSprite.getScale().y)) / 1.47f);

}

void Menu::ajustarPosicaoTextos() {
    // Ajuste de escala e posição para a opção Iniciar Jogo
    sf::FloatRect iniciarJogoRect = iniciarJogoTexto.getLocalBounds();
    iniciarJogoTexto.setOrigin(iniciarJogoRect.width / 2.0f, iniciarJogoRect.height / 2.0f);
    iniciarJogoTexto.setPosition(janela->getSize().x / 2.0f,
                                 (janela->getSize().y - iniciarJogoRect.height) / 1.7f);

    // Ajuste de escala e posição para a opção Sair
    sf::FloatRect sairRect = sairTexto.getLocalBounds();
    sairTexto.setOrigin(sairRect.width / 2.0f, sairRect.height / 2.0f);
    sairTexto.setPosition(janela->getSize().x / 2.0f,
                          (janela->getSize().y - sairRect.height) / 1.7f + 120.0f);
}

void Menu::desenharTela() {
    janela->draw(menuSprite);
    janela->draw(semSomSprite);

    // Ajuste de escala para a opção Iniciar Jogo
    if (opcaoSelecionada == IniciarJogo) {
        iniciarJogoTexto.setScale(1.3, 1.3);
    } else {
        iniciarJogoTexto.setScale(1.0, 1.0);
    }
    janela->draw(iniciarJogoTexto);

    // Ajuste de escala para a opção Opções
    if (opcaoSelecionada == Opcoes) {
        semSomSprite.setScale(1.3, 1.3);
    } else {
        semSomSprite.setScale(1.0, 1.0);
    }
    janela->draw(opcoesTexto);

    // Ajuste de escala para a opção Sair
    if (opcaoSelecionada == Sair) {
        sairTexto.setScale(1.3, 1.3);
    } else {
        sairTexto.setScale(1.0, 1.0);
    }
    janela->draw(sairTexto);
}

bool Menu::sair() {
    janela->close();
    return false;  // Retorna false para indicar que o jogo deve encerrar
}

void Menu::atualizarPosicaoTextos() {
    ajustarPosicaoTextos();
    ajustarPosicaoMenu();
}

void Menu::atualizarOpcaoSelecionada() {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*janela);

    // Verifica se o mouse está sobre uma opção
    if (iniciarJogoTexto.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
        opcaoSelecionada = IniciarJogo;
    } else if (semSomSprite.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
        opcaoSelecionada = Opcoes;
    } else if (sairTexto.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
        opcaoSelecionada = Sair;
    } else {
        opcaoSelecionada = NenhumaSelecao;
    }
}

bool Menu::tratarCliqueMouse() {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*janela);

    if (iniciarJogoTexto.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
        return false;  
    } else if (semSomSprite.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
        somAtivo = false;
    } else if (sairTexto.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
        return sair();  // Sair
    }

    return true;  // Nenhuma ação executada
}

bool Menu::atualizar(sf::Event ev) {
    while (janela->pollEvent(ev)) {
        switch (ev.type) {
            case sf::Event::Closed:
                janela->close();
                return false;  // Retorna false para indicar que o jogo deve encerrar

            case sf::Event::MouseMoved:
                atualizarOpcaoSelecionada();
                atualizarPosicaoTextos();
                break;

            case sf::Event::MouseButtonPressed:
                if (ev.mouseButton.button == sf::Mouse::Left) {
                    return tratarCliqueMouse();
                }
                break;

            default:
                break;
        }
    }

    return true;
}

    Menu::OpcaoSelecionada Menu::getOpcaoSelecionada() const {
    return opcaoSelecionada;
}

bool Menu::getSomAtivo()
{
    return somAtivo;
}
void Menu::resetarSelecao() {
    opcaoSelecionada = NenhumaSelecao;
}


