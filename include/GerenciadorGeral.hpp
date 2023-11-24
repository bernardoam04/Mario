#ifndef GERENCIADORGERAL_HPP
#define GERENCIADORGERAL_HPP

#include "../include/Mapa.hpp"
#include "../include/Camera.hpp"
#include "../include/Colisao.hpp"
#include "../include/PoderesEspeciais.hpp"
#include "../include/Pontuacao.hpp"

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

    //Métodos privados
    void inicializarVariaveis();
    void InicializarPoderesEspeciais();
public:
    //Construtor e Destrutor
    GerenciadorGeral(std::shared_ptr <sf::RenderWindow> janela1, sf::Font &fonte);
    virtual ~GerenciadorGeral();

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


};

#endif
