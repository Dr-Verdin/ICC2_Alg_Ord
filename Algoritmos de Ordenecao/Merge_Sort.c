#include <stdio.h>

// start seria o primeiro elemento e end o ultimo passados como parametros
// Função para realizar o merge (mesclagem) entre dois sub-arrays ordenados
void mergeSort(int array[], int start, int end){ // Ordem crescente
    // Condição de parada: quando o intervalo for válido (start < end)
    if(start < end){
        // Encontrar o ponto médio
        int medio = (start + end) / 2;

        // Recursivamente divide o array na metade esquerda
        mergeSort(array, start, medio);

        // Recursivamente divide o array na metade direita
        mergeSort(array, medio + 1, end);

        // Tamanho dos dois sub-arrays
        int sizeL = medio - start + 1;
        int sizeR = end - medio;

        // Criar dois sub-arrays temporarios
        int L[sizeL], R[sizeR];

        // Copiar os elementos dos sub-arrays temporarios
        for(int i = 0; i < sizeL; i++)
            L[i] = array[start + i]; // COpia a primeira metade do array para L[]
        for(int j = 0; j < sizeR; j++)
            R[j] = array[medio + 1 + j]; // Copia a segunda netade do array para R[]
    
        // Indices para percorrer os arrays temporários, i -> L e j -> R
        int i = 0, j = 0, k = start; // k é o indice para o array original

        // Mesclar os arrays L[] e R[] de volta para o array original
        while(i < sizeL && j < sizeR){ 
            if(L[i] <= R[j]){ // Se o elemento de L[] for menor ou igual ao de R[]
                array[k] = L[i];
                i++;
            } else { // Caso contrário, coloca o elemento de R[] no array original
                array[k] = R[j];
                j++;
            }
            k++;
        }

        // Se restarem elementos em L[], colocá-los no array original
        while (i < sizeL){
            array[k] = L[i];
            i++;
            k++;
        }

        // Se restarem elementos em R[], colocá-los no array original
        while (j < sizeR){
            array[k] = R[j];
            j++;
            k++;
        }

    }
}

/*
Análise da complexidade:
- Ω(nlogn)
- Θ(nlogn)
- O(nlogn)
*/