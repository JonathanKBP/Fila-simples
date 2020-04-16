#include<stdio.h>
#include<stdlib.h>

typedef struct fila Fila;

Fila *cria_fila(int );

int fila_vazia(Fila *);
int fila_cheia(Fila *);

int insere_fila(int, Fila *);
int remove_fila(int *, Fila *);

int tamanho_fila(Fila *);

void mostra_fila(Fila *);

void mostra_vetor(Fila *);
 
