#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct nodo{
    int valor;
    struct nodo* prox;
};


Nodo* cria_lista(){
    return NULL;
}

Nodo* insere_lista(Nodo* lista, int valor){
    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    novo->valor = valor;
    novo->prox = lista;
    return novo;
}

Nodo* remove_lista(Nodo* lista, int valor){
    Nodo* ant = NULL;
    Nodo* p = lista;
    while(p != NULL && p->valor != valor){
        ant = p;
        p = p->prox;
    }
    // não encontrou o elemento
    if(p == NULL){
        return lista;
    }
    // remove primeiro elemento
    if(ant == NULL){
        lista = p->prox;
    }else{ // se o elemento a ser removido não for o primeiro
        ant->prox = p->prox;
    }
    free(p);
    return lista;
} 

void imprime_lista(Nodo* lista){
    Nodo* p;
    for(p = lista; p != NULL; p = p->prox){
        printf("Valor: %d\n", p->valor);
    }
}

Nodo* reseta_lista(Nodo* lista){
    Nodo* p = lista;
    while(p != NULL){
        Nodo* t = p->prox;
        free(p);
        p = t;
    }
    return NULL;
}

int vazio(Nodo* lista){
    return lista == NULL;
}

Nodo* valor_proximo(Nodo* lista){
    return lista->prox;
}

Nodo* busca_valor(Nodo* lista, int valor){
    Nodo* p;
    for(p = lista; p != NULL; p = p->prox){
        if(p->valor == valor){
            return p;
        }
    }
    return NULL;
}

/*Dada uma lista ligada individualmente, implemente um algoritmo
em C que encontre o elemento central da lista. Se o número de nós for par, haverá
dois nós intermediários, nesse caso retorne o segundo nó intermediário.*/

Nodo* elemento_central(Nodo* lista){
    Nodo* p = lista;
    Nodo* q = lista;
    while(q != NULL && q->prox != NULL){
        p = p->prox;
        q = q->prox->prox;
    }
    // Se q não é NULL, então a lista tem um número par de elementos
    // e p deve ser movido para o próximo nó para retornar o segundo nó intermediário
    if (q != NULL) {
        p = p->prox;
    }
    return p;
}

/*Dada uma lista de tamanho N, reverta todos os k nós (onde k é uma
entrada para a função) na lista. Se o número de nós não for um múltiplo de k,
então os nós restantes deixados de fora, no final, devem ser considerados como
um grupo e devem ser revertidos.*/

Nodo* reverte_k_nos(Nodo* lista, int k){
    Nodo* p = lista;
    Nodo* q = lista;
    Nodo* ant = NULL;
    Nodo* prox = NULL;
    int i = 0;

    while(q != NULL && i < k){
        q = q->prox;
        i++;
    }
    if(i < k){
        return lista;
    }
    i = 0;
    while(p != NULL && i < k){
        prox = p->prox;
        p->prox = ant;
        ant = p;
        p = prox;
        i++;
    }
    if(prox != NULL){
        lista->prox = reverte_k_nos(prox, k);
    }
    return ant;
}

int main(){

    //1->2->2->4->5->6->7->8
    Nodo* lista = cria_lista();
    lista = insere_lista(lista, 1);
    lista = insere_lista(lista, 2);
    lista = insere_lista(lista, 3);
    lista = insere_lista(lista, 4);
    lista = insere_lista(lista, 5);
    lista = insere_lista(lista, 6);
    
  
    imprime_lista(lista);
    printf("\n");
    Nodo* p = elemento_central(lista);
    printf("Elemento central: %d\n", p->valor);
    printf("\n");
    Nodo* q = reverte_k_nos(lista, 4);
    imprime_lista(q);
    return 0;
}




