#include "../include/SoundManager.hpp"

SoundManager::SoundManager() {
    if (!this->musicaFundo.openFromFile("../audio/1-1.wav")) {
        throw std::exception();
    }
    this->tocarMusica();
}

void SoundManager::tocarMusica() {
    this->musicaFundo.play();
    this->musicaFundo.setLoop(true);
}

void SoundManager::pausarMusica() {
    this->musicaFundo.pause();
}

void SoundManager::reiniciarMusica(){
    this->musicaFundo.stop();
    this->musicaFundo.play();
}
