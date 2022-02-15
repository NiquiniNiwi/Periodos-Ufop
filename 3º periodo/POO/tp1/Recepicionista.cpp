#include <iostream>
#include <string>
#include "Recepicionista.h"

Recepicionista:: Recepicionista(){}
Recepicionista:: ~Recepicionista(){}

void Recepicionista::setNomeRecepicionista(string nome){
    NomeR = nome ;
}
void Recepicionista::setSNomeRecepicionista(string snome){
    sNomeR = nome ;
}
string Recepicionista::getNomeRecepicionista(){
    return NomeR;
}
string Recepicionista::getSNomeRecepicionista(){
    return sNomeR;
}