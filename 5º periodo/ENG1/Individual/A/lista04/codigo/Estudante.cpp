#include "Estudante.h"

using namespace std;

// Construtor e Destrutor
Estudante::Estudante(){}
Estudante::Estudante(string mat, string nome, double nota):matricula(mat), nome(nome), nota(nota){}
Estudante::~Estudante(){}

// Setters e Getters
void Estudante::setMatricula(string matricula){
    this->matricula = matricula;
}

string Estudante::getMatricula(){
    return matricula;
}

void Estudante::setNome(string nome){
    this->nome = nome;
}

string Estudante::getNome(){
    return nome;
}

void Estudante::setNota(double nota){
    this->nota = nota;
}

double Estudante::getNota(){
    return nota;
}

ostream& operator<<(ostream& os, const Estudante& e){
    os << "Nome     : " << e.nome << "\n";
    os << "Matricula: " << e.matricula << "\n";
    os << "Nota     : " << e.nota << "\n";

    return os;
}

bool Estudante::operator<(const Estudante& e) const{
    return this->nota < e.nota;
}
bool Estudante::operator>(const Estudante& e) const{
    return this->nota > e.nota;
}
bool Estudante::operator<=(const Estudante& e) const{
    return this->nota <= e.nota;
}
bool Estudante::operator>=(const Estudante& e) const{
    return this->nota >= e.nota;
}
bool Estudante::operator==(const Estudante& e) const{
    return this->nota == e.nota;
}
bool Estudante::operator==(int x) const{
    return this->nota == x;
}
bool Estudante::operator==(float x) const{
    return this->nota == x;
}
bool Estudante::operator==(double x) const{
    return this->nota == x;
}
int Estudante::operator+(int x) {
    return this->nota + x;
}
float Estudante::operator+(float x) {
    return this->nota + x;
}
double Estudante::operator+(double x) {
    return this->nota + x;
}