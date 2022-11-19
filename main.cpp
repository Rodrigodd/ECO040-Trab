// Jean Tan Li 2017011255
// Lucas Gaburro Dadalto 2017003781
// Márcio Tan Li 2017011282
// 20/11/2017 - Trabalho 5 de Ordenação
// Programa que ordena palavras, e possibilita escolher qual tipo de ordenação
// que desejar.
#include "dicionario.h"
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void bench(dicionario &a, void (*fun)(char **, int)) {
    for (int n = 1; n < 20'000; n = 2 * n) {
        a.n = n;

        // em nanosegundos
        unsigned long long int total_time = 0;

        int t = 0;
        for (t = 1; t < 1'000'000; t++) {
            a.embaralhar();

            auto start = std::chrono::high_resolution_clock::now();
            fun(a.palavras, a.n);
            auto end = std::chrono::high_resolution_clock::now();
            total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(
                              end - start)
                              .count();

            // if (!a.checarOrdenado()) {
            //     cout << "Ordenação falhou";
            //     exit(1);
            // }

            // maior que 5 segundos
            if (total_time > 5'000'000'000) {
                break;
            }
        }

        double tempo = (double)total_time / 1'000'000'000.0 / (double)t;

        int digitos = (int)(-log10(tempo) + 4);
        if (digitos < 2)
            digitos = 2;

        printf("\t%.*f", digitos, tempo);
    }
}
int main() {
    /* setlocale(LC_ALL, "Portuguese"); */

    dicionario a = dicionario(40'000);

    struct {
        char const *name;
        void (*fun)(char **, int);
    } funcoes[7] = {
        {"Bubble1", Bubble1},     {"Bubble2", Bubble2},
        {"Selection", Selection}, {"Insertion", Insertion},
        {"Quicksort", Quicksort}, {"Mergesort", Mergesort},
        {"HeapSort", HeapSort},
    };

    for (int n = 1; n < 20'000; n = 2 * n) {
        cout << "\t" << n;
    }
    cout << endl;
    for (auto fun : funcoes) {
        cout << fun.name;
        bench(a, fun.fun);
        cout << endl;
    }

    return 0;
}
