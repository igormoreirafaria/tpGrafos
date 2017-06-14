#include "hipergrafoTAD.h"


void inicia_grafo(Grafo **G, int num_vertice){

    (*G) = malloc(sizeof(Grafo));

    (*G)->lista = malloc(sizeof(Node)*num_arestas);

}

void adiciona_vertice (Grafo **G, int *vertice, int aresta){ //adiciona um vertice na aresta

}
void criar_dependencias(Grafo **G){
    Node *list = (*G)->lista[i]->prox;
    // colunas
    list = realloc(list, ((sizeof(list)/sizeof(int)) + sizeof(int)));

    list[(sizeof(list)/sizeof(int)) + 1] = vertice;

}

int verifica_conflitos(Grafo *G){

}