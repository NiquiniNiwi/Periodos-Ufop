#ifndef ESPECIALISTA_HPP
#define ESPECIALISTA_HPP

#include <iostream>
#include <string>
#include "Assistente.h"
#include "Funcionario.h"
#include "Agenda.h"

class Especialista: public Funcionario, public Assistente{
    private:
        Agenda agenda;
        Assistente* assistente;
    public:
        Especialista(string nome = "", string cpf = "", string rg = "", string endereco = "", string telefone = "", string email = "", string user = "", string senha = "", int id = 0);
        ~Especialista();

        void setAgenda(Agenda);
        Agenda getAgenda(Especialista);

        void setAssAssistente(Assistente);
        Assistente getAssAssistente(Especialista);

        friend class Assistente;
};


#endif