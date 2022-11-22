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
#include <ostream>
#include <stdio.h>
#include <vector>

using namespace std;

void mean_error(vector<long long> const &times, double &mean_, double &error_) {
    if (times.empty())
        return;
    double sum = 0.0;
    double sq_sum = 0.0;
    for (int i = 0; i < times.size(); i++) {
        double time = (double)times[i] / 1'000'000'000.0;
        sum += time;
        sq_sum += time * time;
    }

    double n = times.size();
    sum = sum / n;

    double mean = sum / n;
    double var = (sq_sum - sum * sum) / (n - 1.0);

    double error = sqrt(var / n);

    double t[2];
    mean_ = sum;
    error_ = error;
}

void print_error(double mean, double error) {

    int exp = (int)ceil(log10(mean));
    int err_exp = (int)ceil(log10(error));
    if (error > mean)
        exp = err_exp;

    int digitos = (exp - err_exp) + 2;

    if (digitos > 5) {
        digitos = 5;
    }

    printf("\t%.*fe%d±%.*fe%d", digitos, mean / pow(10.0, exp), exp, digitos,
           error / pow(10.0, exp), exp);
}

void bench(dicionario &a, void (*fun)(char **, int)) {
    vector<long long> times(1'000'000);
    for (int n = 1; n < 20'000; n = 2 * n) {
        // em nanosegundos
        unsigned long long total_time = 0;
        times.clear();

        int t = 0;
        for (t = 1; t < 1'000'000'000; t++) {
            a.embaralhar(n);

            auto start = std::chrono::high_resolution_clock::now();
            fun(a.palavras, n);
            auto end = std::chrono::high_resolution_clock::now();
            long long time =
                chrono::duration_cast<chrono::nanoseconds>(end - start).count();

            total_time += time;
            times.push_back(time);

            // if (!a.checarOrdenado()) {
            //     cout << "Ordenação falhou";
            //     exit(1);
            // }

            // maior que 5 segundos
            if (total_time > 5'000'000'000 && t >= 5) {
                break;
            }
        }

        double mean;
        double error;
        mean_error(times, mean, error);

        print_error(mean, error);
        flush(cout);
    }
}

int main() {
    // setlocale(LC_ALL, "");

    dicionario a = dicionario(40'000);
    a.embaralhar();
    a.n = 16'384;

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
