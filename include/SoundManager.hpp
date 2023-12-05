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
        sf::SoundBuffer sbGameOver;
        sf::SoundBuffer sbGameoverScream;  
        sf::Sound sGameoverScream;    
        sf::Sound sGameOver;
        sf::SoundBuffer sbWin;  
        sf::Sound sWin;  
        sf::SoundBuffer sbCogumelo;  
        sf::Sound sCogumelo;      

        bool somAtivo = true;

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
        void somCogumelo();
        void somWin();

        sf::Music& getMusicaFundo();
        sf::SoundBuffer& getSbMoeda();
        sf::SoundBuffer& getSbPulo();
        sf::SoundBuffer& getSbGameover();

        bool isSoundPlaying(std::string som);
        bool musicaPausada();
        void desativarSom();
        void ativarSom();

        void carregarSomVazio(sf::SoundBuffer& soundBuffer);
};

#endif