#include <iostream>
#include <string>

#include "users.hpp"

using namespace std;

User::User(string login, string senha) : login(login), senha(senha) {};
User::~User() {};

void User::setLogin(string login) {
    this->login = login;
}

string User::getLogin() const {
    return login;
}

void User::setSenha(string senha) {
    this->senha = senha;
}

string User::getSenha() const {
    return senha;
}

Administrador::Administrador(string login, string senha) : User(login,senha) {};

Administrador::~Administrador() {};

AssistenteAdm Administrador::criarAssistenteAdm() {
    string login, senha;

    cout << "Criando novo assistente administrativo:" << endl;
    cout << "Login: ";
    cin >> login;
    cout << "Senha: ";
    cin >> senha;

    AssistenteAdm novo(login, senha);
    return novo;
}

UserGeral Administrador::criarUserGeral() {
    string login, senha;

    cout << "Criando novo usuario geral:" << endl;
    cout << "Login: ";
    cin >> login;
    cout << "Senha: ";
    cin >> senha;

    UserGeral novo(login, senha);
    return novo;
}

AssistenteAdm::AssistenteAdm(string login, string senha) : User(login,senha) {};

AssistenteAdm::~AssistenteAdm() {};

UserGeral::UserGeral(string login, string senha) : User(login,senha) {};

UserGeral::~UserGeral() {};

void inicializaAuth(Auth *auth) {
    Administrador novo = Administrador();
    
    Login aux;
    aux.login = novo.getLogin();
    aux.senha = novo.getSenha();
    aux.user = 1;

    (*auth).push_back(aux);
}

int login(Auth *auth, int *permissao) {
    string login, senha;
    limpaTela();
    cout << "Para entrar no sistema, faca login:" << endl;
    cout << "LOGIN: " << endl;
    cin >> login;
    cout << "SENHA: " << endl;
    cin >> senha;

    for(auto itr = (*auth).begin(); itr != (*auth).end(); ++itr)
        cout << (*itr).login << " - " << (*itr).senha << " - " << (*itr).user << endl;

    for(auto itr = (*auth).begin(); itr != (*auth).end(); ++itr) {
        if((login == (*itr).login) && (senha == (*itr).senha)) {
            cout << "Login encontrado" << endl;
            *permissao = (*itr).user;
            return 1;
        }
    }

    // string bla;
    // cin >> bla;

    return 0;
}

void criarUser(Administrador adm, Auth *auth) {
    int option; Login user;

    cout << endl << "Criando usuario do sistema:" << endl << endl;

    cout << "1 - Assistente Administrativo" << endl;
    cout << endl << "2 - Usuario Geral" << endl;

    cout << endl << "Qual voce deseja criar?" << endl;

    cin >> option;

    std::vector<string> users;

    if(option == 1) {
        AssistenteAdm novo = adm.criarAssistenteAdm();

        user.login = novo.getLogin();
        user.senha = novo.getSenha();
        user.user = 2;

        (*auth).push_back(user);

    } else if (option == 2) {
        UserGeral novo = adm.criarUserGeral();

        user.login = novo.getLogin();
        user.senha = novo.getSenha();
        user.user = 3;

        (*auth).push_back(user);

    } else {
        cout << endl << "Opcao nao disponivel." << endl;
        return;
    }

    for(auto itr = (*auth).begin(); itr != (*auth).end(); ++itr) 
        cout << (*itr).login << " - " << (*itr).senha << " - " << (*itr).user << endl;
    
    string bla;
    cin >> bla;

    return;
}


// void inicializarAuth() {
//     FILE *arq; Auth user;

//     if((arq = fopen("auth.bin", "wb+")) == NULL) {
//         cout << "Erro ao ler arquivo" << endl;
//         return;
//     }

//     Administrador novo = Administrador();

//     user.login = novo.getLogin();
//     user.senha = novo.getSenha();
//     user.user = 1;

//     fwrite(&user, sizeof(Auth), 1, arq);

//     rewind(arq);

//     Auth leitura;
//     fread(&leitura, sizeof(Auth), 1, arq);
//     cout << "User: " << leitura.user << endl;
//     cout << "Login: " << leitura.login << endl;
//     cout << "Senha: " << leitura.senha << endl << endl;

//     fclose(arq);
// }


/*

int login(int *logado) {
    string login, senha;
    cout << "Para entrar no sistema, faca login:" << endl;
    cout << "LOGIN: " << endl;
    cin >> login;
    cout << "SENHA: " << endl;
    cin >> senha;

    FILE *arq; Auth user;

    if((arq = fopen("auth.bin", "rb")) == NULL) {
        cout << "Erro ao ler arquivo" << endl;
        return 0;
    }

    rewind(arq);

    Auth leitura;
    fread(&leitura, sizeof(Auth), 1, arq);

        cout << "User: " << leitura.user << endl;
        cout << "Login: " << leitura.login << endl;
        cout << "Senha: " << leitura.senha << endl << endl;

        if((login == leitura.login) == 0) {
            cout << "Login nao encontrado" << endl;
            *logado = 0;
            return 0;
        } else if ((senha == leitura.senha) == 0) {
            cout << "Senha incorreta" << endl;
            *logado = 0;
            return 0;
        } else {
            cout << "\nBem vindo " << leitura.login << endl << endl;
            *logado = 1;
            return 1;
        }
    

    for(auto itr = (*l).begin(); itr != (*l).end(); ++itr) {
        cout << endl << (*itr).getLogin() << " | " << (*itr).getSenha() << endl;
        if((login == (*itr).getLogin()) == 0) {
            cout << "Login nao encontrado" << endl;
            *logado = 0;
            return 0;
        } else if ((senha == (*itr).getSenha()) == 0) {
            cout << "Senha incorreta" << endl;
            *logado = 0;
            return 0;
        } else {
            cout << "\nBem vindo " << (*itr).getLogin() << endl << endl;
            *logado = 1;
            return 1;
        }
    } 

    if((login == "admin") == 0) {
        cout << "Login nao encontrado" << endl;
        *logado = 0;
        return 0;
    } else if ((senha == "admin") == 0) {
        cout << "Senha incorreta" << endl;
        *logado = 0;
        return 0;
    } else {
        cout << "\nBem vindo Administrador" << endl << endl;
        *logado = 1;
        return 1;
    }

    return 0;
}

void criarUser(Administrador adm) {
    FILE *arq; Auth user;

    if((arq = fopen("auth.bin", "wb+")) == NULL) {
        cout << "Erro ao ler arquivo" << endl;
        return;
    }

    int option;

    cout << endl << "Criando usuario do sistema:" << endl << endl;

    cout << "1 - Assistente Administrativo" << endl;
    cout << endl << "2 - Usuario Geral" << endl;

    cout << endl << "Qual voce deseja criar?" << endl;

    cin >> option;

    std::vector<string> users;

    if(option == 1) {
        AssistenteAdm novo = adm.criarAssistenteAdm();

        user.login = novo.getLogin();
        user.senha = novo.getSenha();
        user.user = 2;

        fwrite(&user, sizeof(Auth), 1, arq);

    } else if (option == 2) {
        UserGeral novo = adm.criarUserGeral();

        user.login = novo.getLogin();
        user.senha = novo.getSenha();
        user.user = 3;

        fwrite(&user, sizeof(Auth), 1, arq);
    } else {
        cout << endl << "Opcao nao disponivel." << endl;
        return;
    }
    
    string bla;
    cin >> bla;

    return;
}

*/