#ifndef MODEL_H
#define MODEL_H

#include "flow.h"

#include <cstring>
#include <vector>

class Model{
    protected:
        vector<Flow*> flows; //Vetor de fluxos
        vector<System*> systems; //Vetor de blocos

    public:
        /**
         * @brief Construtor de modelo
         */
        Model();

        /**
         * @brief Destrutor de modelo
         */
        virtual ~Model();

        /**
         * @brief Função para "rodar" o modelo
         * @param start Valor inicial
         * @param finish Valor final
         * @return Retorna o valor final das operações
         */
        double run(int,int);

        /**
         * @brief Função para adicionar um novo bloco P
         * @param System bloco P a ser adicionado 
         */
        void add(System*);

        /**
         * @brief Função para adicionar um novo fluxo
         * @param Flow fluxo a ser adicionado 
         */
        void add(Flow*);
        
    private:
        /**
         * @brief Função para sobrecarregar operator =
         * @param  Model ponteiro de fluxo
         * @return returna um modelo
         */
        Model* operator=(Model*);
};

#endif