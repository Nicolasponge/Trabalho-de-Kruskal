#include "grafo.hpp"
#include <iostream>

void inicializaGrafo(Grafo &g, int numVertices) {
    g.numVertices = numVertices;
    g.arestas.clear();
    g.nomesVertices.resize(numVertices);
}

void defineNomeVertice(Grafo &g, int vertice, const std::string &nome) {
    if (vertice >= 0 && vertice < g.numVertices) {
        g.nomesVertices[vertice] = nome;
    } else {
        std::cerr << "Índice de vértice inválido: " << vertice << std::endl;
    }
}

void adicionaAresta(Grafo &g, int vertOrigem, int vertDestino, double peso) {
    Aresta a;
    a.vertOrigem = vertOrigem;
    g.nomesVertices[vertOrigem] = vertOrigem; // Para assegurar que não vai dar erro caso alguém não dê um nome para um vértice
    
    a.vertDestino = vertDestino;
    g.nomesVertices[vertDestino] = vertDestino; // Para assegurar que não vai dar erro caso alguém não dê um nome para um vértice

    a.peso = peso;
    g.arestas.push_back(a);
}

void imprimeGrafo(const Grafo &g, bool comPesos) {
    std::cout << "Número de vértices: " << g.numVertices << std::endl;
    std::cout << "Arestas:" << std::endl;
    for (const auto &a : g.arestas) {
        std::cout << g.nomesVertices[a.vertOrigem] << " -- " << g.nomesVertices[a.vertDestino];
        if (comPesos) {
            std::cout << " (peso: " << a.peso << ")";
        }
        std::cout << std::endl;
    }
}