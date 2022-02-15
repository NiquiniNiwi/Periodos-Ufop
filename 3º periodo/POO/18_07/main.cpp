//Libs
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "tool.hpp"
#include "tool.cpp"

#include "grandezas/funcionario.hpp"
#include "grandezas/dentista.hpp"
#include "grandezas/pessoa.hpp"
#include "grandezas/paciente.hpp"

#include "grandezas/funcionario.cpp"
#include "grandezas/dentista.cpp"
#include "grandezas/pessoa.cpp"
#include "grandezas/paciente.cpp"

#include "folhaPonto/folhaPonto.hpp"
#include "contas/conta.hpp"
#include "usuarios/users.hpp"
#include "agenda/agenda.hpp"
#include "consulta/consulta.hpp"

#include "folhaPonto/folhaPonto.cpp"
#include "contas/conta.cpp"
#include "usuarios/users.cpp"
#include "agenda/agenda.cpp"
#include "consulta/consulta.cpp"

using namespace std;

void menu(int *logado, Auth* auth, int permissao);

int main() {
    // Vector com nomes de usuário e senha de todos os usuários do sistema
    Auth auth;
    // Inicializo o vector com o login e senha do administrador, "admin" e "admin"
    inicializaAuth(&auth);

    // Variaveis que irao controlar acesso ao sistema
    int logado = 1; int permissao;

    // Quando minha variavel logado tiver valor -1, saio do programa
    while(logado != -1) {
        logado = login(&auth, &permissao);
        if(!(logado)) {
            cout << "Nao foi possivel entrar no sistema. Tente novamente." << endl << endl;
            continue;
        }
        menu(&logado, &auth, permissao);
    }
    return 0;
}

// Método MENU
void menu(int *logado, Auth* auth, int permissao){
    Funcionario recepcionista("Thiago Silva");
    Dentista dent[] = {
        Dentista("Ana"),
        Dentista("Maria Clara"),
        Dentista("Luis")
    };
    Funcionario fun[] = {
        Funcionario("Carlos"),
        Funcionario("Fabricio"),
        Funcionario("Joaquim"),
        Funcionario("Fernanda")
    };
    vector<Agenda> agenda(3);
    Consulta consultas;

    vector<Conta> contas;
    vector<Conta>::iterator it;

    vector<Paciente> pacientes;
    vector<Paciente>::iterator pit;

    vector<FolhaPonto> folhaponto(7);
    Administrador adm;

    it = contas.begin();
    int value;
    do {   
        limpaTela();
        if(permissao == 1) {
            cout << endl << "Administrador" << endl;
            cout << endl << "1 - Agenda" << endl;
            cout << endl << "2 - Receber Consulta" << endl;
            cout << endl << "3 - Pagamento de contas" << endl;
            cout << endl << "4 - Folha de ponto" << endl;
            cout << endl << "5 - Criar Usuario" << endl;
            cout << endl << "6 - Fazer logout" << endl;
            cout << endl << "7 - Fechar" << endl;

            cin >> value;

            switch (value)
            {
            case 1:
                menuAgenda(agenda, dent);
                break;

            case 2:
                // receberConsulta(agenda, &consultas);
                break;
            case 3:
                fazerPagamentoContas(&contas, &it);
                break;
            case 4: 
                folhaPonto(dent, fun, folhaponto);
                break;
            case 5:
                criarUser(adm, auth);
                break;
            case 6:
                *logado = 0;
                return;
            case 7:
                *logado = -1;
                return;
            default:
                break;
            }

        } else if (permissao == 2) {
            cout << endl << "Assistente Administrativo" << endl;
            cout << endl << "1 - Agenda" << endl;
            cout << endl << "2 - Receber Consulta" << endl;
            cout << endl << "3 - Pagamento de contas" << endl;
            cout << endl << "4 - Folha de ponto" << endl;
            cout << endl << "5 - Fazer logout" << endl;
            cout << endl << "6 - Fechar" << endl;

            cin >> value;

            switch (value)
            {
            case 1:
                menuAgenda(agenda, dent);
                break;
            case 2:
                // receberConsulta(agenda, &consultas);
                break;
            case 3:
                fazerPagamentoContas(&contas, &it);
                break;
            case 4: 
                folhaPonto(dent, fun, folhaponto);
                break;
            case 5:
                *logado = 0;
                return;
            case 6:
                *logado = -1;
                return;
            default:
                break;
            }
        } else if (permissao == 3) {
            cout << endl << "Usuario Geral" << endl;
            cout << endl << "1 - Agenda" << endl;
            cout << endl << "2 - Fazer logout" << endl;
            cout << endl << "3 - Fechar" << endl;

            cin >> value;

            switch (value)
            {
            case 1:
                menuAgenda(agenda, dent);
                break;
            case 2:
                *logado = 0;
                return;
            case 3:
                *logado = -1;
                return;
            default:
                break;
            }
        }
    
    } while (*logado != -1);
}