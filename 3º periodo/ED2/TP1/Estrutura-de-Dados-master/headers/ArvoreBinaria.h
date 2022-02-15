#ifndef BINARIO_H
#define BINARIO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Registros.h"

typedef struct no no;
typedef struct no *arvore;

void imprimi (arvore r);
no* busca(int chave, no* arvore);
no* cria_arquivo(no *r, FILE* arq);
void destroi(arvore r);
arvore* cria();
int main_binaria(FILE* arq, int chave, Registro ** f);
#endif