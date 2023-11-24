#include "Mapa.hpp"
#include "Camera.hpp"
#include "PoderesEspeciais.hpp"
#include "Colisao.hpp"


class Personagem {
    private:
        //Posicao e modificadores
        int coord_x;
        int coord_y;
        float velocidadeVertical;
        float velocidadeHorizontal;

        //Verificacoes
        bool vivo;
        bool estaNoAr;
        bool movDireita;
        bool movEsquerda;

        //Colisao
        Colisao &colisao;
        
    public:


}