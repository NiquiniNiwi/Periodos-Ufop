#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include <iostream>
#include <string>

using namespace std;

// Definindo a classe estudante
class Estudante{
    protected:
        string matricula;
        string nome;
        double nota;

    public:
        Estudante();
        Estudante(string="", string="", double=0);
        virtual ~Estudante();

        void setMatricula(string matricula);
        string getMatricula();
        
        void setNome(string nome);
        string getNome();
        
        void setNota(double nota);
        double getNota();

        friend ostream& operator<<(ostream& os, const Estudante& e);

        bool operator<(const Estudante& e) const;
        bool operator>(const Estudante& e) const;
        bool operator<=(const Estudante& e) const;
        bool operator>=(const Estudante& e) const;
        bool operator==(const Estudante& e) const;
        
        bool operator==(int x) const;
        bool operator==(float x) const;
        bool operator==(double x) const;
        
        int operator+(int x);
        float operator+(float x);
        double operator+(double x);
};

#endif