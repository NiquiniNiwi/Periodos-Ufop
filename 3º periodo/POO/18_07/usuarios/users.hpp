#ifndef USERS_HPP
#define USERS_HPP

#include <string>
#include <vector>
#include <map>

#include "../tool.hpp"

using namespace std;

class User {
    string login;
    string senha;

    public:
    User(string="", string="");
    ~User();

    void setLogin(string);
    string getLogin() const;

    void setSenha(string);
    string getSenha() const;
};

class UserGeral : public User {

    public:
    UserGeral(string="", string="");
    ~UserGeral();
};

class AssistenteAdm : public User {

    public:
    AssistenteAdm(string="=", string="");
    ~AssistenteAdm();
};

class Administrador : public User {

    public:
    Administrador(string="admin", string="admin");
    ~Administrador();

    AssistenteAdm criarAssistenteAdm();
    UserGeral criarUserGeral();
};

class Login {
    public:
    string login;
    string senha;
    int user;
};

typedef std::vector<Login> Auth;

void inicializaAuth(Auth* auth);
int login(Auth *auth, int *permissao);
void criarUser(Administrador adm, Auth *auth);

#endif