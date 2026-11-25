#include "grafo.hpp"
#include "union_find.hpp"
#include "kruskal.hpp"
#include "leitura.hpp"
#include "visualizacao.hpp"
#include <iostream>
#include <map>
#ifdef _WIN32
#include <windows.h>
#endif

// Mostra as arestas escolhidas pelo Kruskal e o custo total.
// Se k > 1, mostra também quais vértices ficaram em cada grupo.
void imprimeResultado(const Grafo &g, const ResultadoKruskal &r, int k) {
    std::cout << "\n=== Resultado do Kruskal (k = " << k << ") ===\n";
    int n = 1;
    for (const auto &a : r.arvore) {
        std::cout << "  " << n++ << ". " << g.nomesVertices[a.vertOrigem] << " -- "
                  << g.nomesVertices[a.vertDestino] << "  (peso " << a.peso << ")\n";
    }
    std::cout << "  Arestas escolhidas: " << r.arvore.size()
              << "   Custo total: " << r.custoTotal << "\n";

    if (k > 1) {
        // Reconstrói os grupos com um Union-Find usando só as arestas escolhidas
        UnionFind uf;
        inicializaUF(uf, g.numVertices);
        for (const auto &a : r.arvore) unir(uf, a.vertOrigem, a.vertDestino);
        std::map<int, std::vector<int>> grupos;
        for (int v = 0; v < g.numVertices; ++v) grupos[find(uf, v)].push_back(v);
        int i = 1;
        for (const auto &par : grupos) {
            std::cout << "  Grupo " << i++ << ": ";
            for (int v : par.second) std::cout << g.nomesVertices[v] << "  ";
            std::cout << "\n";
        }
    }
}

// Lê o grafo do arquivo, roda o Kruskal, imprime e gera os desenhos (antes e depois).
void executa(const std::string &arquivo, int k, const std::string &nomeSaida) {
    Grafo g;
    if (!lerGrafo(arquivo, g)) return;

    std::cout << "\n=== Grafo lido de " << arquivo << " ===\n";
    if (g.arestas.size() <= 30) {
        imprimeGrafo(g);
    } else {
        // Grafo grande demais para listar no terminal (ex.: motoboys, onde todo pedido liga com todo pedido)
        std::cout << "Número de vértices: " << g.numVertices
                  << "\nArestas: " << g.arestas.size() << " (lista omitida por ser longa)\n";
    }

    ResultadoKruskal r = kruskal(g, k);
    imprimeResultado(g, r, k);

    bool grafoGrande = g.arestas.size() > 30;
    if (!grafoGrande) exportarDot(g, {}, "saida/" + nomeSaida + "_original.dot");
    exportarDot(g, r.arvore, "saida/" + nomeSaida + "_resultado.dot", grafoGrande);
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    int opcao = -1;
    while (opcao != 0) {
        std::cout << "\n====== Algoritmo de Kruskal ======\n"
                  << "1. Exemplo ilustrativo (grafo A-F)\n"
                  << "2. Rede elétrica entre cidades da região de Guarapuava\n"
                  << "3. Divisão de pedidos entre motoboys (k grupos)\n"
                  << "4. Carregar outro arquivo\n"
                  << "0. Sair\n"
                  << "Opção: ";
        if (!(std::cin >> opcao)) break;

        if (opcao == 1) {
            executa("dados/ilustrativo.txt", 1, "ilustrativo");
        } else if (opcao == 2) {
            executa("dados/rede_eletrica.txt", 1, "rede_eletrica");
        } else if (opcao == 3) {
            int k;
            std::cout << "Quantos motoboys (grupos)? ";
            std::cin >> k;
            if (k < 1) k = 1;
            executa("dados/motoboys.txt", k, "motoboys");
        } else if (opcao == 4) {
            std::string caminho;
            int k;
            std::cout << "Caminho do arquivo: ";
            std::cin >> caminho;
            std::cout << "Número de grupos k (1 = árvore completa): ";
            std::cin >> k;
            if (k < 1) k = 1;
            executa(caminho, k, "personalizado");
        } else if (opcao != 0) {
            std::cout << "Opção inválida.\n";
        }
    }
    return 0;
}
