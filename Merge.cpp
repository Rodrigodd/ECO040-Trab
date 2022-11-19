#include "dicionario.h"
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

// funçao que intercala as palavras,trocando-as entre si
void intercala(char **palavras, int n, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    char **L, **R;
    L = new (nothrow) char *[n1 + 1];
    R = new (nothrow) char *[n2 + 1];
    for (int i = 0; i < n1; i++)
        L[i] = palavras[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = palavras[q + j + 1];
    char v[] = "úúúú";
    L[n1] = R[n2] = v;
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (strcmpi(L[i], R[j]) <= 0) {
            palavras[k] = L[i];
            i++;
        } else {
            palavras[k] = R[j];
            j++;
        }
    }
    delete[] L;
    delete[] R;
}

// funçao que ordena pelo merge
void MergesortAux(char **palavras, int n, int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        MergesortAux(palavras, n, p, q);
        MergesortAux(palavras, n, q + 1, r);
        intercala(palavras, n, p, q, r);
    }
}

void Mergesort(char **palavras, int n) { MergesortAux(palavras, n, 0, n - 1); }
