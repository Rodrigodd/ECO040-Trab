#include "dicionario.h"
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

void QuicksortAux(char **palavras, int n, int left, int right) {
    char *pivo;
    pivo = palavras[(left + right) / 2];
    int i = left;
    int j = right;
    char *aux;
    do {
        while ((strcmpi(palavras[i], pivo)) < 0)
            i++;
        while ((strcmpi(palavras[j], pivo)) > 0)
            j--;
        if (i <= j) {
            aux = palavras[i];
            palavras[i] = palavras[j];
            palavras[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j)
        QuicksortAux(palavras, n, left, j);
    if (i < right)
        QuicksortAux(palavras, n, i, right);
}

// funçao que ordena pelo quick
void Quicksort(char **palavras, int n) { QuicksortAux(palavras, n, 0, n - 1); }
