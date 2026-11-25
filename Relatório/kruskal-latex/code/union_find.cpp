#include "union_find.hpp"

// Inicializa o vetor pai de forma que cada elemento seja seu próprio pai,
// e o tamanho do grupo seja 1 para cada elemento.
void inicializaUF(UnionFind &uf, int n) {
    uf.pai.assign(n, 0);
    uf.tamanhoGrupo.assign(n, 1);
    for (int i = 0; i < n; ++i){
        uf.pai[i] = i;
    }
}

// Retorna o representante do conjunto de x, com compressão de caminho.
int find(UnionFind &uf, int x) {
    if (uf.pai[x] != x) {
        uf.pai[x] = find(uf, uf.pai[x]); // Path compression
    }
    return uf.pai[x];
}

// Une os conjuntos de a e b (união por tamanho).
// Retorna true se uniu e false se já estavam no mesmo conjunto.
bool unir(UnionFind &uf, int a, int b) {
    int rootA = find(uf, a);
    int rootB = find(uf, b);
    if (rootA != rootB) {
        // O menor grupo é anexado ao maior grupo
        if (uf.tamanhoGrupo[rootA] < uf.tamanhoGrupo[rootB]) {
            uf.pai[rootA] = rootB;
            uf.tamanhoGrupo[rootB] += uf.tamanhoGrupo[rootA];
        } else {
            uf.pai[rootB] = rootA;
            uf.tamanhoGrupo[rootA] += uf.tamanhoGrupo[rootB];
        }
        return true;
    }
    return false;
}
