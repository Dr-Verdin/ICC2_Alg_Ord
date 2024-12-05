#include <stdio.h>

// Função para fazer o heapify (ajustar a arvore)
void heapify(int array[], int tam, int i) {
    int maior = i;  // Inicializa o maior como raiz
    int esq = 2 * i + 1;  // ��ndice do filho esquerdo
    int dir = 2 * i + 2;  // ��ndice do filho direito

    // Verifica se o filho esquerdo é maior que o raiz
    if (esq < tam && array[esq] > array[maior]) {
        maior = esq;
    }

    // Verifica se o filho direito é maior que o maior
    if (dir < tam && array[dir] > array[maior]) {
        maior = dir;
    }

    // Se o maior não é a raiz
    if (maior!= i) {
        // Troca os elementos
        int temp = array[i];
        array[i] = array[maior];
        array[maior] = temp;

        // Chama heapify para a subárvore afetada
        heapify(array, tam, maior);
    }
}

// Função principal do Heap Sort
void heapSort(int array[], int tam) {
    // Construa o heap (max-heap -> tipo arv bin: o valor de cada nó é maior ou igual ao valor de seus filhos) de baixo para cima
    for (int i = tam / 2 - 1; i >= 0; i--) {
        heapify(array, tam, i);
    }

    // Extraí os elementos um por um do heap
    for (int i = tam - 1; i >= 1; i--) {
        // Mova a raiz (o maior elemento) para o final
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // Chama heapify para a subárvore afetada
        heapify(array, i, 0);
    }
}