/*
 Alunos: Isabela Ferreira Scarabelli, Paulo Éder Medeiros Cardoso, Pedro Henrique de Almeida
 Curso: Engenharia de Computação 2° período
 Matéria: Algoritmo e Estrutura de dados 2
 Professor: Ilo Amy Saldanha Rivero
 Data: 14/06/2022
 Algoritmo: Projeto Árvore Binária
 */

/**
 * Arvore binária de pesquisa 
 */
#include <stdlib.h>
#include <stdio.h>          //Importação de bibliotecas
#include "arvorebinaria.h"

/*
 * Variavel global
 */
No* raiz;

/**
 * Cria arvore binaria.
 */
void start() {
   raiz = NULL;
}

/**
 * Metodo publico para pesquisar elemento.
 */
bool pesquisar(int x) {
   return pesquisarRec(x, raiz);
}

/**
 * Metodo privado para pesquisar elemento.
 */
bool pesquisarRec(int x, No* i) {
   bool resp;
   if (i == NULL) {
      resp = false;

   } else if (x == i->elemento) {
      resp = true;

   } else if (x < i->elemento) {
      resp = pesquisarRec(x, i->esq);

   } else {
      resp = pesquisarRec(x, i->dir);
   }
   return resp;
}

/**
 * Metodo publico  para exibir elementos.
 */
void caminharCentral() {
   printf("[ ");
   caminharCentralRec(raiz);
   printf("]\n");
}

/**
 * Metodo privado para exibir elementos.
 */
void caminharCentralRec(No* i) {
   if (i != NULL) {
      caminharCentralRec(i->esq);
      printf("%d ", i->elemento);
      caminharCentralRec(i->dir);
   }
}

/**
 * Metodo publico iterativo para exibir elementos.
 */
void caminharPre() {
   printf("[ ");
   caminharPreRec(raiz);
   printf("]\n");
}

/**
 * Metodo privado recursivo para exibir elementos.
 */
void caminharPreRec(No* i) {
   if (i != NULL) {
      printf("%d ", i->elemento);
      caminharPreRec(i->esq);
      caminharPreRec(i->dir);
   }
}

/**
 * Metodo publico para exibir elementos.
 */
void caminharPos() {
   printf("[ ");
   caminharPosRec(raiz);
   printf("]\n");
}

/**
 * Metodo privado para exibir elementos.
 */
void caminharPosRec(No* i) {
   if (i != NULL) {
      caminharPosRec(i->esq);
      caminharPosRec(i->dir);
      printf("%d ", i->elemento);
   }
}

/**
 * Metodo publico iterativo para inserir elemento.
 */
void inserir(int x) {
   inserirRec(x, &raiz);
}

/**
 * Metodo privado recursivo para inserir elemento.
 */
void inserirRec(int x, No** i) {
   if (*i == NULL) {
      *i = novoNo(x);

   } else if (x < (*i)->elemento) {
      inserirRec(x, &((*i)->esq));

   } else if (x > (*i)->elemento) {
      inserirRec(x, &((*i)->dir));

   } else {
      printf("Erro ao inserir!");
   }
}

/**
 * Metodo publico iterativo para remover elemento.
 */
int remover(int x) {
    int aux = x;
   removerRec(x, &raiz);
   return aux;
}

/**
 * Metodo privado recursivo para remover elemento.
 */
void removerRec(int x, No** i) {
   if (*i == NULL) {
      printf("Erro ao remover!");

   } else if (x < (*i)->elemento) {
      removerRec(x, &((*i)->esq));

   } else if (x > (*i)->elemento) {
      removerRec(x, &((*i)->dir));

   } else if ((*i)->dir == NULL) {
      No* del = *i;
      *i = (*i)->esq;
      free(del);

   } else if ((*i)->esq == NULL) {
      No* del = *i;
      *i = (*i)->dir;
      free(del);

   } else {
      antecessor(i, &((*i)->esq));
   }
}

/**
 * Metodo para trocar no removido pelo antecessor.
 */
void antecessor(No** i, No** j) {
   if ((*j)->dir != NULL) {
      antecessor(i, &((*j)->dir));

   } else {
      No* del = *j;
      (*i)->elemento = (*j)->elemento;
      (*j) = (*j)->esq;
      free(del);
   }
}
