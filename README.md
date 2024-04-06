Este trabalho apresenta a implementação e análise comparativa de duas abordagens distintas
para resolver o problema de enumerar todos os ciclos em um grafo não direcionado simples.
Uma das abordagens é baseada na permutação dos vértices do grafo, enquanto a outra utiliza um
algoritmo de caminhamento em largura (BFS) no grafo. Além das implementações, realizamos
uma análise comparativa para avaliar suas diferenças de desempenho, especialmente à medida
que o tamanho do grafo aumenta.
Para a abordagem de permutação, implementamos um algoritmo que gera todas as permuta-
ções dos vértices do grafo e verifica se cada permutação representa um ciclo válido. Já para
a abordagem de caminhamento, desenvolvemos um algoritmo que utiliza BFS para explorar o
grafo em busca de ciclos. Em seguida, comparamos o tempo de execução e o uso de recursos
de ambas as abordagens em diferentes tamanhos de grafo.
Nossos experimentos demonstram que a eficiência e o desempenho dessas abordagens variam
de acordo com as características do grafo, como o número de vértices e arestas. Os resultados
obtidos fornecem insights valiosos sobre as vantagens e limitações de cada técnica, contribuindo
para uma melhor compreensão do problema de enumeração de ciclos em grafos não direciona-
dos.
