#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Registro.h"

/* não recebe parametros, cria aloca dinamicamente e retorna um registro  */
Registro* cria_registro()
{
	Registro *A;
	A = malloc(sizeof(Registro));

	return A;
}

/*trata a exclusão de um registro, recebido como parametro */
void deleta_registro(Registro* A)
{
	free(A);
}

/* imprime todos os campos do registro corretamente formatados conforme arquivo .txt de exemplo */
void print_registro(Registro* A)
{
    printf("%8ld\t", A->inscricao);
    printf("%5.1f\t", A->nota);
    printf("%s\t", A->estado);
    printf("%s\t", A->cidade);
    printf("%s\n", A->curso);

}

/* imprime um arquivo de registros com determinada quantidade */
void print_arquivo(FILE* arqb, long QUANTIDADE)
{
	Registro A;
	int cont = 0;

	fseek(arqb, 0, 0);

	/* faz a leitura de registro por registro do arquivo até certa quantidade */
	while(fread(&A, sizeof(Registro), 1, arqb) == 1 && cont < QUANTIDADE)
	{
		print_registro(&A); //imprime registro 
		cont++;
	}
}

/* altera a chave(nota) de um registro */
void set_chave(Registro* A, float x)
{
	A->nota = x;
}

void clear(Registro ** itens){
    for(int i = 0; i < size(itens); i++){
        free(itens[i]);
    }
}

int size(Registro ** itens){
    int size = sizeof(itens)/sizeof(Registro);
    return size;
}

void popBack(Registro ** itens){
    free(itens[sizeof(itens) -1]);
}
