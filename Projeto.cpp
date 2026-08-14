//bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>


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
int main(){
	Jogador player;
	
	iniciarJogador (&player, "Heroi");
	printf("Jogador %c criado com sucesso!\n", player.nome);
	printf("Vida: %d de %d\n", player.vida, player.vidaMax);
	printf("Posicao inicial do jogador: %d, %d\n", player.pos.x, player.pos.y);
	
	return 0;
}
