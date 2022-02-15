#ifndef CONSULTA_HPP
#define CONSULTA_HPP

#include <iostream>
#include <string>
#include <vector>

#include "../tool.hpp"

#include "../agenda/agenda.hpp"
#include "../grandezas/paciente.hpp"

typedef std::multimap<string, string> Consulta;

using namespace std;

void receberConsulta(vector<Agenda> agenda, Consulta *consultas);
void printConsultasPagasRecentes(Consulta *consultas);
void addConsulta(Consulta *consultas, string nome, string data);

#endif