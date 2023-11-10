#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int counter = 0;
int tamanho = 1000000000;
int thread_count = 2;
sem_t sem1;

void* Thread_work_1(){
    for(int i=0;i< tamanho;i++){
        sem_wait(&sem1);
        counter++;
        sem_post(&sem1);
    }
}

void* Thread_work_2(){
    for(int i=0;i< tamanho;i++){
        sem_wait(&sem1);
        counter--;
        sem_post(&sem1);
    }
}

int main(){
    pthread_t p1, p2;
    sem_init(&sem1, 0, 1);
    if(pthread_create(&p1,NULL, &Thread_work_1, NULL)!= 0){
        return 1;
    }
    if (pthread_create(&p2, NULL, &Thread_work_2, NULL) !=0){
        return 2;
    }
    if (pthread_join(p1, NULL) != 0){
        return 3;
    }
    if (pthread_join(p2, NULL) !=0){
        return 4;
    }
    sem_destroy(&sem1);
    printf("Resultado, %d: %d\n", tamanho, counter);
    return 0;
}
