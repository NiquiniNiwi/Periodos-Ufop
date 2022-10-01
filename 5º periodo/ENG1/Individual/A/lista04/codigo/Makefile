all:  Estudante.o Disciplina.o main.cpp
	g++ -o lista04 main.cpp Estudante.o Disciplina.o 

Estudante.o: Estudante.cpp
	g++ -o Estudante.o -c Estudante.cpp

Disciplina.o: Disciplina.cpp
	g++ -o Disciplina.o -c Disciplina.cpp

clean:
	rm -f *.o

run:
	./lista04

# Criar o make com para fazer o DLL
# Criar o make com DLL