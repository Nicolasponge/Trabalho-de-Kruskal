#ifndef UNIONFIND_BIB
#define UNIONFIND_BIB

#include <vector>

struct UnionFind {
    std::vector<int> pai;
    std::vector<int> tamanhoGrupo;
};

void inicializaUF(UnionFind &uf, int n);
int  find(UnionFind &uf, int x);
bool unir(UnionFind &uf, int a, int b);

#endif