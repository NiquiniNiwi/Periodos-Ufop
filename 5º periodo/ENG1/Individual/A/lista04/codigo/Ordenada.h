#ifndef ORDENADA_H
#define ORDENADA_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#include "Estudante.h"
#include "Disciplina.h"

using namespace std;

template <class T>
class Ordenada{
    protected:
        multimap<int, T> itens;

    public:
        typedef typename multimap<int, T>::iterator iterator;

        //Construtores e destrutores
        Ordenada(){}
        Ordenada(multimap<int, T> t){this->itens = t;}
        virtual ~Ordenada(){}

        // Metodo para insercao de forma ordenada
        void insert(int chave, T t){
            this->itens.insert(pair <int, T> (chave, t));            
        }

        iterator begin( void ) const {
            auto itr = itens.begin();
            return itr->second;
        }
        iterator end( void ) const {
            auto itr = itens.end();
            return itr->second;
        }
        
        T& operator [] ( int i ){
            int qntd = this->itens.size();
            auto itr = this->itens.begin();
            for (int j = 0; j < qntd; j++){
                if (i == j){
                    return itr->second;
                }
                itr++;
            }

            return itr->second; //
        }

        int size( void ){return this->itens.size();}

        void print(){
            int i = 0;
            for (auto itr = this->itens.begin(); itr != this->itens.end(); ++itr){
                cout << "i = " << i++ << "\n" << itr->second << "\n";
            }
        }

};

#endif