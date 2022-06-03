#include "Disciplina.h"

using namespace std;

// Construtor e destrutor
Disciplina::Disciplina(){}
Disciplina::Disciplina(string nome, string codigo, int cargaHoraria):nome(nome), codigo(codigo), cargaHoraria(cargaHoraria){}
Disciplina::~Disciplina(){}


// Setters e Getters
void Disciplina::setNome(string nome){
    this->nome = nome;
}

string Disciplina::getNome(){
    return nome;
}

void Disciplina::setCodigo(string codigo){
    this->codigo = codigo;
}

string Disciplina::getCodigo(){
    return codigo;
}

void Disciplina::setCargaHoraria(int cargaHoraria){
    this->cargaHoraria = cargaHoraria;
}

int Disciplina::getCargaHoraria(){
    return cargaHoraria;   
}

ostream& operator<<(ostream& os, const Disciplina& d){
    os << "Nome        : "<< d.nome << "\n";
    os << "Codigo      : "<< d.codigo << "\n";
    os << "CargaHoraria: "<< d.cargaHoraria << "\n";

    return os;
}

bool Disciplina::operator<(const Disciplina& d) const{
    return this->cargaHoraria < d.cargaHoraria;
}
bool Disciplina::operator>(const Disciplina& d) const{
    return this->cargaHoraria > d.cargaHoraria;
}
bool Disciplina::operator<=(const Disciplina& d) const{
    return this->cargaHoraria <= d.cargaHoraria;
}
bool Disciplina::operator>=(const Disciplina& d) const{
    return this->cargaHoraria >= d.cargaHoraria;
}
bool Disciplina::operator==(const Disciplina& d) const{
    return this->cargaHoraria == d.cargaHoraria;
}
bool Disciplina::operator==(int x) const{
    return this->cargaHoraria == x;
}
bool Disciplina::operator==(float x) const{
    return this->cargaHoraria == x;
}
bool Disciplina::operator==(double x) const{
    return this->cargaHoraria == x;
}
int Disciplina::operator+(int x) {
    return this->cargaHoraria + x;
}
float Disciplina::operator+(float x) {
    return this->cargaHoraria + x;
}
double Disciplina::operator+(double x) {
    return this->cargaHoraria + x;
}