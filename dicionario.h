#ifndef DICIONARIO_H_INCLUDED
#define DICIONARIO_H_INCLUDED

void Bubble1(char **palavras, int n);
void Bubble2(char **palavras, int n);
void Selection(char **palavras, int n);
void Insertion(char **palavras, int n);
void Quicksort(char **palavras, int n);
void intercala(char **palavras, int n);
void Mergesort(char **palavras, int n);
void constroiHeap(char **palavras, int n);
void HeapSort(char **palavras, int n);

class dicionario {
  public:
    char **palavras;
    int n;

    void embaralhar();
    bool checarOrdenado();

    dicionario(int _n);
    ~dicionario();
};

#endif // DICIONARIO_H_INCLUDED
