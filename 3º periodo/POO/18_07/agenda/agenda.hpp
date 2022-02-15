#ifndef AGENDA_HPP
#define AGENDA_HPP

#include <string>
#include <map>
#include <vector>

using namespace std;

typedef std::multimap<string, string> Agenda;

#include "../tool.hpp"

#include "../grandezas/funcionario.hpp"
#include "../grandezas/dentista.hpp"
#include "../folhaPonto/folhaPonto.hpp"

void menuAgenda(vector<Agenda> agenda, Dentista *dent);
void editAgenda(Agenda *agenda, string nome);
void printAgenda(Agenda *agenda);
void addToAgenda(Agenda *agenda, string nome, string data);
void removeFromAgenda(Agenda *agenda, string nome);

#endif