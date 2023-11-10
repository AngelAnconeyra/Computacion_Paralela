#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

int counter = 0;
int number = 1000000;
pthread_mutex_t barrier_mutex;

void* Thread_work(){
    for(int i = 0;i< number; i++){
        counter++;
    }
}

int main(){
    pthread_t p1, p2;
    if(pthread_create(&p1,NULL, &Thread_work, NULL)!= 0){
        return 1;
    }
    if (pthread_create(&p2, NULL, &Thread_work, NULL) !=0){
        return 2;
    }
    if (pthread_join(p1, NULL) != 0){
        return 3;
    }
    if (pthread_join(p2, NULL) !=0){
        return 4;
    }

    printf("Number of mail, %d: %d\n", number,counter);
    return 0;
}
