#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>
#include <string>

using namespace std;

// Definindo a classe disciplina
class Disciplina{
    protected:
        string nome;
        string codigo;
        int cargaHoraria;

    public:
        Disciplina();
        Disciplina(string="", string="", int=0);
        virtual ~Disciplina();

        void setNome(string nome);
        string getNome();
  
        void setCodigo(string codigo);
        string getCodigo();

        void setCargaHoraria(int cargaHoraria);
        int getCargaHoraria();

        friend ostream& operator<<(ostream& os, const Disciplina& d);

        bool operator<(const Disciplina& e) const;
        bool operator>(const Disciplina& e) const;
        bool operator<=(const Disciplina& e) const;
        bool operator>=(const Disciplina& e) const;
        bool operator==(const Disciplina& e) const;

        bool operator==(int x) const;
        bool operator==(float x) const;
        bool operator==(double x) const;

        int operator+(int x);
        float operator+(float x);
        double operator+(double x);
};

#endif