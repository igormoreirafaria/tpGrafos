#include "hipergrafoTAD.h"


void inicia_grafo(Grafo **G, int num_arestas){

    (*G) = malloc(sizeof(Grafo));

    (*G)->lista = malloc(sizeof(Node)*num_arestas);

    for(int i=0;i<27;i++){
        (*G)->lista[i].prox = malloc(sizeof(Node));
        (*G)->lista[i].prox->vertices = malloc(sizeof(int)*9);
        for (int j=0;j<9;j++){
            (*G)->lista[i].prox->vertices[j] = -1;
        }
    }
}
void criar_grafo(Grafo **G){
    int k=0;
    for(int i=0; i<9;i++){
        for(int j=0;j<9;j++){
            criar_dependencias(G, k, i+(9*j));
        }
        k++;
    }

}
void criar_dependencias(Grafo **G, int i, int vertice){ // i == aresta
    Node *list = (*G)->lista[i].prox;
    // colunas
    for(int k=0;k<9;k++){
        if(list->vertices[k] == -1){
            list->vertices[k] = vertice;
            printf("%d\n", list->vertices[k]);
            return;
        }
    }
}

int verifica_conflitos(Grafo *G){
    return 0;
}

int getPrimProx(Grafo *grafo, int r, int A, int *prim, int *prox){

    for(int i =0;i<81;i++){
        prim[i]=-1;
    }

    for(int i =0;i<9*27;i++){
        prox[i]=-1;
    }
    int i=0;
    for(int a=0; a<27;a++){
        for(int j = 0; j < 9; j++){

                i = a + ( j * A );
                printf("%d aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n",i );
                prox[i] = prim[grafo->lista[a].prox->vertices[j]];
                prim[grafo->lista[a].prox->vertices[j]] = i;
                printf("%d\n", prim[grafo->lista[a].prox->vertices[j]]);

        }
    }
    return 0;
}

int main (){
    Grafo *G;
    int *prim, *prox;

    prim = malloc(81*sizeof(int));
    prox = malloc(9*27*sizeof(int));
    inicia_grafo(&G, 27);

    criar_grafo(&G);
    getPrimProx(G, 9, 27, prim, prox);
    int aux, inicio, fim;
    for(int i=0;i<81;i++){
        printf("%d\n", prim[i]);
        inicio = prox[prim[i]];
        fim = prox[inicio];
        while(fim != -1){
            aux = fim;
            fim = prox[fim];
        }
        printf ("%d %d %d\n", i, inicio, aux);
    }
    return 1;
}