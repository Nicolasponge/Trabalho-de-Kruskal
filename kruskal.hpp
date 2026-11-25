#ifndef KRUSKAL_BIB
#define KRUSKAL_BIB

#include <vector>
#include "grafo.hpp"

struct ResultadoKruskal {
    std::vector<Aresta> arvore;   // arestas aceitas
    double custoTotal;
};
ResultadoKruskal kruskal(const Grafo &g, int k);  // k = 1: árvore inteira; k > 1: para com k grupos

#endif