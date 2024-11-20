#include <stdio.h>

void bubbleSort (int array[], int n) { // Ordem crescente
    // Loop para percorrer o array
    for(int i = 0; i < n; i++) {
        // Flag para verificar se houve troca em algum elemento
        int swapped = 0;

        // Loop para comparara elementos adjacentes
        for(int j = 0; j < n - 1 - i; j++) {
            if(array[j] > array[j+1]){
                // Troca os elementos se necessário
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }

        // Se não houve troca em nenhum elemento, o array está ordenado
        if (swapped == 0) {
            break;
        }
    }
}

/*
Análise da complexidade:
- Ω(n)
- Θ(n²)
- O(n²)
*/