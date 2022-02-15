#ifndef CONTAS_HPP
#define CONTAS_HPP

#include <string>
#include <vector>

using namespace std;

#include "../tool.hpp"

class Conta {
    string descricao;

    string dataVencimento;
    string dataPagamento;

    public:
    Conta(string="-", string="-", string="-");
    ~Conta();

    string getDescricao() const;
    void setDescricao(string);

    string getDataVencimento() const;
    void setDataVencimento(string);

    string getDataPagamento() const;
    void setDataPagamento(string);
};

void fazerPagamentoContas(vector<Conta> *contas, vector<Conta>::iterator *it);

#endif