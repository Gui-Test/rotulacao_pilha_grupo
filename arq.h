#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIM 1
#define NAO 0
#define SUCESSO 1
#define FRACASSO 0

typedef struct{
	int lin;
	int col;
}info;

struct caixa{	
	info dados;
	struct caixa *acima;
	struct caixa *abaixo;
};	

struct pilha{ 
	struct caixa *topo;
	int tamPilha;
};

//Funções da Pilha
struct pilha * cria(void);
int vazia(struct pilha *pil);
int empilha(info *reg, struct pilha *pil);
int desempilha(info *reg, struct pilha *pil);
int busca(info *reg, struct pilha *pil);
void reinicia(struct pilha *pil);
struct pilha *destroi(struct pilha *pil);

//Funções da matriz e marcador
int conta_linha(FILE *f);
int ** cria_matriz(int *m, int *n);
void insere_matriz(int*** mat, int m, int n);
void print_matriz(int **mat, int m, int n);
info mover(int ***mat, info dir[4], info *novo);
int marcador(int i,int j,int rot, struct pilha *pil, info dir[4], int*** mat, int m, int n, int* bariLT, int* bariCT);
void limpa_matriz(int ***mat, int m, int n, int rot);

