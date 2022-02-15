#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ITEMPAGINA 4
#define TAM 500

typedef struct registro{
    long chave;
    long dado1;
    char dado2 [500];
}Registro;

typedef struct tipoindice{
    Registro* reg; //valor do indice
    int posicao; //qual posição
}tipoindice;

int pesquisa(long * tab, int tam, long chave, FILE *arq, Registro ** retorno);
void main_sequencial(FILE *arq, long * tabela[500]);
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

void main_sequencial(FILE *arq, long * tabela[TAM]){
    Registro * x; //item a procurar
    int cont;// posicionador e contador
    cont = 0;
    while(fread(&x, sizeof(x), 1, arq) != EOF){
       (*tabela)[cont] = x->chave;//MORREU AQUI
        printf("odio");
       cont++;
    }
    printf("odio");
    fclose(arq);
}

int pesquisa(long * tab, int tam, long chave, FILE *arq, Registro ** retorno){
    Registro * pagina[ITEMPAGINA];//disposição dos itens nas paginas
    int i, quantitens;//variavel auxiliar do loop e quantidade de itens
    long desloc;//deslocamento
    i = 0;
    while (i < tam && tab[i] <= chave)//procura pela pagina onde o item pode se encontrar
        i++;
    if (i == 0 )//caso nao exista no arquivo
        return 0;
    else{     //ultima pagina icompleta
        if(i < tam)
            quantitens = ITEMPAGINA;
        else{
            fseek(arq, 0, SEEK_END);
            quantitens = (ftell(arq)/sizeofRegistro()) % ITEMPAGINA;
        } 
        //le pagina desejada
        desloc = (tab[i-1]) * ITEMPAGINA * sizeofRegistro();
        fseek(arq, desloc, SEEK_SET);
        fread(&pagina, sizeofRegistro(), quantitens, arq);
        //pesquisa na pagina lida
         for (i = 0; i < quantitens; i++){
            if(getChaveRegistro(pagina[i]) == getChaveRegistro(*retorno)){
                *retorno = pagina[i];

                return 1;
            }
        }
        return 0;
    }
}

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

int main(int argc, char * argv[]){
    long ** tabela = malloc(TAM * sizeof(long));
    
    int metodo = atoi(argv[1]);

    int numRegistros = atoi(argv[2]);

    int situacao = atoi(argv[3]);

    long chave = atoi(argv[4]);

    clock_t time;
        
    FILE * registros;
    Registro * r;

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
    fclose(registros);
    registros = fopen("registros.bin","rb");
    time = clock();
    main_sequencial(registros, tabela);
    time = clock() - time;
    printf("Tempo de Criação do Arquivo Sequencial Indexado: %lf", ((double)time)/((CLOCKS_PER_SEC/1000)));
    time = clock();
    if(pesquisa(*tabela, TAM, chave, registros, &r)){
        printf("A chave: %ld foi encontrada", getChaveRegistro(r));
    }
    else{
         printf("A chave: %ld não foi encontrada", getChaveRegistro(r));
    }
    time = clock() - time;
    printf("Tempo de Pesquisa do Arquivo Sequencial Indexado: %lf", ((double)time)/((CLOCKS_PER_SEC/1000)));
    fclose(registros);
    return 0;
}