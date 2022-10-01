// Gabriel Fernandes Niquini
//19.1.4113

#define EXERC1

#include <cstdlib>
#include <iostream>

using namespace std;
            
#if defined(EXERC1)
// QUESTÃO 1: Critique o código abaixo e aponte seus problemas com relação:
//          a) à flexibilidade da implementação: alterações em pequenos trechos 
//             do código não deveriam exigir recodificação de outras partes
//          b) à legibilidade do código: lendo o código é fácil entrender os 
//             objetos e processos que ele representa. Qual é seu objetivo?

// 1)
// a) Existe apenas um tipo de construtor para a classe Casa o que não deixa o código flexível. Há também um erro de implementação onde não foi definido um destrutor para a classe Casa. Os atributos dessa classe estão privados o que prejudica o reuso dessa clase.
// b) A legibilidade do código não é boa, pois não é possível saber qual a função de cada objeto/processos. Variáveis com nomes incoerentes. Tabulações diferentes. Poluição visual.

class Casa {
      float orc;
      int a;
public:
       Casa( float o ):orc(o){ cout << "Casa criada..." << endl; }
       void setOrc( float o ) { orc = o; }
       float getOrc( void ) { return orc; }
};

#else
// QUESTAO 2: Corrija os problemas identificado na questão 1.

// 2)
// Nessa questão foi supsoto q 'orc' significa orçamento
class Casa {
    protected:
        float orcamento;
    public:
        //construtores
        Casa():orcamento(0){
            cout << "Casa criada..." << endl;
        }
        Casa(float orcamento):orcamento(orcamento){
            cout << "Casa criada..." << endl;
        }
        
        //destrutor
        virtual ~Casa(){};

        //metodos
        void setOrcamento(float orcamento){
            this->orcamento = orcamento;
        }
        float getOrcamento(){
            return orcamento;
        }
};
// ...e aqui se necessário.
#endif

// QUESTAO 3: Explique o código abaixo e cada uma das linhas de texto que 
// formam sua saída.

// O codigo cria um objeto da classe Casa passando como parameto o valor 7.
// A variavel C2 eh um ponteiro para o objeto C1, no codigo o conteudo de C2 recebe o endereco de C1.
// A variavel C3 eh uma referencia constante ao objeto C1
// Na primeira linha de saida eh impresso o conteudo de C1 atraves do metodo getOrc()
// Na segunda e terceira saida eh impresso os valores de orc dos objetos C2 e C3 que refletem a mudanca feita pela chamada do metodo
// setOrc() anteriormente  
// Na ultima linha de saida eh impresso o endereco de memoria para o qual as duas variaveis apontam, ou seja, o endereco de C1
int main(int argc, char *argv[])
{
    Casa c1(7), *c2 = &c1, &c3 = c1;
    
    cout << "C1: " << c1.getOrc() << endl;
    c1.setOrc(3);
    cout << "C2: " << c2->getOrc() << ", ";
    cout << "C3: " << c3.getOrc() << endl;
    cout << "C2: " << c2 << ", C3: " << &c3 << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}

// QUESTAO 4: Quantas vezes o construtor da classe foi invocado? Por que?

// O construtor eh invocado apenas 1 vez durante a criacao de C1 por que as outras variaveis apenas recebem a referencia de C1.