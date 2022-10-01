#include "estudantes.hpp"
#include "disciplina.hpp"
#include "templates.hpp"

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <assert.h>

int main (){
	estudantes e;
	disciplina d;

	testeEstudantes(e);
	testeDisciplina(d);
	
    return 0;
}

void testeEstudantes(estudantes e){
	assert(e.getMatricula() > 0);
	assert(e.getCpf().length() > 0);
	assert(e.getNome().length());
}

void testeDisciplina(disciplina d ){
	assert (d.getNome().length() > 0 );
	assert (d.getCodigo().length() == 4 );
	assert (d.getCargaHoraria() >= 0);
}
