// Gabriel Fernandes Niquini
//19.1.4113

#include <cstdlib>
#include <iostream>

using namespace std;
            
// QUESTÃO 1: O código desse exercício é idêntico ao do exercício anterior. 
//          Porém o operador "<<" foi sobrecarregado para permitir que 
//          programador implemente de maneira mais fácil a saída do programa.
//          Desta maneira, o codigo a seguir pode ser utilizado para imprimir
//          na tela um objeto "Casa": Casa c1; cout << c1; 
//
//          a) Explique porque o método que sobrecarrega o operador "<<" precisou
//          ser declarado como amigo ("friend") da classe Casa? 
//          b) Explique o funcionamento do novo operador "<<".

// 1)
// a) O metodo deve ser declarado como amigo da classe Casa para que ele possa acessar os dados privados de um objeto Casa
// b) Quando eh passado um objeto Casa como parametro, o operador << ira imprimir o campo orc desse objeto

class Casa {
      float orc;
public:
		// Casa( float o ):orc(o){ printf("Casa criada..."); }
       Casa( float o ):orc(o){ cout << "Casa criada..." << endl; }
       void setOrc( float o ) { orc = o; }
       float getOrc( void ) { return orc; }
       friend ostream& operator<<( ostream& s, Casa& c) {  s << c.orc; return s; }
};

// QUESTÃO 2: Explique o código abaixo e cada uma das linhas de texto que 
// formam sua saída.

// 2)
// A variavel C1 eh criada como um objeto de Casa e C2 recebe a referencia de C1.
// Na primeira linha de saida eh impresso os valores de orc dos objetos atraves do metodo getOrc().
// Na segunda linha de saida eh impresso os valores de orc dos objetos atraves da sobrecarga do operador <<.

int main(int argc, char *argv[])
{
    Casa c1(7), &c2 = c1;
    
    cout << "C1: " << c1.getOrc() << ", C2: " << c2.getOrc() << endl;
    c2.setOrc(3);
    cout << "C1: " << c1 << ", C2: " << c2 << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}

