#include "fila.h"
#include<stdio.h>
#include<time.h>

int main(int argc, char *argv[]) {
	Fila *f = cria_fila(6);
	int i;
	if(f){
		printf("\nFila criada com sucesso!\n");
		srand(time(0)); //inicia o gerador
		do{
			if(rand() % 2){
				insere_fila(rand()%10, f);
				mostra_vetor(f);
				mostra_fila(f);
			}
			else{
				remove_fila(&i, f);
				mostra_vetor(f);
				mostra_fila(f);
			}
		}while(!fila_vazia(f));
	}
	else{
		printf("\nFalha na alocacao\n");
	}
	return 0;
}
