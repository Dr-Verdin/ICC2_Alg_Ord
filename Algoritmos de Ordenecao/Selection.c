#include <stdio.h>

void selectionShort(int array[], int n){
    int i, j, minIdx, temp;

    // Loop para percorrer a lista
    for(i = 0; i < n; i++){
        // Encontra o menor elemento na lista não ordenada
        minIdx = i;

        for(j = i+1; j < n; j++){
            if(array[j] < array[minIdx])
                minIdx = j;
        }

        // Troca o menor elemento encontrado com o elemento na posição inicial
        temp = array[i];
        array[i] = array[minIdx];
        array[minIdx] = temp;
    }
}

/*
Análise da complexidade:
- Ω(n²)
- Θ(n²)
- O(n²)
*/