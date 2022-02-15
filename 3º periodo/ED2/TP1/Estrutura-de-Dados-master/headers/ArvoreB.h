#include <stdio.h>
#include <stdlib.h>

#ifndef ARVOREB_H
#define ARVOREB_H

#define ORDEM_M 10

//--- Definindo tipos ---

typedef long TKey;
typedef struct TRegister TRegister;
typedef struct TPage *TPointer;
typedef struct TPage TPage;

//--------Funções --------

void inicializa(TPointer);
int pesquisaArvoreB(TRegister *, TPointer);
void imprime(TPointer);
void encerra(TPointer);

//Inserção
void ins(TRegister, TPointer, short *, TRegister *, TPointer *);
void insereArvoreB(TRegister, TPointer *);
void insereNaPagina(TPointer, TRegister, TPointer);

//Remoção
void reconstitui(TPointer, TPointer, int, short *);
void antecessor(TPointer, int, TPointer, short *);
void ret(TKey, TPointer *, short *);
void retiraArvoreB(TKey, TPointer *);

//Funções específicas do TP
void insercaoTP(TPointer *, FILE *);
void pesquisaTP(long, TPointer *);

#endif
