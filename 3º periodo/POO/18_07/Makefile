main: clean main.o pessoas.o funcionarios.o dentistas.o pacientes.o agenda.o folhaPonto.o consulta.o
	g++ main.o -o main

main.o: main.cpp
	g++ -c main.cpp

## GRANDEZAS: FUNCIONARIO, DENTISTA, PACIENTE
grandezas.o: ./grandezas/*.cpp
	g++ -c ./grandezas/*.cpp

pessoas.o: ./grandezas/pessoa.cpp
	g++ -c ./grandezas/pessoa.cpp
	
funcionarios.o: ./grandezas/funcionario.cpp
	g++ -c ./grandezas/funcionario.cpp

dentistas.o: ./grandezas/dentista.cpp
	g++ -c ./grandezas/dentista.cpp

pacientes.o: ./grandezas/paciente.cpp
	g++ -c ./grandezas/paciente.cpp

## FOLHA DE PONTO
folhaPonto.o: ./folhaPonto/folhaPonto.cpp
	g++ -c ./folhaPonto/folhaPonto.cpp

## AGENDA
agenda.o: ./agenda/agenda.cpp
	g++ -c ./agenda/agenda.cpp

## CONSULTA
consulta.o: ./consulta/consulta.cpp
	g++ -c ./consulta/consulta.cpp

# DELETAR/LIMPAR
clean:
	del -f *.o main.exe

remove:
	rm -f *.o main.exe

# Em windows, usar comando make clean
# Em linux, comando make remove

#### EXEMPLO MAKEFILE ####

# output: main.o garage.o
#         g++ -std=c++0x -Wall main.o garage.o -o output

#  main.o: main.cpp
#         g++ -c main.cpp

#  garage.o: garage.cpp garage.hpp
#         g++ -c garage.cpp

#  clean:
#         rm *.o output