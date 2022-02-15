#include "Agendaa.h++"
#include "Especialista.h++"
#include <iostream>
#include <string>

Especialista :: Agenda(){}
Especialista :: ~Agenda(){}

void setAll(int consultas, string data, string cliente){

}

void setData(string data){
    this->data.pushback(data);
}

vector<string> getData(Agenda agenda){
    return agenda.data;
}

void setCliente(string cliente){
    this->cliente.pushback(cliente)
}

vector<string> getCliente(Agenda agenda){
    return agenda.cliente;
}

void setCosultas(int consultas){
    this->consultas = consultas;
}

int getConsultas(Agenda agenda){
    return agenda.consultas;
}
        
void printAgenda(Agenda agenda){
    for(int i = 0; i < agenda.consultas; i++){
        cout << agenda.data[i] << "\n";
        cout << agenda.cleinte[i] << "\n";
    }
}

void adConsulta(Agenda agenda, string data, string cliente){
    agenda.consultas++;
    agenda.data.pushback(data);
    agenda.cliente.pushback(cliente);
}