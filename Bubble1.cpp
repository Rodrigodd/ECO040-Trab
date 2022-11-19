#include "dicionario.h"
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

// funçao que ordena pelo bubble 1
void Bubble1(char **palavras, int n) {
    char *aux;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (strcmpi(palavras[j], palavras[j + 1]) > 0) {
                aux = palavras[j + 1];
                palavras[j + 1] = palavras[j];
                palavras[j] = aux;
            }
        }
    }
}
