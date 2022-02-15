#include "agenda.hpp"

void menuAgenda(vector<Agenda> agenda, Dentista *dent) {
    int dentista;
    int edit;
    string nome;
    string data;
    do{
        getc(stdin);
        limpaTela();
        cout << endl << "Selecione o dentisa" << endl;
        cout << endl << "1 - " << dent[0].getNome() << endl;
        cout << endl << "2 - " << dent[1].getNome()<< endl;
        cout << endl << "3 - " << dent[2].getNome()<< endl;
        cout << endl << "4 - Sair" << endl;
        cin >> dentista;
        dentista = dentista - 1;
        getc(stdin);
        limpaTela();
        if (dentista >=0 && dentista <=2){
            printAgenda(&agenda[dentista]);
            cout << endl << "Gostaria de editar algo ?" << endl;
            cout << endl << "1 - Sim" << endl;
            cout << endl << "2 - Nao" << endl;
            cin >> edit;
            getc(stdin);
            if(edit == 1){
                cout << endl << "Selecione o que mudar" << endl;
                cout << endl << "1 - Alterar data de consulta" << endl;
                cout << endl << "2 - Deletar Consulta" << endl;
                cout << endl << "3 - Adicionar consulta" << endl;
                cout << endl << "4 - Sair" << endl;
                cin >> edit;
                if(edit == 1){
                    cout << endl << "Qual consultante deseja modificar ?" << endl;
                    getc(stdin);
                    getline(cin, nome);
                    editAgenda(&agenda[dentista], nome);
                }
                else if(edit == 2){
                    cout << endl << "Qual consultante deseja deletar ?" << endl;
                    getc(stdin);
                    getline(cin, nome);
                    removeFromAgenda(&agenda[dentista], nome);
                }
                else if(edit == 3){
                    cout << endl << "Qual nome do paciente?" << endl;
                    getc(stdin);
                    getline(cin, nome);
                    cout << "Qual data da consulta?" << endl;
                    getline(cin, data);
                    addToAgenda(&agenda[dentista], nome, data);
                }
            }
        }    
    } while (dentista != 3);
}

void editAgenda(Agenda *agenda, string nome){
    string newDate;
    cout << "Digite a nova data: " << endl;
    getline(cin, newDate);

    Agenda::iterator it;
    it = (*agenda).find(nome);
    if(it == (*agenda).end())
        (*agenda).erase (it);
    (*agenda).insert(pair<string, string>(nome, newDate));
}

void printAgenda(Agenda *agenda){
    Agenda::iterator it;
    if(!(*agenda).empty()) {
        cout << "Agenda " << endl << "Data - Nome do paciente" << endl;
    }
    for (it = (*agenda).begin(); it != (*agenda).end(); it++) {
        cout << it->second << " - " << it->first << endl;
    }
}

void addToAgenda(Agenda *agenda, string nome, string data){
    (*agenda).insert(pair<string, string>(nome, data));
}

void removeFromAgenda(Agenda *agenda, string nome){
    (*agenda).erase(nome);
}