# Mario

## Índice

- [Descrição do projeto](#descrição-do-projeto)
- [Sobre o Mapa](#sobre-o-mapa)
- [Recursos](#recursos)
- [Compilação e Execução](#compilação-e-execução)
- [Controles](#controles)

## Descrição do projeto
![d459d3d5a51f7c5224f71daa9f54318a_w200](https://github.com/pds2-dcc-ufmg/2023-2-TN-grupo12/assets/78943325/f5173082-626a-4754-9876-0087d16649c1)

O projeto desenvolvido pelo grupo tinha como objetivo, recriar, do zero, utilizando os conceitos aprendidos na disciplina de PDS 2 o famoso jogo Super Mario Bros. Foi desenvolvido baseado no primeiro jogo da franquia e desenvolvemos apenas uma fase, baseada tambem no jogo original, para o projeto utilizamos a primeira fase como base.
  
  Super Mario Bros. é um icônico jogo de plataforma desenvolvido e publicado pela Nintendo. 
Lançado inicialmente em 1985 para o console Nintendo Entertainment System (NES), o jogo foi criado por Shigeru Miyamoto e Takashi Tezuka,
e rapidamente se tornou um marco na história dos videogames.

## Sobre o Mapa

Um dos maiores desafios enfrentados durante o desenvolvimento do nosso jogo foi a representação eficiente do mapa. Para superar esse obstáculo, optamos por utilizar a representação matricial.
Para fazer essa representação, foi utilizado o programa open-source [Tiled Map Editor](https://www.mapeditor.org/) para desenhar o mapa, e exportá-lo em formato .tmx, e por esse motivo precisamos incluir a biblioteca TinyXML2 para fazer um parsing do arquivo exportado e extrair os dados que era de nosso interesse (camadas, tiles...)
![image](https://github.com/pds2-dcc-ufmg/2023-2-TN-grupo12/assets/78943325/186b136b-432e-4424-ba08-113ed30ad80a)
Imagem do programa Tiled Map Editor

Um exemplo de como percorremos o arquivo XML gerado, foi bastante semelhante à maneira de percorrer os elementos de uma lista encadeada, neste exemplo a seguir, foi carregado a textura de todos os elementos 
![code](https://github.com/pds2-dcc-ufmg/2023-2-TN-grupo12/assets/78943325/1b90d2f1-2358-4a9c-a244-edc1da89aac4)


Basicamente, com essas informações obtidas nós somos capazes de criar colisão, texturas e sprites, entre outros, para interagir com o código


## Recursos


- Biblioteca Gráfica SFML
- Biblioteca TinyXML2 para a leitura do Mapa

## Controles
- Setas para se movimentar

## Compilação e Execução

Instruções sobre como compilar e executar o jogo. Certifique-se de incluir dependências e configurações específicas.

```bash
cd exec
make
./app.exe
