#include<iostream>
#include<chrono>

using namespace std;
const int MAX = 600;
int i,j;

int main(){
    double A[MAX][MAX], x[MAX], y[MAX];
    /* Initialize A and x, assign y = 0 */
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            A[i][j] = j+1;
        }
        x[i] = i+1;
        y[i] = 0.0;
    }
    auto inicio = chrono::high_resolution_clock::now();
    /* First pair of loops */
    for (i = 0; i < MAX; i++){
        for (j = 0; j < MAX; j++){
            y[i] += A[i][j]*x[j];
        }
    }
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    cout<<"First pair of loops: "<<duracion.count()<<endl;

    /* Assign y = 0 */
    for(i=0;i<MAX;i++){
        y[i] = 0;
    }

    inicio = chrono::high_resolution_clock::now();
    /* Second pair of loops */
    for (j = 0; j < MAX; j++){
        for (i = 0; i < MAX; i++){
            y[i] += A[i][j]*x[j];
        }
    }
    fin = chrono::high_resolution_clock::now();
    duracion = fin - inicio;
    cout<<"Second pair of loops: "<<duracion.count()<<endl;
    return 0;
}
