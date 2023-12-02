#ifndef SOUND_MANAGER_HPP
#define SOUND_MANAGER_HPP
#include <SFML/Audio.hpp>

class SoundManager{
    private:
        //Sons e músicas
        sf::Music musicaFundo;
        sf::SoundBuffer sbMoeda;
        sf::Sound sMoeda;
        sf::SoundBuffer sbPulo;
        sf::Sound sPulo;
        sf::Sound sGameOver;
        sf::SoundBuffer sbGameOver;
        sf::SoundBuffer sbGameoverScream;  
        sf::Sound sGameoverScream;    

    public:
        //Construtor
        SoundManager();

        //Música principal
        void tocarMusica();
        void pausarMusica();
        void reiniciarMusica();

        //Sons
        void somMoeda();
        void somGameOver();
        void somPulo();
        void somgameovertela();
};

#endif