#include <stdio.h>

// Função recursiva de busca binária
int buscaBinaria(int array[], int alvo, int inicio, int fim) {
    // Caso base: se o intervalo for inválido (início > fim), o alvo não está no vetor
    if (inicio > fim) {
        return -1;  // Valor não encontrado
    }

    // Calcula o índice do meio
    int meio = (inicio + fim) / 2;

    // Caso base: o meio é o valor procurado
    if (array[meio] == alvo) {
        return meio;  // Retorna o índice do elemento encontrado
    }
    // Se o valor procurado for menor que o valor no meio, a busca continua na metade esquerda
    else if (array[meio] > alvo) {
        return buscaBinaria(array, alvo, inicio, meio - 1);
    }
    // Caso contrário, a busca continua na metade direita
    else {
        return buscaBinaria(array, alvo, meio + 1, fim);
    }
}

// Função auxiliar para iniciar a busca binária
int buscar(int array[], int alvo, int tamanho) {
    return buscaBinaria(array, alvo, 0, tamanho - 1);
}

int main() {
    int vetorOrd[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int tamanho = sizeof(vetorOrd) / sizeof(vetorOrd[0]);
    int alvo = 7;

    int resultado = buscar(vetorOrd, alvo, tamanho);

    if (resultado != -1) {
        printf("Elemento encontrado no índice %d\n", resultado);
    } else {
        printf("Elemento não encontrado\n");
    }

    return 0;
}
