#ifndef LISTA_H
#define LISTA_H

typedef struct nodo Nodo;

Nodo* cria_lista();
Nodo* insere_lista(Nodo* lista, int valor);
Nodo* remove_lista(Nodo* lista, int valor);
void imprime_lista(Nodo* lista);
Nodo* reseta_lista(Nodo* lista);
int vazio(Nodo* lista);
Nodo* valor_proximo(Nodo* lista);
Nodo* busca_valor(Nodo* lista, int valor);
Nodo* elemento_central(Nodo* lista);
Nodo* reverte_k_nos(Nodo* lista, int k);


#endif
