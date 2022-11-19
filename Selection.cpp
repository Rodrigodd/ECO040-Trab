#include "dicionario.h"
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

// funçao que ordena pelo selection
void Selection(char **palavras, int n) {
    int i_menor;
    char *aux;
    for (int i = 0; i < n - 1; i++) {
        i_menor = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmpi(palavras[j], palavras[i_menor]) < 0)
                i_menor = j;
        }
        aux = palavras[i];
        palavras[i] = palavras[i_menor];
        palavras[i_menor] = aux;
    }
}
