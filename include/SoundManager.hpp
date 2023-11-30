#ifndef SOUND_MANAGER_HPP
#define SOUND_MANAGER_HPP
#include <SFML/Audio.hpp>

class SoundManager{
    private:
        sf::Music musicaFundo;
        sf::SoundBuffer sbMoeda;
        sf::Sound sMoeda;
        sf::Sound sGameOver;
        sf::SoundBuffer sbGameOver;

    public:
        SoundManager();
        void tocarMusica();
        void pausarMusica();
        void reiniciarMusica();

        void somMoeda();
        void somGameOver();
};

#endif