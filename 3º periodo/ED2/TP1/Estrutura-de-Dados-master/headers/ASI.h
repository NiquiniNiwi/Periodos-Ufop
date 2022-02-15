#ifndef ASI_H
#define ASI_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Registros.h"

#define TAM 500

typedef struct tipoindice tipoindice;
typedef struct tipoitem tipoitem;

int pesquisa(long * tab, int tam, long chave, FILE *arq, Registro ** retorno);
void main_sequencial(FILE *arq, long * tabela[500]);
#endif
