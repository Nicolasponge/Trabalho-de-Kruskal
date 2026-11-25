#ifndef LEITURA_BIB
#define LEITURA_BIB

#include <string>
#include "grafo.hpp"

// Lê um grafo de um arquivo de texto no formato:
//   linha 1: numVertices numArestas
//   linha 2: nome de cada vértice, separados por espaço (use _ no lugar de espaço no nome)
//   demais linhas: origem destino peso   (uma aresta por linha, usando os nomes)
// Retorna false se o arquivo não abrir ou tiver algum erro.
bool lerGrafo(const std::string &caminho, Grafo &g);

#endif
