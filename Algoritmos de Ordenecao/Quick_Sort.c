#include <stdio.h>

// Função de particionamento
void particao(int array[], int start, int end, int *i, int *j){
    int pivo, aux;
    *i = start;
    *j = end;
    pivo = array[(*i + *j) / 2];
    
    do{
        while(array[*i] < pivo)
            (*i)++;
        while(array[*j] > pivo)
            (*j)--;
        if(*i < *j){
            aux = array[*i];
            array[*i] = array[*j];
            array[*j] = aux;
        }
    } while (*i < *j);
}

void quickSort(int array[], int start, int end){
    int i, j;

    particao(array, start, end, &i, &j);

    if(start < j-1)
        quickSort(array, start, j-1);
    if(i+1 < end)
        quickSort(array, i+1, end);
}

/*
Análise da complexidade:
- Ω(nlogn)
- Θ(nlogn)
- O(n²)
*/