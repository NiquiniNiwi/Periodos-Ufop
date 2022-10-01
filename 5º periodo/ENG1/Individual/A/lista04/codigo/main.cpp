#include "Estudante.h"
#include "Disciplina.h"
#include "Desordenada.h"
#include "Ordenada.h"
#include "Funcoes.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define TEST

#ifdef TEST

int main(){

    //Criando instancias da classe Estudante
    Estudante e("19.1.0001","Joao",8.5);
    Estudante e2("19.1.0002","Maria",6.5);
    Estudante e3("19.1.0003","Pedro",7.5);
    
    assert(e.getMatricula() != "");
    assert(e.getNome() != "");
    assert(e.getNota() == 8.5);
    cout << "Classe Estudante funcionando corretamente\n";

    //Criando instancias da classe Disciplina
    Disciplina d("Programacao I","BCC001",40);
    Disciplina d2("Algoritmos","BCC002",60);
    Disciplina d3("Banco de Dados","BCC003",30);
    
    assert(d.getNome() != "");
    assert(d.getCodigo() != "");
    assert(d.getCargaHoraria() == 40);
    cout << "Classe Disciplina funcionando corretamente\n";

    //Testando template Desordenada com classe Estudante
    Desordenada<Estudante> listaEstudantesDesord;
    listaEstudantesDesord.insert(e);
    listaEstudantesDesord.insert(e2);
    listaEstudantesDesord.insert(e3);
    assert(listaEstudantesDesord[0].getNota() == 8.5);
    assert(listaEstudantesDesord[0].getNome() == "Joao");
    assert(listaEstudantesDesord[0].getMatricula() == "19.1.0001");
    cout << "Template Desordenada funcionando corretamente\n";

    //Testando template Desordenada com classe Estudante
    Ordenada<Estudante> listaEstudantesOrd;
    listaEstudantesOrd.insert(2, e);
    listaEstudantesOrd.insert(3, e2);
    listaEstudantesOrd.insert(1, e3);
    assert(listaEstudantesOrd[0].getNota() == 7.5);
    assert(listaEstudantesOrd[0].getNome() == "Pedro");
    assert(listaEstudantesOrd[0].getMatricula() == "19.1.0003");
    cout << "Template Desordenada funcionando corretamente\n";


    //Testando template Ordenada com a classe Disciplina
    Ordenada<Disciplina> listaDisciplinaOrd;
    listaDisciplinaOrd.insert(2, d);
    listaDisciplinaOrd.insert(3, d2);
    listaDisciplinaOrd.insert(1, d3);
    assert(listaDisciplinaOrd[0].getCargaHoraria() == 30);
    assert(listaDisciplinaOrd[0].getNome() == "Banco de Dados");
    assert(listaDisciplinaOrd[0].getCodigo() == "BCC003");
    cout << "Template Ordenada funcionando corretamente\n";

    //Testando template Desordenada com a classe Disciplina
    Desordenada<Disciplina> listaDisciplinaDesord;
    listaDisciplinaDesord.insert(d);
    listaDisciplinaDesord.insert(d2);
    listaDisciplinaDesord.insert(d3);
    assert(listaDisciplinaDesord[0].getCargaHoraria() == 40);
    assert(listaDisciplinaDesord[0].getNome() == "Programacao I");
    assert(listaDisciplinaDesord[0].getCodigo() == "BCC001");
    cout << "Template Ordenada funcionando corretamente\n\n";

    //Testando count para um conjunto desordenado de Estudantes
    double num = 6.5;
    int conta1 = count<Desordenada<Estudante>,double>(listaEstudantesDesord, num);
    cout << "contador desordenado = " << conta1 << "\n";

    //Testando count para um conjunto ordenado de Disciplinas
    int num2 = 400;
    int conta2 = count<Ordenada<Disciplina>,int>(listaDisciplinaOrd, num2);
    cout << "contador ordenado    = " << conta2 << "\n\n";
    
    //Testando sum para um conjunto desordenado de Estudantes
    double soma1 = sum<Desordenada<Estudante>,double>(listaEstudantesDesord);
    cout << "soma desordenada     = " << soma1 << "\n";

    //Testando sum para um conjunto ordenado de Disciplinas
    int soma2 = sum<Ordenada<Disciplina>,int>(listaDisciplinaOrd);
    cout << "soma ordenada        = " << soma2 << "\n\n";

    //Testando average
    double media1 = average<Desordenada<Estudante>>(listaEstudantesDesord);
    cout << "media desordenada    = " << media1 << "\n";
    
    double media2 = average<Ordenada<Disciplina>>(listaDisciplinaOrd);
    cout << "media ordenada       = " << media2 << "\n\n";


    // Testando funções count, sum e average
    assert(conta1 == 1);
    assert(conta2 == 0);
    assert(abs(soma1 - 22.5) <= 0.0001);
    assert(soma2  == 130);
    assert(media1 == 7.5);
    assert(abs(media2 - 43.3333) <= 0.0001);

    return 0;
}

#else
int main(){

    //Criando instancias da classe Estudante
    Estudante e("19.1.0001","Joao",8.5);
    Estudante e2("19.1.0002","Maria",6.5);
    Estudante e3("19.1.0003","Pedro",7.5);

    //Criando instancias da classe Disciplina
    Disciplina d("Programacao I","BCC001",40);
    Disciplina d2("Algoritmos","BCC002",60);
    Disciplina d3("Banco de Dados","BCC003",30);

    //Testando template Desordenada com classe Estudante
    Desordenada<Estudante> listaEstudantesDesord;
    listaEstudantesDesord.insert(e);
    listaEstudantesDesord.insert(e2);
    listaEstudantesDesord.insert(e3);

    //Testando template Desordenada com classe Estudante
    Ordenada<Estudante> listaEstudantesOrd;
    listaEstudantesOrd.insert(2, e);
    listaEstudantesOrd.insert(3, e2);
    listaEstudantesOrd.insert(1, e3);


    //Testando template Ordenada com a classe Disciplina
    Ordenada<Disciplina> listaDisciplinaOrd;
    listaDisciplinaOrd.insert(2, d);
    listaDisciplinaOrd.insert(3, d2);
    listaDisciplinaOrd.insert(1, d3);

    //Testando template Desordenada com a classe Disciplina
    Desordenada<Disciplina> listaDisciplinaDesord;
    listaDisciplinaDesord.insert(d);
    listaDisciplinaDesord.insert(d2);
    listaDisciplinaDesord.insert(d3);

    //Testando count para um conjunto desordenado de Estudantes
    double num = 6.5;
    int conta1 = count<Desordenada<Estudante>,double>(listaEstudantesDesord, num);
    cout << "contador desordenado = " << conta1 << "\n";

    //Testando count para um conjunto ordenado de Disciplinas
    int num2 = 400;
    int conta2 = count<Ordenada<Disciplina>,int>(listaDisciplinaOrd, num2);
    cout << "contador ordenado    = " << conta2 << "\n\n";
    
    //Testando sum para um conjunto desordenado de Estudantes
    double soma1 = sum<Desordenada<Estudante>,double>(listaEstudantesDesord);
    cout << "soma desordenada     = " << soma1 << "\n";

    //Testando sum para um conjunto ordenado de Disciplinas
    int soma2 = sum<Ordenada<Disciplina>,int>(listaDisciplinaOrd);
    cout << "soma ordenada        = " << soma2 << "\n\n";

    //Testando average
    double media1 = average<Desordenada<Estudante>>(listaEstudantesDesord);
    cout << "media desordenada    = " << media1 << "\n";
    
    double media2 = average<Ordenada<Disciplina>>(listaDisciplinaOrd);
    cout << "media ordenada       = " << media2 << "\n\n";

    return 0;
}

#endif