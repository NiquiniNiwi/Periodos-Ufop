#include "Especialista.h++"
#include "Assistente.h++"
#include "Agenda.h++"
#include "Funcionario.h++"
#include <iostream>
#include <string>

Especialista :: Especialista(string nome, string cpf, string rg, string endereco, string telefone, string email, string user, string senha, int id){}
Especialista :: ~Especialista(){}

void Especialista :: setAgenda(Agenda agenda){
    this->agenda = agenda;
}

Agenda Especialista :: getAgenda(Especialista especialista){
    return especialista.agenda;
}

void Especialista :: setAssAssistente(Assistente assistente){
    this->assistente = *assistente; 
}

Assistente* Especialista :: getAssAssistente(Especialista especialista){
    return especialista.assistente;
}