// Sistema: Gerenciamento de Concessionaria de Automoveis - AutoMananger
// Modulo: Administracao de Clientes
// Autor: Tiago Garcia de Senna Carneiro
// Ultima alteracao:15/12/2006
// Responsavel: Tiago G. S. Carneiro
//
// Descri��o:  Mant�m cadastro de clientes da concessionaria. Os clientes sao
// identificados pelo nome.
//             
// Servi�os (API): 
//           - Cria novo cliente
//           - Remove cliente
//           - Edita cliente
// Requisitos:
//           -
#include "cliente.h"

#include <cstring>
#include <stdlib.h>

using namespace std;
Cliente::Cliente(char *n){
    if (nome == NULL){
        nome = n;
    }
    else{
        free(nome);
        nome = n;
    }
}
Cliente::~Cliente(){
    delete (this->nome);
}
void Cliente::setNome( char* n  ){
    if (nome == NULL){
        nome = n;
    }
    else{
        free(nome);
        nome = n;
    }
} 
char* Cliente::getNome( void ) { return nome; }

Cliente& Cliente::operator=(Cliente& cliente){
    if (this == &cliente){
        return *this;
    }
    
    delete(this->nome);
    this->nome = new char[strlen(cliente.nome) + 1];
    strcpy(this->nome, cliente.nome);
    return *this;
}