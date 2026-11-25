# Algoritmo de Kruskal

Trabalho final da disciplina de Estrutura de Dados e Algoritmos em Grafo (Unicentro, 2026, Prof. Me. João Duda), com o tema do Algoritmo de Kruskal.

O programa implementa em C++ o algoritmo de Kruskal para encontrar a **árvore geradora mínima** de um grafo ponderado e não direcionado. O teste de ciclo usa a estrutura **Union-Find** (conjuntos disjuntos), com compressão de caminho e união por tamanho.

## Como compilar e rodar

É preciso ter o `g++` com suporte a C++17.

```
g++ -std=c++17 -Wall *.cpp -o kruskal.exe
./kruskal.exe
```

Rode a partir da pasta do projeto, para o programa encontrar as pastas `dados/` e `saida/`.

## O que o programa faz

O menu tem quatro opções:

| Opção | Problema | Arquivo |
| --- | --- | --- |
| 1 | Exemplo ilustrativo: grafo abstrato com 6 vértices (A a F) e 9 arestas | `dados/ilustrativo.txt` |
| 2 | Rede elétrica entre 11 cidades da região de Guarapuava (PR) | `dados/rede_eletrica.txt` |
| 3 | Divisão de 12 pedidos de entrega entre k motoboys | `dados/motoboys.txt` |
| 4 | Qualquer outro grafo, no mesmo formato | caminho digitado |

Para cada grafo, o programa mostra as arestas lidas, as arestas escolhidas pelo Kruskal em ordem, o custo total e, quando k > 1, os grupos formados.

## Resultados

| Problema | Arestas escolhidas | Custo total |
| --- | --- | --- |
| Exemplo ilustrativo | 5 | 16 |
| Rede elétrica (11 cidades) | 10 | 294,6 km |
| Motoboys (k = 3) | 9 | 3 grupos de 4 pedidos |

As distâncias da rede elétrica são em linha reta entre as sedes dos municípios, calculadas a partir de coordenadas aproximadas. Os pedidos dos motoboys são fictícios.

## Estrutura do projeto

| Arquivo | Responsabilidade |
| --- | --- |
| `grafo.hpp/.cpp` | `struct Aresta` e `struct Grafo` (lista de arestas e nomes dos vértices) |
| `union_find.hpp/.cpp` | Union-Find: `inicializaUF`, `find` e `unir` |
| `kruskal.hpp/.cpp` | O algoritmo: `kruskal(grafo, k)` |
| `leitura.hpp/.cpp` | Leitura do grafo a partir de um arquivo `.txt` |
| `visualizacao.hpp/.cpp` | Gera arquivos `.dot` para desenhar o grafo no Graphviz |
| `main.cpp` | Menu e apresentação dos resultados |

O grafo é guardado como uma **lista de arestas**, porque o Kruskal só precisa percorrer as arestas em ordem de peso. Os vértices são números de 0 a n − 1; os nomes só aparecem na leitura e na impressão.

O parâmetro `k` da função `kruskal` define quando parar: com `k = 1` sai a árvore geradora mínima completa (n − 1 arestas); com `k > 1` sobram k grupos, o que permite usar o mesmo código para agrupar dados (opção 3).

## Formato dos arquivos de entrada

```
6 9            <- número de vértices e de arestas
A B C D E F    <- nomes dos vértices (use _ no lugar de espaço)
A B 4          <- uma aresta por linha: origem destino peso
B C 6
...
```

## Visualização

A cada execução o programa grava em `saida/` dois arquivos no formato DOT: o grafo original e o grafo com a árvore destacada em vermelho. Para ver o desenho, cole o conteúdo em [Graphviz Online](https://dreampuf.github.io/GraphvizOnline) ou rode `dot -Tpng arquivo.dot -o arquivo.png`. A visualização usa a ferramenta externa [Graphviz](https://graphviz.org); o algoritmo e o Union-Find são implementação própria.

## Complexidade

Tempo O(E log E), dominado pela ordenação das arestas; cada operação do Union-Find custa O(α(V)) em tempo amortizado. Memória O(V + E).

## Referências

- KRUSKAL, J. B. On the shortest spanning subtree of a graph and the traveling salesman problem. *Proceedings of the American Mathematical Society*, v. 7, n. 1, p. 48–50, 1956.
- CORMEN, T. H.; LEISERSON, C. E.; RIVEST, R. L.; STEIN, C. *Algoritmos: teoria e prática*. 3. ed. Rio de Janeiro: Elsevier, 2012.

Autor: Nícolas.
