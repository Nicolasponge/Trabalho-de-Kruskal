#include "visualizacao.hpp"
#include <fstream>
#include <iostream>

static bool estaDestacada(const Aresta &a, const std::vector<Aresta> &destacadas) {
    for (const auto &d : destacadas) {
        if ((d.vertOrigem == a.vertOrigem && d.vertDestino == a.vertDestino) ||
            (d.vertOrigem == a.vertDestino && d.vertDestino == a.vertOrigem)) {
            return true;
        }
    }
    return false;
}

void exportarDot(const Grafo &g, const std::vector<Aresta> &destacadas, const std::string &caminho,
                 bool soDestacadas) {
    std::ofstream arq(caminho);
    if (!arq.is_open()) {
        std::cerr << "Não foi possível criar " << caminho << std::endl;
        return;
    }
    // "graph" com "--" = grafo NÃO direcionado
    arq << "graph G {\n";
    arq << "  layout=neato; overlap=false; splines=true;\n";
    arq << "  node [shape=circle, style=filled, fillcolor=\"#E1F5EE\", fontname=\"Arial\"];\n";
    arq << "  edge [fontname=\"Arial\", fontsize=10];\n";
    for (int i = 0; i < g.numVertices; ++i) {
        arq << "  " << i << " [label=\"" << g.nomesVertices[i] << "\"];\n";
    }
    bool temDestaque = !destacadas.empty();
    for (const auto &a : g.arestas) {
        arq << "  " << a.vertOrigem << " -- " << a.vertDestino << " [label=\"" << a.peso << "\"";
        bool destacada = estaDestacada(a, destacadas);
        if (soDestacadas && !destacada) {
            arq << ", style=invis";
        } else if (temDestaque) {
            if (destacada) arq << ", color=red, penwidth=3";
            else arq << ", color=gray, style=dashed";
        }
        arq << "];\n";
    }
    arq << "}\n";
    std::cout << "Desenho salvo em " << caminho << std::endl;
}
