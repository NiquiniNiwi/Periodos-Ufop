#ifndef REG_H
#define REG_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
    typedef struct registro Registro;
    void transferencia(Registro * result, Registro * origem);
    Registro * criaRegistro(int, int, char *);
    long getChaveRegistro(Registro * reg);
    void desalocaRegistro(Registro *);
    FILE * criaRegistrosRAN(int qtd);
    FILE * criaRegistrosDESC(int qtd);
    FILE * criaRegistrosASC(int qtd);
    void listaRegistros(FILE *, int);
    int sizeofRegistro();
    void toString(Registro *);
#endif
