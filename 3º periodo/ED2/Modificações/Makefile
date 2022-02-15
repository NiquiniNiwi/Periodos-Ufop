all: 
	gcc Gerador.c -Wall -o gerador
	gcc -c Registro.c
	gcc -c Area.c
	gcc -c Fita.c
	gcc -c Quicksort.c
	gcc -c Analise.c
	gcc -c Main.c
	gcc Registro.o Area.o Fita.o Quicksort.o Analise.o Main.o -o tp
clean:
	rm -f *.o 
	rm gerador
	rm tp

run:
	./gerador
	./tp

