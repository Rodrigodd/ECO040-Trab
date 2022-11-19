#include "dicionario.h"
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

void constroiHeap(char **palavras, int n, int tamanho, int indice_raiz) {
    int ramificacao;
    char *valor;
    valor = palavras[indice_raiz];

    while (indice_raiz <= tamanho / 2) {
        ramificacao = 2 * indice_raiz;

        if (ramificacao < tamanho &&
            strcmpi(palavras[ramificacao], palavras[ramificacao + 1]) <= 0)
            ramificacao++;

        if (strcmpi(valor, palavras[ramificacao]) >= 0) // Identifica o max-heap
            break;

        palavras[indice_raiz] = palavras[ramificacao];
        indice_raiz = ramificacao;
    }
    palavras[indice_raiz] = valor;
}

void HeapSort(char **palavras, int n) {
    int tamanho = n - 1;
    for (int indice = tamanho / 2; indice >= 0; indice--)
        constroiHeap(palavras, n, tamanho, indice);

    while (tamanho > 0) {
        char *troca = palavras[0];
        palavras[0] = palavras[tamanho];
        palavras[tamanho] = troca;
        constroiHeap(palavras, n, --tamanho, 0);
    }
}
