#ifndef ESTUDANTES_HPP
#define ESTUDANTES_HPP
#include "estudantes.hpp"

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class estudantes {
    private:
        string nome;
        int idade;
        int matricula;
        string cpf;

    public:

        estudantes();
        estudantes(string nome, int idade, int matricula, string cpf);
        ~estudantes();
        
        string getNome();
        int getIdade();
        int getMatricula();
        string getCpf();
        void setNome(string);
        void setIdade(int);
        void setMatricula(int);
        void setCpf(string);
};

#endif
