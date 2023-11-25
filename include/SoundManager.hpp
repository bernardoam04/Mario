#ifndef SOUND_MANAGER_HPP
#define SOUND_MANAGER_HPP
#include <SFML/Audio.hpp>

class SoundManager{
    private:
        sf::Music musicaFundo;

    public:
        SoundManager();
        void tocarMusica();
        void pausarMusica();
        void reiniciarMusica();
};

#endif