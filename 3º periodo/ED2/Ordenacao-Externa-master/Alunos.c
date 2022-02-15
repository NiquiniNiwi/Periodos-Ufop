#include "headers/Alunos.h"
struct aluno{
    int matricula;
    float nota;
    char estado[2];
    char cidade[50];
    char curso[50];
};

Aluno * criaAluno(int matricula, float nota, char * estado, char * cidade, char * curso){
    Aluno * aluno = malloc(sizeof(Aluno));
    aluno->matricula = matricula;
    strcpy(aluno->cidade, cidade);
    //printf("Cidade: %s\n", aluno->cidade);
    aluno->nota      = nota;
    strcpy(aluno->curso, curso);
    strcpy(aluno->estado, estado);
    return aluno;
}

int getSizeAluno(){
    return sizeof(Aluno);
} 

float getNota(Aluno * aluno){
    return aluno->nota;
}

void desalocaAluno (Aluno * aluno){
    free(aluno);
}

void toString(Aluno * aluno){
    printf("Matricula: %d\n", aluno->matricula);
    printf("Nota: %f\n", aluno->nota);
    printf("Estado: %s\n", aluno->estado);
    //printf("Cidade: %s\n", aluno->cidade);
    printf("Curso: %s\n", aluno->curso);
    printf("==========================================\n");
}

void toCidade(Aluno * aluno){
    printf("Cidade: %s\n", aluno->cidade);
}