#ifndef FOLHAPONTO_HPP
#define FOLHAPONTO_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef std::multimap<string, string, std::less<string > > FolhaPonto;

#include "../tool.hpp"

#include "../grandezas/funcionario.hpp"
#include "../grandezas/dentista.hpp"

void folhaPonto(Dentista *dent, Funcionario *fun, vector<FolhaPonto> folhaponto);
void printFolhaPonto(FolhaPonto *folhaponto);
void adicionarFolhaPonto(FolhaPonto *folhaponto, string observacao, string data);

#endif