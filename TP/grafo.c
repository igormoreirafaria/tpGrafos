#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int numVertice;
	int numAresta;
	int **adj;

}Grafo;

void imprimeGrafo(Grafo *grafo){

	for(int i = 0; i<(grafo->numVertice);i++){
		for(int j=0;j<(grafo->numVertice);j++){
			printf("%d ", grafo->adj[i][j]);
		}
		printf("\n");
	}
}

void insereAresta(Grafo *grafo, int verticeA, int verticeB, int peso){
	grafo->adj[verticeA][verticeB] = peso;
}

Grafo criaGrafo(int vertice, int aresta){
	Grafo *grafo;
	grafo = malloc(sizeof(grafo));
	grafo->numVertice = vertice;
	grafo->numAresta = aresta;
	grafo->adj = malloc(vertice*sizeof(int*));
	for(int i=0;i<vertice;i++){
		grafo->adj[i] = malloc(vertice*sizeof(int));
	}
	for(int i = 0; i<vertice;i++){
		for (int j = 0; j < vertice; j++){
			grafo->adj[i][j] = 0;
		}
	}
	return *grafo;
}


void leitura(Grafo **G){
	int i=0, j=0, leitura;
	FILE *arq = fopen("sudoku.txt", "r");
	while(!feof(arq)){

		fscanf(arq, "%d", &leitura);
		printf("%d\n", leitura);
		(*G)->adj[i][j] = leitura;
		j++;
		if(j == 9){
			j=0;
			i++;
		}

		if(i==9){
			break;
		}
	}

	imprimeGrafo(*G);

	fclose(arq);
}

int main(){
	int vertice;
	int aresta;
	printf("Digite numero de numero de Vertice\n");
	printf("> ");
	scanf("%d", &vertice);
	printf("\n");
	printf("Digite numero de numero de Aresta\n");
	printf("> ");
	scanf("%d", &aresta);
	printf("\n");
	Grafo *grafo;
	*grafo = criaGrafo(vertice, aresta);
	if(grafo==NULL){
		printf("Grafo não criado\n");
	}
	imprimeGrafo(grafo);

	printf("\n");
	leitura(&grafo);
	//insereAresta(grafo,0,0,10);
	return 0;
}