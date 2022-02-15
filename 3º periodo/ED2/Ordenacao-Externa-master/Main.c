#include "headers/Alunos.h"

int main(){
    FILE * txt = fopen("PROVAO.txt", "r");
    FILE * bin = fopen("PROVAO.bin", "w+b");

    int mat;
    float nota;
    char estado [2];
    char cidade [50];
    char curso [50];
    Aluno * aluno;
    Aluno * teste;

    while(fscanf(txt, "%d %f %s %s %s \n", &mat, &nota, estado, cidade, curso) != EOF){
        aluno = criaAluno(mat, nota, estado, cidade, curso);
        fwrite(aluno, getSizeAluno(), 1, bin);
    }
    
    fclose(txt);
    fclose(bin);
    return 0;
}