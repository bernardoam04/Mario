#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/SoundManager.hpp"

TEST_CASE("Musica Carregada") {
    SoundManager sounds;
    SUBCASE("Musica de Fundo"){
        CHECK(sounds.getMusicaFundo().getDuration() > sf::Time::Zero);
    }
    
    SUBCASE("Som Moeda"){
        CHECK(sounds.getSbMoeda().getDuration() > sf::Time::Zero);
    }
    
    SUBCASE("Som Morte"){
        CHECK(sounds.getSbGameover().getDuration() > sf::Time::Zero);
    }
    SUBCASE("Som Pulo"){
        CHECK(sounds.getSbPulo().getDuration() > sf::Time::Zero);
    }
}

TEST_CASE("Musica Tocando") {
    SoundManager sounds;
    SUBCASE("Musica de Fundo"){
        sounds.tocarMusica();
        CHECK(sounds.isSoundPlaying("fundo") == true);
    }
    
    SUBCASE("Som Moeda"){
        sounds.somMoeda();
        CHECK(sounds.isSoundPlaying("moeda") == true);
    }

    SUBCASE("Som Pulo"){
        sounds.somPulo();
        CHECK(sounds.isSoundPlaying("pulo") == true);
    }

    SUBCASE("Som Moeda"){
        sounds.somGameOver();
        CHECK(sounds.isSoundPlaying("morte") == true);
    }

}

TEST_CASE("Pausar Musica"){
    SoundManager sounds;
    sounds.pausarMusica();
    CHECK(sounds.musicaPausada() == true);
}
