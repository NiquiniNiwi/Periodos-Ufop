#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <cstdlib>

using namespace std;

class System {
    protected:
        string name; //nome do bloco P
        double value; //valor do bloco P
    public:
        /**
         * @brief Construtor do bloco P
         */
        System();
        System(string,double);

        /**
         * @brief Destrutor do bloco P
         */
        virtual ~System();

        /**
         * @brief "Seta" um nome para o bloco P
         * @param name Nome do bloco P
         */
        void setName(string);

        /**
         * @brief "Seta" um valor para o bloco P
         * @param value Valor do bloco P
         */
        void setValue(double);

        /** @brief Funções de retorno de valores
         *
         * @return Retorna o valor do bloco P
         */
        double getValue();

        /**
         * @return Retorna o nome do bloco P
         */
        string getName();

        /**
         * @brief Função para sobrecarregar operator =
         * @param System pointeiro de um bloco P
         * @return um ponteiro do um bloco P
         */
        System* operator=(System*);
};

#endif