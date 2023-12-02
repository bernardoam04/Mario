#ifndef PODERESESPECIAIS_HPP
#define PODERESESPECIAIS_HPP

#include <SFML/Graphics.hpp>
#include "../include/Colisao.hpp"
#include "../lib/tinyxml2.hpp"

class PoderesEspeciais  {
private:
    //Texturas e posições
    std::vector<sf::Texture> cogumeloTextures; 
    std::vector<sf::Texture> estrelaTextures; 
    std::vector<sf::Texture> moedaTextures; 
    sf::Sprite poderSprite;  
    sf::Vector2f posicaoInicial; 
    sf::Vector2f posicao; 
    int tipo;


    //Constantes
    const float aceleracaoGravidadeMoeda = 40.8f;;
    const float aceleracaoGravidade = 4.8f;;
    static const int COGUMELO = 1; 
    static const int ESTRELA = 2; 
    static const int MOEDA = 3; 
    const float tileSize=32;

    //Modificáveis
    float velocidadeVertical = 0.0f;;
    float velocidadeHorizontal = 50.0f;
    float velocidadeInicialPulo = 1000.0f;

    //Verificações
    bool moedaColetada = false;
    bool puloIniciado = false;
    bool estaNoAr = false;
    bool movDireita= true;
    bool movEsquerda= false;
    bool existe = false;

    Colisao &colisao;
public:
    //Construtor
    PoderesEspeciais(Colisao &colisao);  

    //Carregamento
    void carregarMoedas();
    void carregarPoderes();

    //Métodos usados diretamente
    int gerarTipoAleatorio();
    bool inicializarNoMapa(Mapa& mapa);
    void inicializar(float x, float y);
    void desenhar(sf::RenderWindow& janela);
    void ModificacaoPosicaoPoderes(sf::Time deltaTime);
    void ModificacaoPosicaoMoeda(sf::Time deltaTime);
    void atualizar(sf::Time deltaTime, sf::Time tempoAtual);
    void voltarPosicaoInicial();

    //Verificação
    bool verificarColisao(sf::Vector2f posicaoPersonagem, int altura, int largura);

    //Getters
    sf::Vector2f getPosicaoInicial();
    int getTipo();
    sf::Vector2f getPosicaoAtual();
};

#endif 