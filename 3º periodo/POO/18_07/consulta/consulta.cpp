#include "consulta.hpp"

void receberConsulta(vector<Agenda> agenda, Consulta *consultas, vector<Paciente> pessoa, vector<Paciente>::iterator *pit){
    double valor;
    int confirmaPagamento;
    string nome, data;
    Paciente aux;
    Consulta::iterator it;
    cout << endl << "Valor: ";
    cin >> valor;
    getc(stdin);
    cout << endl << "aperte '1' + 'enter' para confimar o pagamento, qualquer outro valor cancelara a ação"<< endl;
    cin >> confirmaPagamento;
    getc(stdin);
    if(confirmaPagamento == 1){
        cout << "Pagamento confirmado!" << endl;
        aux.setPagamentos("PG");//Set pagamento para pago
        cout << "Digite o nome do cliente: ";
        getline(cin, nome);
        getc(stdin);
        aux.setNome(nome);//Set nome do cliente da consulta
        cout << "Digite a data: ";
        getline(cin, data);
        getc(stdin);
        addConsulta(consultas, nome, data);
        printConsultasPagasRecentes(consultas); 
        pessoa.insert((*pit),aux);   
    }
    else{
        cout << "Erro ao efetivar o pagamento!" << endl << "Enter parar continuar";
        getc(stdin);
        limpaTela();
    }
}

void printConsultasPagasRecentes(Consulta *consultas){
    Consulta::reverse_iterator it;
    int i = 0;
    for (it = (*consultas).rbegin(); it != (*consultas).rend() && i < 10; it++) {
        cout << it->first << " " << it->second << endl;
        i++;
    }
}

void addConsulta(Consulta *consultas, string nome, string data){
    (*consultas).insert(pair<string, string>(data, nome));
}