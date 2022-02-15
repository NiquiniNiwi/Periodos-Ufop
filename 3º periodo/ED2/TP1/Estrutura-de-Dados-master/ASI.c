#include "headers/ASI.h"

#define ITEMPAGINA 4
#define TAM 500

struct tipoindice{
    Registro* reg; //valor do indice
    int posicao; //qual posição
};

void main_sequencial(FILE *arq, long * tabela[TAM]){
    Registro * x; //item a procurar
    int cont;// posicionador e contador
    cont = 0;
    while(fread(&x, sizeof(x), 1, arq) != EOF){
       (*tabela)[cont] = getChaveRegistro(x);//MORREU AQUI
       cont++;
    }
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
