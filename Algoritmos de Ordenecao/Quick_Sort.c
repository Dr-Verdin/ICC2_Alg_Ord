#include <stdio.h>

// Função de particionamento
int particao(int array[], int start, int end){
    int pivo = array[end]; // Escolhemos o ultimo elemento como pivo
    int i = (start - 1); // Indice do menor elemento

    // Reorganiza a lista com base no pivo
    for(int j = start; j <= end - 1; j++){
        // Se o elemento atual é menor ou igual ao pivo, troca com o elemento na posição i + 1 e incrementa i + 1
        if(array[j] <= pivo){
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    // Coloca o pivo no lugar correto onde ele já deveria estar
    int temp = array[i + 1];
    array[i + 1] = array[end];
    array[end] = temp;

    return (i + 1); // Retorna o indice do pivo
}

void quickSort(int array[], int start, int end){
    if(start < end){
        // Particiona a lista e obtém o índice do pivô
        int pivo = particao(array, start, end);

        // Ordena recursivamente as sublistas à esquerda e à direita do pivô
        quickSort(array, start, pivo - 1); // Sublista à esquerda
        quickSort(array, pivo + 1, end); // Sublista à direita
    }
}

/*
Análise da complexidade:
- Ω(nlogn)
- Θ(nlogn)
- O(n²)
*/