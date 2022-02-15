#include <pthread.h>
#include <semaphore.h> //Versão mais atualizada da biblioteca dada como exemplo de semaforo
#include <stdio.h>

//Defs e variaveis universais
#define N 5
#define LEFT (i+N-1)%N
#define RIGHT (i+1)%N
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[N];
int philosofers[N] = {0, 1, 2, 3, 4};
sem_t mutex;
sem_t s[N];
//----------------------------------------------------------

//Declaração das funções
void* philosopher(void* i);
void take_forks(int i);
void put_forks(int i);
void test(int i);
//----------------------------------------------------------

int main(){
    pthread_t thread_id[N];//Criação da thread, honestamente, preguiça de ficar verificando se cricou com sucesso

    sem_init(&mutex, 0, 1);//Criação do semaforo, honestamente, preguiça de ficar verificando se criou com sucesso

    for(int i = 0; i < N; i++){
        sem_init(&s[i], 0 ,0);//Inicialização da semaforo, honestamente, preguiça de ficar verificando se preencheu com sucesso
    }
    for(int i = 0; i < N; i++){
        pthread_create(&thread_id[i], NULL, philosopher, &philosofers[i]);//Inicialização da thread, honestamente, preguiça de ficar verificando se preencheu com sucesso

        printf("Philosopher %d is thinking\n", i+1);
    }

    for(int i = 0; i < N; i++){
        pthread_join(thread_id[i], NULL);//começa a rodar a thread
    }
}

void* philosopher(void* i){
    while (1){
        int* num = i;

        sleep(1);//faz com que a thread em questão entre em "pause"

        take_forks(*num);

        sleep(0);//Dar uma chance de outras threads rodadrem

        put_forks(*num);
    }
}

void take_forks(int i){
    sem_wait(&mutex);//espera pela resposta de outras trheads "travando o semaforo"

    state[i] = HUNGRY;
    printf("Philosopher %d is Hungry\n", i+1);

    test(i);

    sem_post(&mutex);//faz o destravamento do semaforo
    sem_wait(&s[i]);
}

void put_forks(int i){
    sem_wait(&mutex);
    state[i] = THINKING;

    test(LEFT);
    test(RIGHT);

    sem_post(&mutex);
}

void test(int i){
    if(state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING){//Condição pro filosofo comer
        state[i] = EATING;
        sleep(2);
        printf("Philosopher %d takes fork %d and %d\n", i+1, LEFT+1, i+1);

        printf("Philosopher %d is Eating\n", i+1);

        sem_post(&s[i]);
    }
}
