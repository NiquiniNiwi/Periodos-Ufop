#ifndef FUNCOES_H
#define FUNCOES_H

#include <iostream>
#include "Desordenada.h"
#include "Ordenada.h"

using namespace std;

template <class T, typename U>
U count(T& estrutura, U& valor){
    int qntd = estrutura.size();
    int counter = 0;
    for(int i = 0; i < qntd; i++){
        if (estrutura[i] == valor){
            counter++;
        }
    }
    return counter;

}

template <class T, typename U>
U sum(T& estrutura){
    int qntd = estrutura.size();
    U soma = 0;

    for(int i = 0; i < qntd; i++){
        soma = estrutura[i] + soma;    
    }

    return soma;
}

template <class T>
double average(T& estrutura){
    int qntd = estrutura.size();
    double soma = 0;

    for(int i = 0; i < qntd; i++){
        soma = estrutura[i] + soma;    
    }

    return soma/qntd;
}

#endif