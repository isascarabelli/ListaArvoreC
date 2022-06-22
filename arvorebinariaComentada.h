/*
 Alunos: Isabela Ferreira Scarabelli, Paulo Éder Medeiros Cardoso, Pedro Henrique de Almeida
 Curso: Engenharia de Computação 2° período
 Matéria: Algoritmo e Estrutura de dados 2
 Professor: Ilo Amy Saldanha Rivero
 Data: 14/06/2022
 Algoritmo: Projeto Árvore Binária
 */

/**
 * Arvore binária de pesquisa h 
 */

#include "no.h"
#define bool   short        //Importação de bibliotecas
#define true   1
#define false  0

bool pesquisarRec(int, No*);
void caminharCentralRec(No*);
void caminharPreRec(No*);
void caminharPosRec(No*);
void inserirRec(int, No**);
void removerRec(int, No**);
void antecessor(No**, No**);

void start();
bool pesquisar(int);
void caminharCentral();
void caminharPre();
void caminharPos();
void inserir(int);
int remover(int);
