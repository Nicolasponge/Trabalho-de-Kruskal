#include "union_find.hpp"

// Ele inicializa o vetor pai de forma que cada elemento seja seu próprio pai, e o tamanho do grupo seja 1 para cada elemento.
void inicializaUF(UnionFind &uf, int n) {
    uf.pai.assign(n, 0);
    uf.tamanhoGrupo.assign(n, 1);
    for (int i = 0; i < n; ++i){
        uf.pai[i] = i;
    }
}

// A função find retorna o representante do conjunto ao qual o elemento x pertence. Ela também aplica a técnica de "path compression" para otimizar futuras consultas.
int find(UnionFind &uf, int x) {
    if (uf.pai[x] != x) {
        uf.pai[x] = find(uf, uf.pai[x]); // Path compression
    }
    return uf.pai[x];
} 

// A função unir une os conjuntos que contêm os elementos a e b. Ela utiliza a técnica de "union by size" para manter a árvore de conjuntos equilibrada. Retorna true se a união foi bem-sucedida e false se já estavam no mesmo conjunto
bool unir(UnionFind &uf, int a, int b) {
    int rootA = find(uf, a);
    int rootB = find(uf, b);
    if (rootA != rootB) {
        // Union por tamanho de grupo: o menor grupo é anexado ao maior grupo
        if (uf.tamanhoGrupo[rootA] < uf.tamanhoGrupo[rootB]) {
            uf.pai[rootA] = rootB;
            uf.tamanhoGrupo[rootB] += uf.tamanhoGrupo[rootA];
        } else {
            uf.pai[rootB] = rootA;
            uf.tamanhoGrupo[rootA] += uf.tamanhoGrupo[rootB];
        }
        return true; // A união foi bem-sucedida
    }
    return false; // Já estão no mesmo conjunto
} 