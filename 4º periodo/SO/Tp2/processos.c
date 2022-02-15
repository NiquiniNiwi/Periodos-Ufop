#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define READ 0
#define WRITE 1

int main(){

    printf("\n[+] para somar 100 UD;\n");
    printf("[-] para subtrair 50 UD;\n");
    printf("[.] para imprimir o valor do saldo;\n");
    printf("[s] para destuir todos os threads e finalizar a execucao.\n");
    printf("[ENTER] para confirmar as operacoes.\n\n");
    printf("O valor inicial de saldo eh: %d\n\n",saldo);

    int saldo[2];
    int option[2];
    int c = 0;
    int aux = 0;

    if (pipe (saldo) < 0 || pipe (option) < 0){
        printf("Erro na criação do pipe\n");
        exit(1);
    }

    if( write(saldo[WRITE], &aux, sizeof(int)) == -1){
        printf("Erro ao escrever no pipe\n");
        exit(1);        
    }

    pid_t pidPai - getpid();
    pid_t pidFilho1 = fork();
    pid_t pidpidFilho2 = -1;

    if(pidFilho1 < 0){
        printf("Error na criação do fork\n");
        exit(1);
    }
    fflush(stdin);

    if (getpid() == pidPai){
        pidFilho2 = fork();
        if (pidFilho2 < 0){
            exit(1);
        }
        if (pidpidFilho2 == 0){
            pidFilho1 = -1;
        }
    }
    
    if (getpid() == pidPai){
        int x;
        while(c != 107 || c != 75){
            do{
                c = (int)getchar();
            }while((c != 43) && (c != 83) && (c != 115) && (c != 107) 
            && (c != 75) && (c != 45));

            if (c == 83 || c == 115) {
                read(saldo[READ], &x, sizeof(int));
                printf("-----------------------------\n");
                printf("Print em PID : %d\n", getpid());
                printf("Saldo        : %d UD\n", x);
                printf("-----------------------------\n");
                write(saldo[WRITE], &x, sizeof(int));
            }
            else{
                write(option[WRITE], &c, sizeof(int));
            }

            if (c == 107 ||c == 75){
                printf("-----------------------------\n");
                kill(pidFilho1, SIGKILL);
                kill(pidpidFilho2, SIGKILL);
                kill(getpid(), SIGKILL);
                exit(0);
            }
        }
    }
    else if (pidFilho1 == 0){
        int operacao;
        int x;
        do{
            read(option[READ], &operacao, sizeof(int));

            if (operacao == 43){
                printf("-----------------------------\n");
                printf("Soma em PID  : %d\n", getpid());
                printf("-----------------------------\n");
                read(saldo[READ], &x, sizeof(int));
                x += 100;
                write(saldo[WRITE], &x, sizeof(int));
            }
            else{
                write(option[WRITE], &operacao, sizeof(int)); 
            }
        }while(operacao != 107 ||operacao != 75 );
    }
    else if (pidpidFilho2 == 0){
        int operacao;
        int x;
        do{
            read(option[READ], &operacao, sizeof(int));

            if(operacao == 45){
                printf("-----------------------------\n");
                printf("Remove em PID: %d\n", getpid());
                printf("-----------------------------\n");
                read(saldo[READ], &x, sizeof(int));
                x -= 100;
                write(saldo[WRITE], &x, sizeof(int));
            }
            else{
                write(option[WRITE], &operacao, sizeof(int)); 
            }
        }while(operacao != 107 ||operacao != 75);
    }
    
    return 0;
}