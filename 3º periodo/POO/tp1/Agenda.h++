#ifndef AGENDA_HPP
#define AGENDA_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Agenda : public Pessoa{
    int consultas;
    vector<string> data;
    vextor<string> cliente;
    private:
        void setAll(int, string, string);
        void setData(string);      
        void setCosultas(int);
        void setCliente(string);

        Agenda getAll();
        vector<string> getData(Agenda);
        vector<string> getCliente(Agenda);
        int getConsultas();
        
        void printAgenda(Agenda);
        void adConsulta(Agenda);

    friend class Especialista;
};


#endif