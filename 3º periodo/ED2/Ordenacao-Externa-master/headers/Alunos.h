#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct aluno Aluno;
Aluno * criaAluno(int matricula, float nota, char estado [2], char cidade [50], char curso[50]);
int getSizeAluno();
float getNota(Aluno * aluno);
void desalocaAluno (Aluno * aluno);
void toString(Aluno * aluno);
void toCidade(Aluno * aluno);
