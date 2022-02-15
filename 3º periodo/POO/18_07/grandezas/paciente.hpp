#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>

using namespace std;

#include "funcionario.hpp"

class Paciente : public Pessoa {
    string pagamentos;

    public:
    Paciente(string="", string="");
    ~Paciente();

    void setPagamentos(string);
    string getPagamentos() const;
};

#endif