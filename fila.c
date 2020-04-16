#include "fila.h"

struct fila{
	int *v;
	int prim, ult;
	int cont, capacidade;
};

Fila * cria_fila (int n){
	Fila *aux = (Fila *) malloc (sizeof(Fila));
	if(aux){
		aux -> v = (int *)malloc (n * sizeof(int));
		if(!aux -> v)
			return NULL;
		aux -> cont = 0;
		aux -> prim = 0;
		aux -> ult = 0;
		aux -> capacidade = n;
	}
	return aux;
}

int fila_vazia (Fila *f){
	if(f -> cont == 0)
		return 1;//true
	return 0;//false
}

int fila_cheia (Fila *f){
	if(f -> cont == f -> capacidade)
		return 1;
	return 0;
}

int proxima(int pos, Fila *f){
	return (pos+1) % f -> capacidade;
}

int insere_fila(int i, Fila *f){
	if(fila_cheia(f))
		return 0;
	f->v[f->ult] = i;
	f->cont ++;
	f->ult = proxima(f->ult, f);
	return 1;
}

int remove_fila(int *i, Fila *f){
	if(fila_vazia(f))
		return 0;
	*i = f -> v[f ->prim];
	f->prim = proxima(f->prim, f);
	f->cont--;
	return 1;
}

int tamanho_fila(Fila *f){
	return f->cont;	
}

void mostra_fila(Fila *f){
	int i;
	if(fila_vazia(f))
		printf("fila vazia");	
	else{
		for(i=f->prim; i != f->ult; i = proxima(i, f))
			printf("%d ", f->v[i]);
	}
}

void mostra_vetor(Fila *f){
	int i;
	printf("\n");
	if(!fila_vazia(f)){
		if(f->prim < f->ult){
			for(i= 0; i<f->prim; i++)
				printf("_ ");
			for(i=f->prim; i<f->ult; i++)
				printf("%d ", f->v[i]);
			for(i=f->ult; i<f->capacidade; i++)
				printf("_ ");			
		}
		else{
			for(i= 0; i<f->ult; i++)
				printf("%d ", f->v[i]);
			for(i=f->ult; i<f->prim; i++)
				printf("_ ");
			for(i=f->ult; i<f->capacidade; i++)
				printf("%d ", f->v[i]);
		}
		printf(" | ");
	}
}

