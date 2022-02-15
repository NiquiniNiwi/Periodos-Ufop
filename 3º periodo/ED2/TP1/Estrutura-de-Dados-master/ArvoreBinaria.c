#include "headers/ArvoreBinaria.h"
#include "headers/Registros.h"

struct no{
    Registro* reg;//valor
    no *direita;//no maior
    no *esquerda;//no menor
};

/*r = arvores, novo = novos nos, chave = valor a ser procurado/inserido/retirardo */

no* busca(int chave, no* arvore){
    if(arvore == NULL || getChaveRegistro(arvore->reg) == chave){
        return arvore;
    }
    if (chave > getChaveRegistro(arvore->reg)){
        return busca(chave, arvore->direita);
    }
    else{
        return busca(chave, arvore->esquerda);
    }
}

void imprimi (arvore r) {
   if (r != NULL) {
      imprimi (r->esquerda);
      printf ("%ld\n", getChaveRegistro(r->reg));
      imprimi (r->direita); 
   }
}

no* cria_arquivo(no *r, FILE* arq){
    int novo;
    if(fread(&novo, sizeof(int),1, arq) == EOF){
        return r;
    }
    else{
        if(novo >= getChaveRegistro(r->reg)){
            r->direita = malloc(sizeof(no*));
            r->direita = NULL;
            r->direita = cria_arquivo(r->direita, arq);
            return r->direita;
        }
        else{
            r->esquerda = malloc(sizeof(no*));
            r->esquerda = NULL;
            r->esquerda = cria_arquivo(r->esquerda, arq);
            return r->esquerda;
        }
    }
}

void destroi(arvore r){
    if(r->direita != NULL){
        destroi(r->direita);
    }
    if(r->esquerda != NULL){
        destroi(r->esquerda);
    }
    free(r);
    return;
}

int main_binaria(FILE* arq, int chave, Registro ** f){
    clock_t time = clock();
    no* r = NULL;
    rewind(arq);
    r = cria_arquivo(r, arq);
    time = clock() - time;
    printf("Tempo de Criação da Arvore Binaria: %lf", ((double)time)/((CLOCKS_PER_SEC/1000)));
    time = clock();
    no* reg = busca(chave, r);
    time = clock() - time;
    printf("Tempo de Pesquisa da Arvore Binaria: %lf", ((double)time)/((CLOCKS_PER_SEC/1000)));
    if(reg == NULL)
       return 0;
    else{
        transferencia(*f, reg->reg);
        return 1;
    }
}
