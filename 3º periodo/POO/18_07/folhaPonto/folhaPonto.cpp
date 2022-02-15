#include "folhaPonto.hpp"

using namespace std;

void folhaPonto(Dentista *dent, Funcionario *fun, vector<FolhaPonto> folhaponto){
    int funcionario, edit;
    string observacao, data, salvar;

    do{
        limpaTela();

        cout << endl << "Selecione o funcionario" << endl;
        cout << endl << "1 - " << dent[0].getNome() << endl;
        cout << endl << "2 - " << dent[1].getNome() << endl;
        cout << endl << "3 - " << dent[2].getNome() << endl;
        cout << endl << "4 - " << fun[0].getNome()  << endl;
        cout << endl << "5 - " << fun[1].getNome()  << endl;
        cout << endl << "6 - " << fun[2].getNome()  << endl;
        cout << endl << "7 - " << fun[3].getNome()  << endl;
        cout << endl << "8 - Sair" << endl;
        cin >> funcionario;

        funcionario = funcionario - 1;
        limpaTela();

        if (funcionario >=0 && funcionario <=6){

            printFolhaPonto(&folhaponto[funcionario]);

            cout << "Qual data?" << endl;
            cin >> data;
            cout << "Qual observacao a ser adicionada?" << endl;
            cin >> observacao;

            cout << "Salvar? (y/n)" << endl;
            cin >> salvar;

            getc(stdin);

            if(salvar == "y") {
                adicionarFolhaPonto(&folhaponto[funcionario], observacao, data);
            }
        }
    } while (funcionario != 7);
}

void printFolhaPonto(FolhaPonto *folhaponto) {
    FolhaPonto::iterator it;
    if(!(*folhaponto).empty()) {
        cout << "Folha de Ponto " << endl << "Data - Observacao" << endl << endl;
    }
    for (it = (*folhaponto).begin(); it != (*folhaponto).end(); it++) {
        cout << it->second << " - " << it->first << endl;
    }
    cout << endl;
}

void adicionarFolhaPonto(FolhaPonto *folhaponto, string observacao, string data){
    (*folhaponto).insert(pair<string, string>(observacao, data));
}