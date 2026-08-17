//bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>


#define SETA_CIMA 72
#define SETA_BAIXO 80
#define SETA_ESQUERDA 75
#define SETA_DIREITA 77
#define TECLA_ESC 27

#define LARGURA 10
#define ALTURA 10

// Mapa global inicial do jogo
char mapa[ALTURA][LARGURA] = {
    {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
    {'X', '.', '.', '.', 'X', '.', '.', '.', '.', 'X'},
    {'X', '.', '^', '.', 'X', '.', 'E', '.', '.', 'X'}, // '^' é espinho
    {'X', '.', '.', '.', '.', '.', '.', '.', '.', 'X'}, //'E' é inimigo
    {'X', 'X', 'X', '.', 'X', 'X', 'X', 'X', '.', 'X'},
    {'X', '.', '.', '.', '.', '.', '^', '.', '.', 'X'},
    {'X', '.', 'E', '.', 'X', '.', '.', '.', '.', 'X'},
    {'X', '.', '.', '.', 'X', '.', '.', '.', '.', 'X'},
    {'X', '.', '.', '.', 'X', '.', '.', '.', '.', 'X'},
    {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}
};

typedef struct {
	int x;
	int y;

} posicao;//estrutura da posiçao

typedef struct {
	char nome[25];
	int vida;
	int vidaMax;
	int ataque;
	int nivel;
	posicao pos;
	int chaves;
} Jogador;//estrutura do que compoe o jogador


void iniciarJogador(Jogador *j, const char *nomeInicial){
	strcpy(j->nome, nomeInicial);
//Status iniciais do nosso jogador
	j->vidaMax = 100;
	j->vida = 100;
	j->nivel = 1;
	j->ataque = 10;
	j->chaves = 0;
//Posição inicial
	j->pos.x = 1;
	j->pos.y = 1;
}

void moverJogador(Jogador *j, int tecla){
	if (tecla == 224 || tecla == 0){
		tecla = _getch();
	}
	
	int direcaoX = j->pos.x;
	int direcaoY j->pos.y;
	
	switch(tecla){
	//cima
	case 'w': case 'W':
    case SETA_CIMA:
    direcaoY--;
	break;
	
	//baixo
	case 's': case 'S':
    case SETA_BAIXO:
    direcaoY++;
	break;
	
	//esquerda
	case 'a': case 'A':
    case SETA_ESQUERDA:
  	direcaoX--;
	break;
	
	//direita
	case 'd': case 'D':
    case SETA_DIREITA:
    direcaoX++;
	break;
	
	default: return;
    
	}
	
	//fazer a checagem de colisão(alterando apenas a copia da função)
	if (mapa[direcaoY][direcaoX] == 'X'){
		printf("/nVocê colidiu com a parede!/n")
		return; //quando retorna aqui faz o cancelamento do movimento
	}
	if (mapa[direcaoY][direcaoX]=='^'){
		int dano = 20;
		j->vida -= dano;
		printf("\nVocê caiu na armadilha e levou %d de dano/n", dano);
	}
	if (mapa[direcaoY][direcaoX]== 'E'){
		int dano = 35;
		j->vida -= dano;
		printf("/nVoce enfrentou um inimigo! Perdeu %d de vida!\n", dano);
		mapa[novoY][novoX] = '.';
	}
	
	if(j->vida>0){
		j->pos.x = direcaoX;
		j->pos.y = direcaoY;
		}	
	}
	printf("Jogador se moveu para (%d, %d)\n", j->pos.x, j->pos.y);
}


int main(){
	Jogador player;
	
	iniciarJogador (&player, "Heroi");
	printf("Jogador %s criado com sucesso!\n", player.nome);
	printf("Vida: %d de %d\n", player.vida, player.vidaMax);
	printf("Posicao inicial do jogador: %d, %d\n", player.pos.x, player.pos.y);
	
	
	int tecla;
	printf("Use WASD ou as Setinhas do teclado para movimentar.\n");
    printf("Pressione 'q' ou ''ESC' para sair.\n\n");
    
    	while(1){
    		tecla = _getch();
    		
    		if(tecla == 'q' || tecla == 'Q' || tecla == TECLA_ESC){
    			printf("Jogo encerrado!\n");
    			break;
			}
			moverJogador(&player, tecla);
		}
    	
	return 0;
}
