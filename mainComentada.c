/*
 Alunos: Isabela Ferreira Scarabelli, Paulo Éder Medeiros Cardoso, Pedro Henrique de Almeida
 Curso: Engenharia de Computação 2° período
 Matéria: Algoritmo e Estrutura de dados 2
 Professor: Ilo Amy Saldanha Rivero
 Data: 14/06/2022
 Algoritmo: Projeto Árvore Binária
 */

/**
 * Lista dinâmica
 */
#include <stdio.h>
#include <stdlib.h>         //Importação de bibliotecas
#include <locale.h>
#include "arvorebinaria.h"

#define bool   short
#define true   1
#define false  0

//Célula
typedef struct Celula {
	int elemento;        // Elemento inserido na celula.
	struct Celula* prox; // Aponta a celula prox.
} Celula;

Celula* novaCelula(int elemento) {
   Celula* nova = (Celula*) malloc(sizeof(Celula));
   nova->elemento = elemento;
   nova->prox = NULL;
   return nova;
}

//A lista de fato 
Celula* primeiro;
Celula* ultimo;


/**
 * Cria uma lista sem elementos.
 */
void startLista () {
   primeiro = novaCelula(-1);
   ultimo = primeiro;
}


/**
 * Insere um elemento na primeira posicao da lista.
 */
void inserirInicio(int x) {
   Celula* tmp = novaCelula(x);
   tmp->prox = primeiro->prox;
   primeiro->prox = tmp;
   if (primeiro == ultimo) {
      ultimo = tmp;
   }
   tmp = NULL;
}

/**
 * Insere um elemento na ultima posicao da lista.
 */
void inserirFim(int x) {
   ultimo->prox = novaCelula(x);
   ultimo = ultimo->prox;
}


/**
 * Remove um elemento da primeira posicao da lista.
 */
int removerInicio() {
   if (primeiro == ultimo) {
      printf("Erro ao remover!");
   }

   Celula* tmp = primeiro;
   primeiro = primeiro->prox;
   int resp = primeiro->elemento;
   tmp->prox = NULL;
   free(tmp);
   tmp = NULL;
   return resp;
}


/**
 * Remove um elemento da ultima posicao da lista
 */
int removerFim() {
   if (primeiro == ultimo) {
      printf("Erro ao remover!");
   }

   // Caminhar ate a penultima celula:
   Celula* i;
   for(i = primeiro; i->prox != ultimo; i = i->prox);

   int resp = ultimo->elemento;
   ultimo = i;
   free(ultimo->prox);
   i = ultimo->prox = NULL;

   return resp;
}


/**
 * Calcula e retorna o tamanho da lista.
 */
int tamanho() {
   int tamanho = 0;
   Celula* i;
   for(i = primeiro; i != ultimo; i = i->prox, tamanho++);
   return tamanho;
}


/**
 * Insere um elemento em uma posicao especifica considerando que o primeiro elemento valido esta na posicao 0.
 */
void inserirLista(int x, int pos) {

   int tam = tamanho();

   if(pos < 0 || pos > tam){
      printf("Erro ao inserir posicao (%d/ tamanho = %d) invalida!", pos, tam);
   } else if (pos == 0){
      inserirInicio(x);
   } else if (pos == tam){
      inserirFim(x);
   } else {
      // Caminhar ate a posicao anterior a inserção
      int j;
      Celula* i = primeiro;
      for(j = 0; j < pos; j++, i = i->prox);

      Celula* tmp = novaCelula(x);
      tmp->prox = i->prox;
      i->prox = tmp;
      tmp = i = NULL;
   }
}


/**
 * Remove um elemento de uma posicao especifica da lista considerando que o primeiro elemento valido esta na posição 0.
 */
int removerLista(int pos) {
   int resp;
   int tam = tamanho();

   if (primeiro == ultimo){
      printf("Erro ao remover (vazia)!");
   } else if(pos < 0 || pos >= tam){
      printf("Erro ao remover posicao (%d/ tamanho = %d) invalida!", pos, tam);
   } else if (pos == 0){
      resp = removerInicio();
   } else if (pos == tam - 1){
      resp = removerFim();
   } else {
      // Caminhar ate a posicao anterior a inserção
      Celula* i = primeiro;
      int j;
      for(j = 0; j < pos; j++, i = i->prox);

      Celula* tmp = i->prox;
      resp = tmp->elemento;
      i->prox = tmp->prox;
      tmp->prox = NULL;
      free(tmp);
      i = tmp = NULL;
   }
   return resp;
}


/**
 * Mostra os elementos da lista separados por espaços.
 */
void mostrar() {
   printf("[ ");
   Celula* i;
   for (i = primeiro->prox; i != NULL; i = i->prox) {
      printf("%d ", i->elemento);
   }
   printf("] \n");
}


/**
 * Procura um elemento e retorna se ele existe.
 */
bool pesquisarLista(int x) {
   bool retorno = false;
   Celula* i;

   for (i = primeiro->prox; i != NULL; i = i->prox) {
      if(i->elemento == x){
         retorno = true;
         i = ultimo;
      }
   }
   return retorno;
}


int main(int argc, char** argv) {
   setlocale(LC_ALL,"");
   int x1, x2, x3, x4, x5, x6, x7, x8, x9, x10;
   No* no;
   int pos = 0;

   startLista();

   inserir(1);
   inserir(0);
   inserir(4);
   inserir(5);
   inserir(2);
   inserir(3);
   inserir(6);
   inserir(-1);
   inserir(7);
   inserir(8);

   printf("\n");
   printf("Árvore depois da inserção: \n");
   caminharPre(no);

   x1 = remover(1);
   x2 = remover(0);
   x3 = remover(4);
   x4 = remover(5);
   x5 = remover(2);
   x6 = remover(3);
   x7 = remover(6);
   x8 = remover(-1);
   x9 = remover(7);
   x10 = remover(8);

   inserirLista(x1, pos);
   pos++;
   inserirLista(x2, pos);
   pos++;
   inserirLista(x3, pos);
   pos++;
   inserirLista(x4, pos);
   pos++;
   inserirLista(x5, pos);
   pos++;
   inserirLista(x6, pos);
   pos++;
   inserirLista(x7, pos);
   pos++;
   inserirLista(x8, pos);
   pos++;
   inserirLista(x9, pos);
   pos++;
   inserirLista(x10, pos);

   printf("\n");
   printf("Lista depois da inserção: \n");
   mostrar();

   return 0;
}
