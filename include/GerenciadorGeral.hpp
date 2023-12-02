#ifndef GERENCIADORGERAL_HPP
#define GERENCIADORGERAL_HPP

#include "../include/Mapa.hpp"
#include "../include/Camera.hpp"
#include "../include/Colisao.hpp"
#include "../include/PoderesEspeciais.hpp"
#include "../include/Pontuacao.hpp"
#include "../include/SoundManager.hpp"
#include "Jogador.hpp"
#include "Goomba.hpp"
#include <set>

class GerenciadorGeral{
private:

    //Informações da tela(mesma do main)
    const float alturaTela = 640;
    const float larguraTela = 640;

    //Tipos Abstratos
    std::shared_ptr <sf::RenderWindow> janela;
    std::shared_ptr <Pontuacao> pontuacao;
    Mapa mapa;  
    std::shared_ptr <Camera> camera;
    std::shared_ptr <Colisao> colisao;
    std::vector<std::shared_ptr <PoderesEspeciais>> vetorPoderesEspeciais;
    std::vector<std::shared_ptr <Goomba>> goombas;
    std::shared_ptr<SoundManager> _sounds;
    std::shared_ptr <Jogador> mario;
    std::set<unsigned int> indicesComColisao;
    std::set<unsigned int> indicesPoderesEspeciais;
    std::shared_ptr <Goomba> goomba;

    //Textos da pontuacao
    sf::Text textoMaisCem;
    sf::Text textoMaisMil;
    sf::Text textoGanhou;
    sf::Clock temporizadorTexto;
    sf::Time duracaoTexto = sf::seconds(0.5f);

    //Métodos privados
    void inicializarVariaveis();
    void InicializarPoderesEspeciais();
    void InicializarGoombas();
    void inicializarTextos(sf::Font &fonte);
    void atualizarPosicaoTexto(sf::Text &texto);

    //Verificações
    bool puloHabilitado;
    bool gameOver;
    std::vector <int> contagemDesenhoPoderes;

    //Contador
    int contadorPerdeu = 0;

public:
    //Construtor e Destrutor
    GerenciadorGeral(std::shared_ptr <sf::RenderWindow> janela1, sf::Font &fonte, std::shared_ptr<SoundManager> sounds);

    //Métodos de Verificação
    int verificarColisao(float x, float y) const;
    bool janelaAberta() const;

    //Métodos utilizados no jogo diretamente
    bool atualizar(sf::Time tempoAtual, sf::Time deltaTime, sf::Event ev);
    bool atualizarEventos(sf::Event ev);
    void renderizar(sf::Time tempoAtual);
    void desenharMapa(sf::Time tempoAtual);

    //Getters
    float getAlturaTela() const;
    float getLarguraTela() const;
    int getPontuacaoTotal() const;
    const sf::View& getViewCamera() const;
    bool getGamerOver();


};

#endif
