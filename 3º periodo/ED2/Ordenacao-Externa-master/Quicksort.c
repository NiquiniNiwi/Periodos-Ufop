#include "headers/Quicksort.h"
#include "headers/Alunos.h"
#include <limits.h>
#define TAM_AREA 3

struct tipoArea{
    Aluno * alunos [TAM_AREA];
};

void QuickSortExterno(FILE ** ArqLi, FILE ** ArqEi, FILE ** ArqLEs, int Esq, int Dir){
    int i, j;
    TipoArea * Area;
    if(Dir - Esq < 1) return;
    
    FAVazia(&Area);
    
    Particao(ArqLi, ArqEi, ArqLEs, Area, Esq, Dir, &i, &j);

    if(i - Esq < Dir - j){
        QuickSortExterno(ArqLi, ArqEi, ArqLEs, Esq, i);
        QuickSortExterno(ArqLi, ArqEi, ArqLEs, j, Dir);
    }else {
        QuickSortExterno(ArqLi, ArqEi, ArqLEs, j, Dir);
        QuickSortExterno(ArqLi, ArqEi, ArqLEs, Esq, i);
    }
}

void FAVazia(TipoArea ** Area){
    for(int i = 0; i < TAM_AREA; i++) desalocaAluno((*Area)->alunos[i]);
}

void LeSup(FILE ** ArqLes, Aluno ** UltLido, int * Ls, short * OndeLer){
    fseek(*ArqLes, (*Ls - 1) * getSizeAluno(), SEEK_SET);
    fread(*UltLido, getSizeAluno(), 1, *ArqLes);
    (*Ls)--;
    *OndeLer = 0;
}

void LeInf(FILE ** ArqLi, Aluno ** UltLido, int * Li, short * OndeLer){
    fread(*UltLido, getSizeAluno(), 1, *ArqLi);
    (*Li)++;
    *OndeLer = 1;
}

void InserirArea(TipoArea ** Area, Aluno ** UltLido, int * NRArea){
    InsereItem(*UltLido, *Area);
    *NRArea = ObterNumCelOcupadas(*Area);
}

void InsereItem(Aluno * aluno, TipoArea * area){
    int i = 0;
    while(getNota(aluno) < getNota(area->alunos[i])) i++;
    for(int j = ObterNumCelOcupadas(area); j > i; j--){
        area->alunos[j] = area->alunos[j-1];
    }
    area->alunos[i] = aluno;
}

int ObterNumCelOcupadas(TipoArea * area){
    int i = 1;
    while(area->alunos[i-1] != NULL)i++;
    return i;
}

void EscreveMax(FILE ** ArqLes, Aluno * R, int * Es){
    fseek(*ArqLes, (*Es -1) * getSizeAluno(), SEEK_SET);
    fwrite(&R, getSizeAluno(), 1, *ArqLes);
    (*Es)--;
}

void EscreveMin(FILE ** ArqEi, Aluno * R, int * Ei){
    fwrite(&R, getSizeAluno(), 1, *ArqEi);
    (*Ei)++;
}

void RetiraMax(TipoArea ** Area, Aluno ** R, int *NRArea){
    RetiraUltimo(Area, R);
    *NRArea = ObterNumCelOcupadas(*Area);
}

void RetiraMin(TipoArea ** Area, Aluno ** R, int *NRArea){
    RetiraPrimeiro(Area, R);
    *NRArea = ObterNumCelOcupadas(*Area);
}

void RetiraPrimeiro(TipoArea ** Area, Aluno ** R){
    *R = (*Area)->alunos[TAM_AREA];
    desalocaAluno((*Area)->alunos[TAM_AREA]);
    
    for(int i = 0; i < ObterNumCelOcupadas(*Area) -1; i++){
        (*Area)->alunos[i] = (*Area)->alunos[i+1];
    }
}

void RetiraUltimo(TipoArea ** Area, Aluno ** R){
    *R = (*Area)->alunos[TAM_AREA];
    desalocaAluno((*Area)->alunos[TAM_AREA]);
}

void Particao(FILE ** ArqLi, FILE ** ArqEi, FILE ** ArqLEs, TipoArea * Area, int Esq, int Dir, int *i, int *j){
    int Ls = Dir, Es = Dir, Li = Esq, Ei = Esq;
    int NRArea = 0, LInf = INT_MIN, LSup = INT_MAX;
    short OndeLer = 1;
    Aluno * UltLido, *R;
    fseek(*ArqLi, (Li-1)*getSizeAluno(), SEEK_SET);
    fseek(*ArqEi, (Ei-1)*getSizeAluno(), SEEK_SET);
    *i = Esq - 1;
    *j = Dir + 1;

    while(Ls >= Li){
        if(NRArea < TAM_AREA - 1){
            if(OndeLer) LeSup(ArqLEs, &UltLido, &Ls, &OndeLer);
            else LeInf(ArqLi, &UltLido, &Li, &OndeLer);
            InserirArea(&Area, &UltLido, &NRArea);
            continue;
        }

        if(Ls == Es) LeSup(ArqLEs, &UltLido, &Ls, &OndeLer);
        else if(Li == Ei) LeInf(ArqLi, &UltLido, &Li, &OndeLer);
        else if(OndeLer) LeSup(ArqLEs, &UltLido, &Ls, &OndeLer);
        else LeInf(ArqLi, &UltLido, &Li, &OndeLer);

        if(getNota(UltLido) > LSup){
            *j = Es;
            EscreveMax(ArqLEs, UltLido, &Es);
            continue;
        }

        if(getNota(UltLido) < LInf){
            *i = Ei;
            EscreveMin(ArqEi, UltLido, &Ei);
            continue;
        }

        InserirArea(&Area, &UltLido, &NRArea);

        if(Ei - Esq < Dir - Es){
            RetiraMin(&Area, &R, &NRArea);
            EscreveMin(ArqEi, R, &Ei);
            LInf = getNota(R);
        }else{
            RetiraMax(&Area, &R, &NRArea);
            EscreveMax(ArqLEs, R, &Es);
            LSup = getNota(R);
        }
    }

    while(Ei <= Es){
        RetiraMin(&Area, &R, &NRArea);
        EscreveMin(ArqEi, R, &Ei);
    }

}