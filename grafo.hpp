#ifndef GRAFO_BIB
#define GRAFO_BIB

#include <vector>
#include <string>

struct Aresta {
    double peso; // Como vamos trablhar nos exemplos com distâncias, vale a pena usar double
    int vertOrigem;
    int vertDestino;
};

struct Grafo {
    std::vector<std::string> nomesVertices; // Para armazenar os nomes dos vértices
    int numVertices;
    std::vector<Aresta> arestas;
};

void inicializaGrafo(Grafo &g, int numVertices);
void defineNomeVertice(Grafo &g, int vertice, const std::string &nome);
void adicionaAresta(Grafo &g, int vertOrigem, int vertDestino, double peso);
void imprimeGrafo(const Grafo &g, bool comPesos = true);

#endif