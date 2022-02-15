#ifndef RECEPICIONISTA_HPP
#define RECEPICIONISTA_HPP

#include <iostream>
#include <string>

class Recepicionista : public Funcionario{
     public:
        Recepicionista(string nome = "", string cpf = "", string rg = "", string endereco = "", string telefone = "", string email = "", string user = "", string senha = "", int id = 0);
        ~Recepicionista();

};


#endif