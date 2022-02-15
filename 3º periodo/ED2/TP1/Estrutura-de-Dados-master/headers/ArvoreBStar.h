#ifndef BStarTree_H
#define BStarTree_H
    #include "./Registros.h"
    typedef struct TipoPagina TipoPagina;
    typedef struct TipoPagina* TipoApontador;
    void inicializaBStar (TipoApontador ap);
    int pesquisaBStar(Registro ** r, TipoApontador * Ap);
    void insBStar(Registro * r, TipoApontador * Ap, short *cresceu, long * regRetorno, TipoApontador ** apRetorno);
    void insereNaPag(TipoApontador * ap, long chave, TipoApontador * apDir);
    void insNaPaginaBStar(Registro * reg, TipoApontador * ap);
    void insereBStar(Registro * item, TipoApontador * Ap);    
    void insereArvoreBStar(Registro * r, TipoApontador *ap);
#endif
