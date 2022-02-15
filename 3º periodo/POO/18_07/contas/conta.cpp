#include <iostream>
#include <string>

#include "conta.hpp"

Conta::Conta(string descricao, string dataVencimento, string dataPagamento) : 
    descricao(descricao), dataVencimento(dataVencimento), dataPagamento(dataPagamento) {};

Conta::~Conta() {};

string Conta::getDescricao() const {
    return descricao;
}

void Conta::setDescricao(string descricao) {
    this->descricao = descricao;
}

string Conta::getDataVencimento() const {
    return dataVencimento;
}

void Conta::setDataVencimento(string dataVencimento) {
    this->dataVencimento = dataVencimento;
}

string Conta::getDataPagamento() const {
    return dataPagamento;
}

void Conta::setDataPagamento(string dataPagamento) {
    this->dataPagamento = dataPagamento;
}

void fazerPagamentoContas(vector<Conta> *contas, vector<Conta>::iterator *it) {
    Conta aux;
    limpaTela();
    getc(stdin);

    string description, dataVencimento, dataPagamento;
    cout << endl << "Descricao da conta: " << endl;
    getline(cin, description);
    aux.setDescricao(description);// set descrição

    cout << endl << "Data de vencimento: " << endl;
    getline(cin, dataVencimento);
    aux.setDataVencimento(dataVencimento);// set data de vencimento

    cout << endl << "Data de pagamento: " << endl;
    getline(cin, dataPagamento);
    aux.setDataPagamento(dataPagamento);// set data de pagamento

    (*contas).insert((*it), aux);   
}