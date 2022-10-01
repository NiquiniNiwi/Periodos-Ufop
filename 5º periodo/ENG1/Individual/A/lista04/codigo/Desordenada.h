#ifndef DESORDENADA_H
#define DESORDENADA_H

#include <iostream>
#include <vector>

#include "Estudante.h"
#include "Disciplina.h"

using namespace std;
template <class T>
class Desordenada{
    protected:
        vector<T> itens;

    public:
        typedef typename vector<T>::iterator iterator;

        Desordenada(){}

        Desordenada(vector<T> t){
            this->itens = t;
        }

        virtual ~Desordenada(){}

        void insert(T t){
            this->itens.push_back(t);
        }

        iterator begin( void ) {return itens.begin();}
        iterator end( void ) {return itens.end();}
        T& operator [] ( int i ){return this->itens[i];}
        int size( void ) {return this->itens.size();}

        void print(){
            for(int i = 0; i < this->itens.size(); i++ ){
                cout << "i = " << i << "\n" << this->itens[i] << "\n";
            }
        }
};

#endif