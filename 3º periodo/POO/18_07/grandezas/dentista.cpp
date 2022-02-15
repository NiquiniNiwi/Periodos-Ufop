#include <iostream>
#include <string>

#include "dentista.hpp"

Dentista::Dentista(string nome, double salario, Funcionario assistente, int pacientes) : 
    Pessoa(nome), Funcionario(nome, salario), assistente(assistente), pacientes(pacientes) {};

Dentista::~Dentista() {};

void Dentista::setAssistente(Funcionario assistente) {
    this->assistente = assistente;
};

Funcionario Dentista::getAssistente() const {
    return assistente;
};

void Dentista::setPacientes(int pacientes) {
    this->pacientes = pacientes;
};

int Dentista::getPacientes() const {
    return pacientes;
};

