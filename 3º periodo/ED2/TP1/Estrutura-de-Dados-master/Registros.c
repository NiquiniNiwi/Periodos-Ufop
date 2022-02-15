#include "headers/Registros.h"

struct registro{
    long chave;
    long dado1;
    char dado2 [500];
};

Registro * criaRegistro(int chave, int d1, char * d2){
    Registro * reg = malloc(sizeof(Registro));
    reg->chave = chave;
    reg->dado1 = d1;
    strcpy(reg->dado2, d2);
    return reg;
}

void desalocaRegistro(Registro * reg){
    free(reg);
}

long getChaveRegistro(Registro * reg){
    return reg->chave;
}

FILE * criaRegistrosASC(int qtd){
    FILE * file;
    if ((file = fopen("registros.bin","w+b")) == NULL) {
        printf("Arquivo nao pode ser aberto...");
        return 0;
    }

    for(int i = 0; i < qtd; i++){
        Registro * reg = criaRegistro(i, rand() % qtd, "OLA");
        fwrite(reg, sizeof(Registro), 1, file);
        desalocaRegistro(reg);
    }

    return file;
}

void transferencia(Registro * result, Registro * origem){
    result->chave = origem->chave;
    result->dado1 = origem->dado1;
    strcpy(result->dado2, origem->dado2);
}

FILE * criaRegistrosDESC(int qtd){
    FILE * file;
    if ((file = fopen("registros.bin","w+b")) == NULL) {
        printf("Arquivo nao pode ser aberto...");
        return 0;
    }

    for(int i = qtd; i >=0; i--){
        Registro * reg = criaRegistro(i, rand() % qtd, "OLA");
        fwrite(reg, sizeof(Registro), 1, file);
        desalocaRegistro(reg);
    }

    return file;
}

FILE * criaRegistrosRAN(int qtd){
    FILE * file;
    if ((file = fopen("registros.bin","w+b")) == NULL) {
        printf("Arquivo nao pode ser aberto...");
        return 0;
    }

    for(int i = 0; i < qtd; i++){
        Registro * reg = criaRegistro(rand() % qtd, rand() % qtd, "OLA");
        fwrite(reg, sizeof(Registro), 1, file);
        
        //fseek(file, sizeof(Registro) * (rand() % (i + 2)), SEEK_SET); //Só testando.
        
        desalocaRegistro(reg);
    }

    return file;
}

void toString(Registro * reg){
    printf("Chave -> %ld\n", reg->chave);
    printf("Dado1 -> %ld\n", reg->dado1);
    printf("Dado2 -> %s\n", reg->dado2);
    printf("===============================\n");
}

int sizeofRegistro(){
    return sizeof(Registro);
}

void listaRegistros(FILE * reg, int qtd){
    rewind(reg);
    Registro * r;
    while(feof(reg) == 0){
        fread(r,sizeof(Registro), 1, reg);
        toString(r);
    }
}
