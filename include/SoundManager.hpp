#ifndef SOUND_MANAGER_HPP
#define SOUND_MANAGER_HPP

#include <SFML/Audio.hpp>

/**
 * @brief Classe responsável pela gestão de sons e músicas no jogo.
 */
class SoundManager {
private:
    // Sons e músicas
    sf::Music musicaFundo; ///< Objeto Music do SFML para a música de fundo.
    sf::SoundBuffer sbMoeda; ///< Buffer do SFML para o som da moeda.
    sf::Sound sMoeda; ///< Objeto Sound do SFML para o som da moeda.
    sf::SoundBuffer sbPulo; ///< Buffer do SFML para o som de pulo.
    sf::Sound sPulo; ///< Objeto Sound do SFML para o som de pulo.
    sf::SoundBuffer sbGameOver; ///< Buffer do SFML para o som de Game Over.
    sf::SoundBuffer sbGameoverScream; ///< Buffer do SFML para o som de grito de Game Over.
    sf::Sound sGameoverScream; ///< Objeto Sound do SFML para o som de grito de Game Over.
    sf::Sound sGameOver; ///< Objeto Sound do SFML para o som de Game Over.
    sf::SoundBuffer sbWin; ///< Buffer do SFML para o som de vitória.
    sf::Sound sWin; ///< Objeto Sound do SFML para o som de vitória.
    sf::SoundBuffer sbCogumelo; ///< Buffer do SFML para o som do cogumelo.
    sf::Sound sCogumelo; ///< Objeto Sound do SFML para o som do cogumelo.

    bool somAtivo = true; ///< Indica se os sons estão ativados ou desativados.

public:
    /**
     * @brief Construtor da classe SoundManager.
     */
    SoundManager();

    /**
     * @brief Toca a música de fundo.
     */
    void tocarMusica();

    /**
     * @brief Pausa a música de fundo.
     */
    void pausarMusica();

    /**
     * @brief Reinicia a reprodução da música de fundo.
     */
    void reiniciarMusica();

    /**
     * @brief Reproduz o som da moeda.
     */
    void somMoeda();

    /**
     * @brief Reproduz o som de Game Over.
     */
    void somGameOver();

    /**
     * @brief Reproduz o som de pulo.
     */
    void somPulo();

    /**
     * @brief Reproduz o som de Game Over com grito.
     */
    void somgameovertela();

    /**
     * @brief Reproduz o som do cogumelo.
     */
    void somCogumelo();

    /**
     * @brief Reproduz o som de vitória.
     */
    void somWin();

    /**
     * @brief Obtém uma referência à música de fundo.
     * @return Referência à música de fundo.
     */
    sf::Music& getMusicaFundo();

    /**
     * @brief Obtém o buffer de som da moeda.
     * @return Referência ao buffer de som da moeda.
     */
    sf::SoundBuffer& getSbMoeda();

    /**
     * @brief Obtém o buffer de som de pulo.
     * @return Referência ao buffer de som de pulo.
     */
    sf::SoundBuffer& getSbPulo();

    /**
     * @brief Obtém o buffer de som de Game Over.
     * @return Referência ao buffer de som de Game Over.
     */
    sf::SoundBuffer& getSbGameover();

    /**
     * @brief Verifica se um determinado som está sendo reproduzido.
     * @param som Nome do som a ser verificado.
     * @return Verdadeiro se o som estiver sendo reproduzido; falso caso contrário.
     */
    bool isSoundPlaying(std::string som);

    /**
     * @brief Verifica se a música está pausada.
     * @return Verdadeiro se a música estiver pausada; falso caso contrário.
     */
    bool musicaPausada();

    /**
     * @brief Desativa a reprodução de sons.
     */
    void desativarSom();

    /**
     * @brief Ativa a reprodução de sons.
     */
    void ativarSom();

    /**
     * @brief Carrega um som vazio em um buffer de som.
     * @param soundBuffer Referência ao buffer de som que vai receber o som vazio.
     */
    void carregarSomVazio(sf::SoundBuffer& soundBuffer);
};

#endif
