#include "../include/SoundManager.hpp"
#include <unordered_map>
#include "SoundManager.hpp"

SoundManager::SoundManager() {
    //Define o som e efeitos sonoros de cada estado do jogo
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

    if (!this->sbGameoverScream.loadFromFile("../audio/gameOver.wav")) {
        throw std::exception();
    }


    if (!this->sbCogumelo.loadFromFile("../audio/mushroom.wav")) {
        throw std::exception();
    }


    if (!this->sbWin.loadFromFile("../audio/win.wav")) {
        throw std::exception();
    }

    sMoeda.setBuffer(sbMoeda);
    sGameOver.setBuffer(sbGameOver);
    sPulo.setBuffer(sbPulo);
    sGameoverScream.setBuffer(sbGameoverScream);
    sCogumelo.setBuffer(sbCogumelo);
    sWin.setBuffer(sbWin);
}

void SoundManager::tocarMusica() {
    if(somAtivo){
        this->musicaFundo.play();
        this->musicaFundo.setLoop(true);
    }
}

void SoundManager::pausarMusica() {
    this->musicaFundo.pause();
}

void SoundManager::reiniciarMusica(){
    if(somAtivo){
        this->musicaFundo.stop();
        this->musicaFundo.play();
    }
}

void SoundManager::somMoeda(){
    if(somAtivo){
        this->sMoeda.play();
    }
}

void SoundManager::somGameOver(){
    if(somAtivo){
        this->sGameOver.play();
    }
}

void SoundManager::somPulo(){
    if(somAtivo){
        this->sPulo.play();
    }
}
void SoundManager::somgameovertela() {
    if(somAtivo){
        this->sGameoverScream.play();
    }
 }

 void SoundManager::somCogumelo()
 {
    if(somAtivo){
        this->sCogumelo.play();
    }
 }

 void SoundManager::somWin()
 {
    if(somAtivo){
        this->sWin.play();
    }
 }

sf::Music& SoundManager::getMusicaFundo(){
    return this->musicaFundo;
}

sf::SoundBuffer& SoundManager::getSbMoeda(){
    return this->sbMoeda;
}

sf::SoundBuffer& SoundManager::getSbPulo(){
    return this->sbPulo;
}

sf::SoundBuffer& SoundManager::getSbGameover(){
    return this->sbGameOver;
}

bool SoundManager::isSoundPlaying(std::string som){
    //definifno qual som sera usado para cada momento
    std::unordered_map<std::string, int> opcao = {{"moeda", 0}, {"morte", 1}, {"pulo", 2}, {"fundo", 3}};
    switch (opcao[som]){
    case 0:
        return this->sMoeda.getStatus() == sf::Music::Playing;
        break;
    case 1:
        return this->sGameOver.getStatus() == sf::Music::Playing;
        break;
    case 2:
        return this->sPulo.getStatus() == sf::Music::Playing;
        break;
    case 3:
        return this->musicaFundo.getStatus() == sf::Music::Playing;
        break;
    default:
        return false;
        break;
    }
}

void SoundManager::carregarSomPadrao(sf::SoundBuffer& soundBuffer){
    //buffer com som vazio
    sf::Int16 emptySamples[] = { static_cast<sf::Int16>(44100 * 5) };
    soundBuffer.loadFromSamples(emptySamples, 4, 1, 44100);
}

bool SoundManager::musicaPausada(){
    return this->musicaFundo.getStatus() == sf::Music::Paused;
}
void SoundManager::desativarSom()
{
    somAtivo = false;
}