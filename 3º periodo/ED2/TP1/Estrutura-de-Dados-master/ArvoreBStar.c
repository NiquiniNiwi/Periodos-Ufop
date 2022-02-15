#include"headers/ArvoreBStar.h"
#define MM 4

typedef enum {Interna, Externa} TipoIntExt;

struct TipoPagina{
    TipoIntExt Pt;
    union {
        //nós de arvore
        struct {
            int ni;
            long ri[MM];
            TipoApontador* pi[MM + 1];
        } U0;
        //nó de registros
        struct {
            int ne;
            Registro * re[MM * 2];
        } U1;
    } UU;
};

void inicializaBStar (TipoApontador ap){
    ap = NULL;
}

int pesquisaBStar(Registro ** r, TipoApontador * Ap){
    int i;
    TipoApontador Pag = *Ap;
    if ((*Ap)->Pt == Interna){
        i = 1;
        while(i < Pag->UU.U0.ni && getChaveRegistro(*r) > Pag->UU.U0.ri[i-1]){
            i++;
        }
        if(getChaveRegistro(*r) < Pag->UU.U0.ri[i-1]){
            return pesquisaBStar(r, Pag->UU.U0.pi[i-1]);
        }else{
            return pesquisaBStar(r, Pag->UU.U0.pi[i]);
        }
    }else{
        i = 1;
        while(i < Pag->UU.U1.ne && getChaveRegistro(*r) > getChaveRegistro(Pag->UU.U1.re[i-1])){
            i++;
        }
        if(getChaveRegistro(*r) == getChaveRegistro(Pag->UU.U1.re[i-1])){
            transferencia(*r, Pag->UU.U1.re[i-1]);
            return 1;
        } 
        return 0;
    }
}

/* */
void insBStar(Registro * r, TipoApontador * Ap, short *cresceu, long *regRetorno, TipoApontador ** apRetorno){
    int i,j;
    //Chegando no nó folha
    TipoApontador Pag = *Ap;
    TipoApontador * ApTemp = NULL;
    if ((*Ap)->Pt == Externa){
        //Se folha estiver cheia, separa
        if((*Ap)->UU.U1.ne == (MM *2)){
            ApTemp = malloc(sizeof(TipoPagina));
            (*ApTemp)->UU.U1.re[0] = r;
            for(int j = (MM + 2); j < (MM*2); j++) insNaPaginaBStar(r, ApTemp);
            *cresceu = 1;
        }else{
            insNaPaginaBStar(r, ApTemp);
            return;
        }
    }else{
        i = 1;
        while(i < Pag->UU.U0.ni && getChaveRegistro(r) > Pag->UU.U0.ri[i-1]){
            i++;
        }
        if(getChaveRegistro(r) < Pag->UU.U0.ri[i-1]){
            insBStar(r, Pag->UU.U0.pi[i-1], cresceu, regRetorno, apRetorno);
        }else{
            insBStar(r, Pag->UU.U0.pi[i], cresceu, regRetorno, apRetorno);
        }

        if(!(*cresceu)) return;

        if ((*Ap)->UU.U0.ni < (MM * 2)){
            insereNaPag(Ap, getChaveRegistro((*Ap)->UU.U1.re[MM]), *apRetorno);
            *cresceu = 0;
            return;
        }

        ApTemp = malloc(sizeof(TipoPagina));
        (*ApTemp)->UU.U0.ni = 0;
        (*ApTemp)->UU.U0.pi[0] = NULL;

        if(i < (MM + 1)){
            insereNaPag(ApTemp, Pag->UU.U0.ri[(2 * MM)-1], Pag->UU.U0.pi[2 * MM]);
            Pag->UU.U0.ni--;
            insereNaPag(&Pag, *regRetorno, *apRetorno);
        }else{
            insereNaPag(ApTemp, *regRetorno, *apRetorno);
        }

        for(j = MM + 2; j<= (2 * MM); j++){
            insereNaPag(ApTemp, Pag->UU.U0.ri[j-1], Pag->UU.U0.pi[j]);
        }

        Pag->UU.U0.ni = MM;
        (*ApTemp)->UU.U0.pi[0] = Pag->UU.U0.pi[MM + 1];
        *regRetorno = getChaveRegistro(Pag->UU.U1.re[MM]);
        *apRetorno = ApTemp;
    }
}

void insereNaPag(TipoApontador * ap, long chave, TipoApontador * apDir){
    int k = (*ap)->UU.U0.ni;

    while (k > 0){
        if(chave >= (*ap)->UU.U0.ri[k-1]){
            k = 0;
            break;
        }

        (*ap)->UU.U0.ri[k] = (*ap)->UU.U0.ri[k - 1];
        (*ap)->UU.U0.pi[k + 1] = (*ap)->UU.U0.pi[k];
        k--;
    }

    (*ap)->UU.U0.ri[k] = chave;
    (*ap)->UU.U0.pi[k + 1] = apDir;
    (*ap)->UU.U0.ni++;
}

/*Uma vez que a página tem espaço, essa função coloca o registro nela*/
void insNaPaginaBStar(Registro * reg, TipoApontador * ap){
    int k = (*ap)->UU.U1.ne;

    while (k > 0){
        if(getChaveRegistro(reg) >= getChaveRegistro((*ap)->UU.U1.re[k-1]))break;
        (*ap)->UU.U1.re[k] = (*ap)->UU.U1.re[k-1];
        k--;
    }
    transferencia(reg, (*ap)->UU.U1.re[k]);
    (*ap)->UU.U1.ne++;
}

void insereArvoreBStar(Registro * r, TipoApontador *ap){
    short cresceu;
    long regRetorno;
    TipoApontador * apRetorno, apTemp;

    insBStar(r, ap, &cresceu, &regRetorno,&apRetorno);

    if(cresceu){
        apTemp = malloc(sizeof(TipoApontador));
        apTemp->UU.U0.ni = 1;
        apTemp->UU.U0.ri[0] = regRetorno;
        apTemp->UU.U0.pi[1] = apRetorno;
    }
}
