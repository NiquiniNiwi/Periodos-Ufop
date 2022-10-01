#include "estudantes.hpp"

estudantes::estudantes () {
    this->nome = "" ;
    this->idade = 0 ;
    this->matricula = 0 ;
    this->cpf = "";
}

estudantes::estudantes (string nome, int idade, int matricula, string cpf) {
    this->nome = nome;
    this->idade = idade;
    this->matricula = matricula;
    this->cpf = cpf;
}

estudantes::~estudantes(){}

string estudantes::getNome(){
    return this->nome;
}

int estudantes::getIdade(){
    return this->idade;
}

int estudantes::getMatricula(){
    return this->matricula;
}

string estudantes::getCpf(){
    return this->cpf;
}

void estudantes::setNome(string nome){
    this->nome = nome;
}

void estudantes::setIdade(int idade){
    this->idade = idade;
}

void estudantes::setMatricula(int matricula){
    this->matricula = matricula;
}

void estudantes::setCpf(string cpf){
    this->cpf = cpf;
}