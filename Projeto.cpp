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
	switch(tecla){
	//cima
	case 'w': case 'W':
    case SETA_CIMA:
    j->pos.y--;
	break;
	
	//baixo
	case 's': case 'S':
    case SETA_BAIXO:
    j->pos.y++;
	break;
	
	//direito
	case 'a': case 'A':
    case SETA_ESQUERDA:
    j->pos.y--;
	break;
	
	//esquerda
	case 'd': case 'D':
    case SETA_DIREITA:
    j->pos.y++;
	break;
	
	default:
    return;
	}
	printf("Jogador se moveu para (%d, %d)\n", j->pos.x, j->pos.y);
}


int main(){
	Jogador player;
	
	iniciarJogador (&player, "Heroi");
	printf("Jogador %c criado com sucesso!\n", player.nome);
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
