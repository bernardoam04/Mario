#include "../include/SoundManager.hpp"

SoundManager::SoundManager() {
    if (!this->musicaFundo.openFromFile("../audio/1-1.wav")) {
        throw std::exception();
    }
    if(!this->sbMoeda.loadFromFile("../audio/coin.wav")){
        throw std::exception();
    }
    if(!this->sbGameOver.loadFromFile("../audio/death.wav")){
        throw std::exception();
    }
    if(!this->sbPulo.loadFromFile("../audio/jump.wav")){
        throw std::exception();
    }
    sMoeda.setBuffer(sbMoeda);
    sGameOver.setBuffer(sbGameOver);
    sPulo.setBuffer(sbPulo);
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

void SoundManager::somMoeda(){
    this->sMoeda.play();
}

void SoundManager::somGameOver(){
    this->sGameOver.play();
}

void SoundManager::somPulo(){
    this->sPulo.play();
}