#ifndef DISCIPLINA_HPP
#define DISCIPLINA_HPP
#include "disciplina.hpp"

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class disciplina{
    private:
        
        string nome;
        int cargaHoraria;
        string codigo;

    public:

        disciplina();
        disciplina (string nome, int cargaHoraria, string codigo);
        ~disciplina();

        string getNome();
        int getCargaHoraria();
        string getCodigo();
        void setNome (string);
        void setCargaHoraria (int);
        void setCodigo (string);
};

#endif
