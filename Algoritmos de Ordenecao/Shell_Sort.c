#include <stdio.h>

void shellSort(int array[], int n){ // n é numero de elementos
    // Começa com um grande intervalo e vai diminuindo
    for(int gap = n/2; gap > 0; gap /= 2){
        // Realiza o Insertion Sort para cada sublista com o intervalo gap
        for(int i = gap; i < n; i++){
            int chave = array[i];
            int j = i;

            while(j >= gap && array[j-gap] > chave){
                array[j+1] = array[j-gap];
                j -= gap;
            }

            array[j] = chave;
        }
    }
}

/*
Análise da complexidade:
- Ω(nlogn)
- Θ(n^(3/2)))
- O(n²)
*/