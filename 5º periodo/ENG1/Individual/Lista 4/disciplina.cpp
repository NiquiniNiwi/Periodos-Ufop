#include "disciplina.hpp"

disciplina::disciplina()
{
    this->nome = "";
    this->cargaHoraria = 0;
    this->codigo = "";
}

disciplina::disciplina (string nome, int cargaHoraria, string codigo)
{
    this->nome = nome;
    this->cargaHoraria = cargaHoraria;
    this->codigo = codigo;
}

disciplina::~disciplina () {}

string disciplina::getNome () {
    return this->nome;
}

int disciplina::getCargaHoraria () {
    return this->cargaHoraria;
}

string disciplina::getCodigo () {
    return this->codigo;
}

void disciplina::setNome (string nome) {
    this->nome = nome;
}

void disciplina::setCargaHoraria (int idade) {
    this->cargaHoraria = cargaHoraria;
}

void disciplina::setCodigo (string cpf) {
    this->codigo = codigo;
}