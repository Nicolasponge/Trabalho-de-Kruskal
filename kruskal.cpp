#include "kruskal.hpp"
#include "union_find.hpp"
#include <algorithm>

ResultadoKruskal kruskal(const Grafo &g, int k) {
    ResultadoKruskal resultado;
    resultado.custoTotal = 0;

    // Ordenar as arestas pelo peso
    std::vector<Aresta> arestasOrdenadas = g.arestas;
    std::sort(arestasOrdenadas.begin(), arestasOrdenadas.end(), [](const Aresta &a, const Aresta &b) {
        return a.peso < b.peso;
    });

    // Inicializar o conjunto de união
    UnionFind uf;
    inicializaUF(uf, g.numVertices);

    // Para cada aresta em ordem crescente de peso
    for (const auto &aresta : arestasOrdenadas) {
        // Se os vértices não pertencem ao mesmo conjunto
        if (unir(uf, aresta.vertOrigem, aresta.vertDestino)) {
            // Tenta unir os conjuntos

            // Adicionar a aresta ao resultado
            resultado.arvore.push_back(aresta);
            resultado.custoTotal += aresta.peso;
        }
        // Se já temos k grupos, paramos
        if (static_cast<int>(resultado.arvore.size()) == g.numVertices - k) {
            break;
        }
    }

    return resultado;
}