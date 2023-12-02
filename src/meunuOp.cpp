#include "../include/meunuOp.hpp"

menuOp::menuOp(sf::Font& font, std::shared_ptr<sf::RenderWindow> window)
    : Menu(window, font),
      volumeMusicText("Volume Música", font, 22),
      volumeeffectText("Volume Efeito", font, 22),
      opcaoSelecionada(volumemusic) { 

    // Ajuste de posição específico da classe derivada
    volumeMusicText.setPosition(100, 100);
    volumeeffectText.setPosition(150, 150);
};

    

void menuOp::desenharTela() {
    Menu::desenharTela();  // Chama o método da classe base para desenhar o menu principal

    // Adiciona desenhos específicos da classe derivada, se necessário
    janela->draw(volumeMusicText);
    janela->draw(volumeeffectText);
}

bool menuOp::atualizar(sf::Event ev) {
    Menu::atualizar(ev);  // Chama o método da classe base para atualizar o menu principal

    // Adiciona lógica específica da classe derivada, se necessário
    if (opcaoSelecionada == menuOp::opselect::volumemusic) {
    // Lógica para a opção de volume da música
} else if (opcaoSelecionada == menuOp::opselect::volumeefect) {
    // Lógica para a opção de volume do efeito
}


    return true;
}

void menuOp::atualizarPosicaoTextos() {
    Menu::atualizarPosicaoTextos();  // Chama o método da classe base para ajustar posições do menu principal

    // Adiciona ajustes de posição específicos da classe derivada, se necessário
}

void menuOp::atualizarOpcaoSelecionada() {
    Menu::atualizarOpcaoSelecionada();  // Chama o método da classe base para atualizar a opção selecionada do menu principal

    // Adiciona lógica específica da classe derivada, se necessário
}

bool menuOp::tratarCliqueMouse() {
    if (!Menu::tratarCliqueMouse()) {  // Chama o método da classe base e verifica se algo foi clicado no menu principal
        // Adiciona lógica específica da classe derivada para tratamento do clique, se necessário
        return false; 
    }

    return true; 
}