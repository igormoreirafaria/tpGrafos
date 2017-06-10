#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int numVertice;
	int numAresta;
	int **adj;

}Grafo;

int verificaGrau(Grafo * grafo, int vertice){
	int grau = 0;

	for(int j=vertice, i=0;i<grafo->numVertice;i++){
		if(grafo->adj[i][j]>0){
			grau = grau + 1;
		}
	}




	return grau;
}

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
	grafo->adj[verticeB][verticeA] = peso;

}

Grafo *criaGrafo(int vertice, int aresta){
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
	return grafo;
}


void leitura(Grafo **G){
	int i=0, j=0;
	char *leitura;
	FILE *arq = fopen("sudoku.txt", "r");
	leitura = malloc(sizeof(char)*100);
	while(!feof(arq)){
		fgets(leitura, 2, arq);
		printf("%s\n", leitura);
		(*G)->adj[i][j] = atoi(leitura);
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
	grafo = criaGrafo(vertice, aresta);
	if(grafo==NULL){
		printf("Grafo não criado\n");
	}
	imprimeGrafo(grafo);

	printf("\n");
	leitura(&grafo);
	//insereAresta(grafo,0,0,10);

	// imprimeGrafo(grafo);
	// verificaGrau(grafo,3);
	return 0;
}