#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int tamanho = 400;

void llenarMatriz(vector<vector<int>> &matriz){
    for(int i=0;i<tamanho;++i){
        for(int j=0;j<tamanho;++j){
            matriz[i][j] = j+1;
        }
    }
}

vector<vector<int>> multiplicarMatrices(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> resultado(tamanho, vector<int>(tamanho, 0));

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            for (int k = 0; k < tamanho; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return resultado;
}

int main() {
    vector<vector<int>> matrizA (tamanho,vector<int>(tamanho));
    vector<vector<int>> matrizB (tamanho,vector<int>(tamanho));
    llenarMatriz(matrizA);
    llenarMatriz(matrizB);
    auto inicio = chrono::high_resolution_clock::now();
    vector<vector<int>> resultado = multiplicarMatrices(matrizA, matrizB);
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    cout<<"Tamanho "<<tamanho<<": "<<duracion.count()<<endl;

    return 0;
}
