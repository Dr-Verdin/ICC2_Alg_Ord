#include <stdio.h>

void insertionSort(int array[], int n){ // n tamanho é o do array 
    for(int i = 1; i < n; i++){ // A função percorre o array começando pelo segundo elemento
        int chave = array[i];
        int j = i - 1; // Para comparar com o da esquerda

        // Move os elementos maiores que a chave para a direita 1 posição a frente do j
        while(j >= 0 && array[j] > chave){
            array[j+1] = array[j];
            j = j - 1;
        }

        array[j+1] = chave;  // Coloca a chave na posição correta
    }
}

/* 
Análise da Complexidade:
- Ω(n)
- Θ(n²)
- O(n²)
*/