#ifndef ESPECIALISTA_HPP
#define ESPECIALISTA_HPP

#include <iostream>
#include <string>

#include "Funcionario.h"

class Assistente: public Funcionario{
    Especialista* especialista;
    public:
        Assistente(string nome = "", string cpf = "", string rg = "", string endereco = "", string telefone = "", string email = "", string user = "", string senha = "", int id = 0);
        ~Assistente();

        void setAssAssistente(Especialista);
        Especialista getAssAssistente(Assistente);

        friend class Especialista;
};


#endif