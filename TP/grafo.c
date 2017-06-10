#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int peso;
	int grau;
	char *cor;

}ADJ;

typedef struct{
	int numVertice;
	int numAresta;
	ADJ **adj;

}Grafo;


int getGrau(Grafo *grafo, int vertice){
	return grafo->adj[vertice][0].grau;
}


void verificaGrau(Grafo *grafo){
	int grau = 0;

	for(int i=0;i<grafo->numVertice;i++){
		for(int j=0;j<grafo->numVertice;j++){
			if(grafo->adj[i][j].peso>0){
				grau = grau + 1;
			}
		}
		grafo->adj[i][0].grau = grau;
		grau = 0;
	}
	
}

void imprimeGrafo(Grafo *grafo){

	for(int i = 0; i<(grafo->numVertice);i++){
		for(int j=0;j<(grafo->numVertice);j++){
			printf("%d ", grafo->adj[i][j].peso);
		}
		printf("\n");
	}
}

void insereAresta(Grafo *grafo, int verticeA, int verticeB, int peso){
	grafo->adj[verticeA][verticeB].peso = peso;
	grafo->adj[verticeB][verticeA].peso = peso;

}

Grafo criaGrafo(int vertice, int aresta){
	Grafo *grafo;
	grafo = malloc(sizeof(grafo));
	grafo->numVertice = vertice;
	grafo->numAresta = aresta;
	grafo->adj = malloc(vertice*sizeof(ADJ*));
	for(int i=0;i<vertice;i++){
		grafo->adj[i] = malloc(vertice*sizeof(ADJ));
	}
	for(int i = 0; i<vertice;i++){
		for (int j = 0; j < vertice; j++){
			grafo->adj[i][j].peso = 0;
			grafo->adj[i][j].grau = 0;
			grafo->adj[i][j].cor = malloc(sizeof(strlen("nenhuma")));
			grafo->adj[i][j].cor = "nenhuma";
		}
	}
	return *grafo;
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
	
	// insereAresta(grafo,3,0,1);
	// insereAresta(grafo,0,2,1);
	// insereAresta(grafo,2,4,1);
	// insereAresta(grafo,1,3,1);
	// insereAresta(grafo,2,3,1);
	
	// imprimeGrafo(grafo);
	// verificaGrau(grafo);

	// getGrau(grafo, 2);

	return 0;
}