#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prox;
    int *vertices;
}Node;

typedef struct grafo {
    int  num_vertice;
    Node *lista;
}Grafo;

void inicia_grafo(Grafo **G, int num_vertice);
void criar_dependencias(Grafo **G, int i, int vertice);
void criar_grafo(Grafo **G);
int getPrimProx(Grafo *grafo, int r, int A, int *prim, int *prox);