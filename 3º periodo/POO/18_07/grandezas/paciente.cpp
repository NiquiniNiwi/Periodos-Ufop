#include "paciente.hpp"

Paciente::Paciente(string nome, string pagamentos) : Pessoa(nome), pagamentos(pagamentos) {};
Paciente::~Paciente() {};

void Paciente::setPagamentos(string) {
    this->pagamentos = pagamentos;
}

string Paciente::getPagamentos() const {
    return pagamentos;
}