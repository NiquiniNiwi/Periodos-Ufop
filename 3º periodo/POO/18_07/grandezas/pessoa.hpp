#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>

using namespace std;

class Pessoa {
    string nome;

    public:
    Pessoa(string="");
    ~Pessoa();

    void setNome(string);
    string getNome() const;
};

#endif