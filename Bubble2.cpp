#include "dicionario.h"
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

// funçao que ordena pelo bubble 2
void Bubble2(char **palavras, int n) {
    int troca = 1;
    char *aux;
    for (int i = 1; i < n && troca; i++) {
        troca = 0;
        for (int j = 0; j < n - i; j++) {
            if (strcmpi(palavras[j], palavras[j + 1]) > 0) {
                troca = 1;
                aux = palavras[j + 1];
                palavras[j + 1] = palavras[j];
                palavras[j] = aux;
            }
        }
    }
}
