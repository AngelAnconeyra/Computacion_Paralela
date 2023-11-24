#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include <time.h>

void oddEvenSort(int a[],int n, int thread_count);
void llenarArray(int a[], int n);

int main(){
    int n = 20000; // tamaño del array
    int thread_count = 3; //numero de hilos
    int arr[n];

    llenarArray(arr,n);

    clock_t inicio = clock();
    oddEvenSort(arr,n,thread_count);
    clock_t fin = clock();
    double tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Lista de %d elementos ordenada con %d hilos en %.6f", n,thread_count, tiempo_total);
    return 0;
}

void oddEvenSort(int a[],int n, int thread_count){
    int phase, i, tmp;

    for(phase = 0; phase < n; phase++){
        if(phase % 2 == 0){
            #pragma omp parallel for num_threads(thread_count)\
            default(none) shared(a,n) private(i,tmp)
            for (i =1; i<n; i+=2){
                if(a[i-1]>a[i]){
                    tmp = a[i-1];
                    a[i-1] = a[i];
                    a[i] = tmp;
                }
            }
        } else{
            #pragma omp parallel for num_threads(thread_count) \
            default(none) shared(a, n) private(i, tmp)
            for (i = 1; i < n-1; i += 2) {
                if (a[i] > a[i+1]) {
                    tmp = a[i+1];
                    a[i+1] = a[i];
                    a[i] = tmp;
                }
            }
        }
    }
}

void llenarArray(int a[], int n){
    //srand(time(NULL));
    int cont = 0;
    for (int i = n; i > 0; i--) {
        // Generar un número aleatorio en el rango [1, rango]
        //a[i] = rand() % n + 1;
        a[cont] = i;
        cont++;
    }
}
