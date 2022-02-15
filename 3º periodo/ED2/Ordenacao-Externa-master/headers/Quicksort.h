#ifndef QUICK_H
#define QUICK_H
    #include <stdio.h>
    #include <stdlib.h>
    #include "Alunos.h"
    /* Structs */
    typedef struct tipoArea TipoArea;
    void LeSup(FILE ** ArqLes, Aluno ** UltLido, int * Ls, short * OndeLer);
    void QuickSortExterno(FILE ** ArqLi, FILE ** ArqEi, FILE ** ArqLEs, int Esq, int Dir);
    void LeInf(FILE ** ArqLi, Aluno ** UltLido, int * Li, short * OndeLer);
    void InserirArea(TipoArea ** Area, Aluno ** UltLido, int * NRArea);
    void EscreveMax(FILE ** ArqLes, Aluno * R, int * Es);
    void EscreveMin(FILE ** ArqEi, Aluno * R, int * Ei);
    void RetiraMax(TipoArea ** Area, Aluno ** R, int *NRArea);
    void RetiraMin(TipoArea ** Area, Aluno ** R, int *NRArea);
    void Particao(FILE ** ArqLi, FILE ** ArqEi, FILE ** ArqLEs, TipoArea * Area, int Esq, int Dir, int *i, int *j);
    void InsereItem(Aluno * aluno, TipoArea * area);
    int ObterNumCelOcupadas(TipoArea * area);
    void FAVazia(TipoArea ** Area);
    void RetiraUltimo(TipoArea ** Area, Aluno ** R);
    void RetiraPrimeiro(TipoArea ** Area, Aluno ** R);
#endif