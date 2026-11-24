#include "grafo.hpp"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Grafo g;
    inicializaGrafo(g, 6);

    adicionaAresta(g, 0, 1, 4);  // A -- B
    adicionaAresta(g, 1, 4, 2);  // B -- E
    adicionaAresta(g, 0, 3, 3);  // A -- D

    defineNomeVertice(g, 0, "A");
    defineNomeVertice(g, 1, "B");
    defineNomeVertice(g, 2, "C");
    defineNomeVertice(g, 3, "D");
    defineNomeVertice(g, 4, "E");
    defineNomeVertice(g, 5, "F");

    imprimeGrafo(g);
    return 0;
}