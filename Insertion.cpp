#include "dicionario.h"
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

// funçao que ordena pelo insertion
void Insertion(char **palavras, int n) {
    char *aux;
    int j;
    for (int i = 1; i < n; i++) {
        aux = palavras[i];
        j = i;
        while (j > 0 && (strcmpi(palavras[j - 1], aux) > 0)) {
            palavras[j] = palavras[j - 1];
            j--;
        }
        palavras[j] = aux;
    }
}
