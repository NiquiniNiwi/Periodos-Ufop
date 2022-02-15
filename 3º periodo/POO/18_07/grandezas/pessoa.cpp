#include "pessoa.hpp"

Pessoa::Pessoa(string nome) : nome(nome) {};
Pessoa::~Pessoa() {};

void Pessoa::setNome(string nome) {
    this->nome = nome;
}

string Pessoa::getNome() const {
    return nome;
}