#ifndef FLOW_H
#define FLOW_H

#include "system.h"

class Flow{
    protected:
        System* source; // Ponteiro do bloco P fonte
        System* destination; // Ponteiro do bloco P destino
    public:
        /**
         * @brief Construtor de fluxo
         */
        Flow();
        Flow(System*, System*);

        /**
         * @brief Destrutor de fluxo
         */
        virtual ~Flow();

        /**
         * @brief "Seta" bloco P fonte 
         * @param system ponteiro de bloco P
         */
        void setSources(System*);

        /**
         * @brief "Seta" bloco P destino 
         * @param System ponteiro de bloco Pr.
         */
        void setDestination(System*);

        /**
         * @brief Função para retornar bloco P fonte
         * @return Retorna ponteiro do bloco P fonte
         */
        System* getSource();

        /**
         * @brief Função para retornar bloco P destino
         * @return Retorna ponteiro do bloco P destino
         */
        System* getDestination();

        /**
         * @brief Função "Virtual" para rodar o fluxo
         * @return Retorna 0
         */
        virtual double run() = 0;

        /**
         * @brief Função para sobrecarregar operator =
         * @param Flow ponteiro de fluxo
         * @return returna um fluxo
         */
        Flow* operator=(Flow*);
};

class Exponential: public Flow{
    public:
    /**
     * @brief Construtor de um fluxo exponencial 
     */
    Exponential();
    Exponential(System* source, System* destination):Flow(source,destination){};
    
    /**
     * @brief Função para rodar o fluxo
     * @return Retorna o valor da operação efetivada
     */
    double run(){
        return getSource()->getValue()*0.01;
    }
};

class Logistic: public Flow{
    public:
    /**
     * @brief Construtor de um fluxo logistico 
     */
    Logistic();
    Logistic(System* source, System* destination):Flow(source,destination){};
    
    /**
     * @brief Função para rodar o fluxo
     * @return Retorna o valor da operação efetivada
     */
    double run(){
        return getDestination()->getValue()*0.01*(1-(getDestination()->getValue())/70);
    }
};

#endif