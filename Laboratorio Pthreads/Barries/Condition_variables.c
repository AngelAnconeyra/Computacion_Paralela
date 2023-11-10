#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<errno.h>

int counter = 0;
pthread_mutex_t mutex;
pthread_cond_t cond_var;

void* fuel_filling(void* arg){
    for(int i = 0; i< 5;i++){
        pthread_mutex_lock(&mutex);
        counter += 20;
        printf("Number: %d\n", counter);
        pthread_mutex_unlock(&mutex);
        //pthread_cond_signal(&cond_var);
        sleep(1);
    }
}

void* car(void* arg){
    pthread_mutex_lock(&mutex);
    while (counter < 40)
    {
        printf("No fuel. Waiting...\n");
        //pthread_cond_wait(&cond_var,&mutex);
    }
    counter -= 40;
    printf("Got fuel. Now number is: %d\n", counter);
    pthread_mutex_unlock(&mutex);
    
}

int main(){
    pthread_t p[2];
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond_var, NULL);
    for(int i= 0;i<2;i++){
        if(i == 1){
            if(pthread_create(&p[i],NULL,&fuel_filling,NULL)!=0){
                perror("Failed to create thread");
            }
        }else{
            if(pthread_create(&p[i],NULL,&car,NULL)!=0){
                perror("Failed to create thread");
            }
        }
    }
    for (int i=0;i<2;i++){
        if(pthread_join(p[i],NULL)!= 0){
            perror("Failed to join thread");
        }
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_var);
    return 0;
}
