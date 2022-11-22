#include "dicionario.h"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

// contrutor com parametro _n, cria e aloca espaço para o arquivo lido
dicionario::dicionario(int _n) {
    n = _n;

    ifstream ifs;
    ifs.open("basePalavras\\aurelio40000.txt");

    if (ifs.is_open()) {
        palavras = new (nothrow) char *[n];
        if (!palavras) {
            cout << "\nNao conseguiu alocar memoria para a palavra \n";
            exit(1);
        }

        for (int j = 0; j < n; j++)
            palavras[j] = 0;
        if (!palavras) {
            cout << "\nNão conseguiu alocar memória para o vetor de ponteiros "
                    "para caracter";
            exit(1);
        }

        int i = 0;
        char p[30];

        while (ifs.good() && i < n) {
            ifs >> p;

            palavras[i] = new (nothrow) char[strlen(p) + 1];

            if (!palavras[i]) {
                cout << "Nao conseguiu alocar memoria para a palavra " << p;
                exit(1);
            }

            strcpy(palavras[i], p);
            // cout << endl << i+1 << " - " << palavras[i] << " ";
            i++;
        }

        if (i < n) {
            n = i;
            cout << "Apenas" << n << " palavras forma carregadas\n";
        }

        ifs.close();
    } else
        cout << "\nNão abriu!";
}

// destrutor do dicionario
dicionario::~dicionario() {
    for (int i = 0; i < n; i++) {
        delete[] palavras[i];
        palavras[i] = 0;
    }

    delete[] palavras;
    palavras = 0;
}

bool dicionario::checarOrdenado() {
    for (int i = 1; i < n; i++) {
        if (strcmpi(palavras[i - 1], palavras[i]) > 0)
            return false;
    }
    return true;
}

void dicionario::embaralhar(int m) {
    if (m == -1 || m >= n)
        m = n - 1;
    for (int i = 0; i < m; i++) {
        int r = (rand() % (n - i - 1)) + 1;
        swap(palavras[i], palavras[i + r]);
    }
}
