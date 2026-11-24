#include "grafo.hpp"
#include "union_find.hpp"
#include <windows.h>
#include <iostream>

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

    UnionFind uf;
    inicializaUF(uf, g.numVertices);
    std::cout << unir(uf, 1, 4) << "\n";  // B-E: espera 1
    std::cout << unir(uf, 0, 3) << "\n";  // A-D: espera 1
    std::cout << unir(uf, 0, 1) << "\n";  // A-B: espera 1
    std::cout << unir(uf, 3, 4) << "\n";  // D-E: espera 0, fecharia ciclo

    imprimeGrafo(g);
    return 0; 
}