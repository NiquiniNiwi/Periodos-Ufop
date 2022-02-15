#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/ArvoreB.h"
#include "headers/ArvoreBStar.h"
#include "headers/ASI.h"
#include "headers/ArvoreBinaria.h"
#include <time.h>

#define TAM 500

int main(int argc, char * argv[]){
    //Verificando a quantidade de parametros
    if(argc < 5) {
        printf("Faltou algum parametro!\n");
        return 0;
    }else if(argc > 6){
        printf("Sobrou parametros\n");
        return 0;
    }
    long ** tabela = malloc(TAM * sizeof(long));
    
    int metodo = atoi(argv[1]);

    int numRegistros = atoi(argv[2]);

    int situacao = atoi(argv[3]);

    long chave = atoi(argv[4]);

    clock_t time;
        
    FILE * registros;
    Registro * r;
    TipoApontador * ap = NULL;
    
    TPointer arvoreB;

    //Criando o arquivo
    switch(situacao){
        case 1: //Arquivos Ordenados Ascendentemente
            registros = criaRegistrosASC(numRegistros);
            break;
        case 2: //Arquivos Ordenados Descendentemente
            registros = criaRegistrosDESC(numRegistros);
            break;
        case 3: //Arquivos Desordenados Aleatoriamente
            //Falta terminar arquivos randomicos
            registros = criaRegistrosRAN(numRegistros);
            break;
        default:
            printf("O parametro para o número de arquivos foi passado incorretamente!\n");
            return 0;
    }

    switch (metodo){
        case 1:
            time = clock();
            main_sequencial(registros, tabela);
            time = clock() - time;
            printf("Tempo de Criação do Arquivo Sequencial Indexado: %lf", ((double)time)/((CLOCKS_PER_SEC/1000)));
            time = clock();
             if(pesquisa(*tabela, TAM, chave, registros, &r)){
                printf("A chave: %ld foi encontrada", getChaveRegistro(r));
            }else{
                printf("A chave: %ld não foi encontrada", getChaveRegistro(r));
            }
            time = clock() - time;
            printf("Tempo de Pesquisa do Arquivo Sequencial Indexado: %lf", ((double)time)/((CLOCKS_PER_SEC/1000)));
            if(argc == 6)listaRegistros(registros, numRegistros);
            break;  
        case 2:
            //Árvore Binaria de Pesquisa
            if(main_binaria(registros, chave, &r))
                printf("A chave: %ld foi encontrada", getChaveRegistro(r));
            else
                printf("A chave: %ld não foi encontrada", getChaveRegistro(r));
            if(argc == 6)listaRegistros(registros, numRegistros);
            break;
        case 3:
            //Árvore B
            inicializa(arvoreB);
            time = clock();
            insercaoTP(&arvoreB, registros);
            time = clock() - time;
            printf("Tempo de Criação da árvore B: %lf", ((double)time)/((CLOCKS_PER_SEC/1000)));
            
            time = clock();
            pesquisaTP(chave, &arvoreB);
            time = clock() - time;
            printf("Tempo de Pesquisa da árvore B: %lf", ((double)time)/((CLOCKS_PER_SEC/1000)));
            //Liberando a memória
            encerra(arvoreB);
            if(argc == 6)listaRegistros(registros, numRegistros);
        case 4:
            while (fread(r, sizeofRegistro(),1, registros) != EOF){
                registros = fopen("registros.bin", "rb");
                fread(r, sizeofRegistro(),1, registros);
                insereArvoreBStar(r, ap);
            }
            setChaveRegistro(r, chave);
            if(pesquisaBStar(&r, ap)){
                printf("A chave: %ld foi encontrada", chave);
                toString(r);
            }else{
                printf("A chave: %ld não foi encontrada", chave);
            }

            if(argc == 6)listaRegistros(registros, numRegistros);
            break;
        default:
            printf("Método Inválido!");
            return 1;
    }
    return 0;
}
