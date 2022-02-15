#include "Assistente.h++"
#include "Funcionario.h++"
#include "Especialista.h++"
#include <iostream>
#include <string>

Assistente:: Assistente(){}
Assistente:: ~Assistente(){}

void Assistente :: setAssAssistente(Especialista especialista){
    this->especialista = *especialista; 
}

Especialista* Assistente :: getAssAssistente(Assistente assistente){
    return assistente.especialista;
}