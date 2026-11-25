#include "leitura.hpp"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <algorithm>

// Troca '_' por espaço, para "Foz_do_Jordão" aparecer como "Foz do Jordão" na tela.
static std::string nomeParaExibir(std::string nome) {
    std::replace(nome.begin(), nome.end(), '_', ' ');
    return nome;
}

bool lerGrafo(const std::string &caminho, Grafo &g) {
    std::ifstream arq(caminho);
    if (!arq.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo: " << caminho << std::endl;
        return false;
    }

    int numVertices, numArestas;
    if (!(arq >> numVertices >> numArestas) || numVertices <= 0 || numArestas < 0) {
        std::cerr << "Cabeçalho inválido em " << caminho << std::endl;
        return false;
    }
    inicializaGrafo(g, numVertices);

    // "Tradutor" nome -> índice. Só existe aqui na leitura:
    // o Kruskal e o Union-Find trabalham apenas com os índices.
    std::unordered_map<std::string, int> indiceDoNome;
    for (int i = 0; i < numVertices; ++i) {
        std::string nome;
        arq >> nome;
        indiceDoNome[nome] = i;
        defineNomeVertice(g, i, nomeParaExibir(nome));
    }

    for (int e = 0; e < numArestas; ++e) {
        std::string origem, destino;
        double peso;
        if (!(arq >> origem >> destino >> peso)) {
            std::cerr << "Aresta " << e + 1 << " incompleta em " << caminho << std::endl;
            return false;
        }
        if (!indiceDoNome.count(origem) || !indiceDoNome.count(destino)) {
            std::cerr << "Vértice desconhecido na aresta " << origem << " -- " << destino << std::endl;
            return false;
        }
        adicionaAresta(g, indiceDoNome[origem], indiceDoNome[destino], peso);
    }
    return true;
}
