#include "funcionario.hpp"

Funcionario::Funcionario(string nome, double salario) : Pessoa(nome), salario(salario) {};
Funcionario::~Funcionario() {};

void Funcionario::setSalario(double salario) {
    this->salario = salario;
}

double Funcionario::getSalario() const {
    return salario;
}
