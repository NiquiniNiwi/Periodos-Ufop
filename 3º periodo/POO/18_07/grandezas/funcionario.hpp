#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <string>

using namespace std;

#include "pessoa.hpp"

class Pessoa;

class Funcionario : public virtual Pessoa {
    double salario;

    public:
    Funcionario(string="", double=0);
    ~Funcionario();

    void setSalario(double);
    double getSalario() const;
};

#endif