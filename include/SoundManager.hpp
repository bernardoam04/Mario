#ifndef SOUND_MANAGER_HPP
#define SOUND_MANAGER_HPP
#include <SFML/Audio.hpp>

class SoundManager{
    private:
        sf::Music musicaFundo;
        sf::SoundBuffer sbMoeda;
        sf::Sound sMoeda;
        sf::SoundBuffer sbPulo;
        sf::Sound sPulo;
        sf::SoundBuffer sbGameOver;
        sf::Sound sGameOver;

    public:
        SoundManager();
        void tocarMusica();
        void pausarMusica();
        void reiniciarMusica();

        void somMoeda();
        void somGameOver();
        void somPulo();

        sf::Music& getMusicaFundo();
        sf::SoundBuffer& getSbMoeda();
        sf::SoundBuffer& getSbPulo();
        sf::SoundBuffer& getSbGameover();

        bool isSoundPlaying(std::string som);
        bool musicaPausada();

        void carregarSomPadrao(sf::SoundBuffer& soundBuffer);
};

#endif