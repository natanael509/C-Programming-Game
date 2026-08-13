typedef struct {
	int x;
	int y;

} posicao;

typedef struct {
	char nome[50];
	int vida;
	int vidaMax;
	int ataque;
	int nivel;
	posicao pos;
	int chaves;
} Jogador;
