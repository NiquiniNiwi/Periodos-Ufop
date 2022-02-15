#ifndef DENTISTA_HPP
#define DENTISTA_HPP

#include "funcionario.hpp"

class Dentista : public Funcionario {
    Funcionario assistente;
    int pacientes;

    public:
    Dentista(string="", double=0, Funcionario=Funcionario(), int=0);
    ~Dentista();

    void setAssistente(Funcionario);
    Funcionario getAssistente() const;

    void setPacientes(int);
    int getPacientes() const;
};

#endif