#ifndef VISUALIZACAO_BIB
#define VISUALIZACAO_BIB

#include <string>
#include <vector>
#include "grafo.hpp"

// Gera um arquivo .dot (formato do Graphviz) para desenhar o grafo.
// As arestas que estão em "destacadas" saem grossas e vermelhas; as outras, tracejadas e cinza.
// Para desenhar: cole o conteúdo em https://dreampuf.github.io/GraphvizOnline
// ou rode: dot -Tpng arquivo.dot -o arquivo.png
// Se soDestacadas for true, desenha apenas as arestas destacadas (útil para grafos com muitas arestas).
void exportarDot(const Grafo &g, const std::vector<Aresta> &destacadas, const std::string &caminho,
                 bool soDestacadas = false);

#endif
