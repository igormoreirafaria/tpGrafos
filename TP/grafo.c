#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hipergrafo"
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
	grafo->adj = malloc((vertice)*sizeof(ADJ*));
	for(int i=0;i<vertice;i++){
		grafo->adj[i] = malloc((vertice)*sizeof(ADJ));
	}
	for(int i = 0; i<(vertice);i++){
		for (int j = 0; j < (vertice); j++){
			grafo->adj[i][j].peso = 0;
			grafo->adj[i][j].grau = 0;
			grafo->adj[i][j].cor = malloc(sizeof(strlen("nenhuma")));
			grafo->adj[i][j].cor = "nenhuma";
		}
	}
	return *grafo;
}

int eh_solucao(Grafo *G, int *tabela){

	for(int i=0;i<G->numVertice;i++){
		for(int j=0;j<G->numVertice;j++){
			if(G->adj[i][j].peso == 1){
				if(tabela[i] == tabela[j]){
					printf("\n");
					for(int i=0;i<G->numVertice;i++) printf("%d", tabela[i]);
					return 0;
				}
			}
		}
	}
	printf("\n solution ");
	for(int i=0;i<G->numVertice;i++) printf("%d", tabela[i]);
		//getchar();
	return 1;
}

void bakctracking(Grafo *G){;
	int *cor = malloc(sizeof(int)*G->numVertice);
	int i=0, flag=1, k=0;
	int *tabela = malloc(sizeof(int) * G->numVertice );
	int cont=0;
	for(i=0;i<G->numVertice;i++){
		cor[i]=i;
		tabela[i]= 0;
	}
	i=G->numVertice - 1;
	//j=G->numVertice - 2;
	while(flag == 1){
		cont++;
			if(tabela[i]< G->numVertice){
				tabela[i]++;
				if(i!=( G->numVertice)) i++;
			}else {
				tabela[i]= 0;
				i--;
			}
			if(eh_solucao(G, tabela)) {
				break;
			}
	}
	printf("cont %d %d " , cont, k);
	getchar();
}


void leitura(Grafo *G){
	int i=0, j=0;
	char *leitura;
	FILE *arq = fopen("sudoku.txt", "r");
	leitura = malloc(sizeof(char)*100);
	while(!feof(arq)){
		fgets(leitura, 2, arq);

		G->adj[i][j].peso = atoi(leitura);
		j++;
		if(j == 9){
			j=0;
			i++;
		}

		if(i==9){
			break;
		}
	}

	imprimeGrafo(G);

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


	 insereAresta(grafo,0,1,1);
	 insereAresta(grafo,0,2,1);
	 insereAresta(grafo,0,3,1);
	 insereAresta(grafo,1,2,1);
	 insereAresta(grafo,1,3,1);
	 insereAresta(grafo,2,3,1);

	imprimeGrafo(grafo);

	bakctracking(grafo);

	printf("\n");
	// leitura(grafo);
	verificaGrau(grafo);
	//insereAresta(grafo,0,0,10);
	// imprimeGrafo(grafo);
	//printf("o vertice 3 possui grau %d\n", getGrau(grafo, 3));

	return 0;
}