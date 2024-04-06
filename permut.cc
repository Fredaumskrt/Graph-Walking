#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Função para verificar se a permutação dada representa um ciclo em um grafo não direcionado simples
bool isCycle(const vector<int>& perm) {
  set<int> visited;  // Conjunto para armazenar vértices já visitados
  for (int i = 0; i < perm.size() - 1; i++) {
    if (visited.find(perm[i]) != visited.end()) {
      return false; // Vértice já visitado
    }
    visited.insert(perm[i]);

    // Verifica se a aresta já foi percorrida
    if (find(perm.begin() + i + 1, perm.end(), perm[i]) != perm.end()) {
      return false; // Aresta duplicada
    }
  }
  return true;
}

// Função para encontrar todos os ciclos em um grafo não direcionado simples usando permutação de vértices
vector<vector<int>> findCyclesWithPermutation(const vector<vector<int>>& graph) {
  vector<vector<int>> cycles;  // Vetor para armazenar os ciclos encontrados
  vector<int> perm;           // Vetor para armazenar a permutação atual
  set<vector<int>> permSet;   // Conjunto para armazenar permutações (evita duplicatas)

  int numVertices = graph.size();

  // Gera todas as permutações dos vértices
  for (int i = 0; i < numVertices; i++) {
    perm.push_back(i);
  }

  do {
    // Verifica se a permutação já foi explorada
    if (permSet.find(perm) != permSet.end()) {
      continue;
    }
    permSet.insert(perm);

    // Verifica se a permutação representa um ciclo em um grafo não direcionado simples
    if (isCycle(perm)) {
      // Adiciona o ciclo à lista de ciclos encontrados
      cycles.push_back(perm);
    }
  } while (next_permutation(perm.begin(), perm.end()));

  return cycles;
}

int main() {
  // Exemplo de grafo não direcionado simples
  vector<vector<int>> graph = {
    {1, 2}, {1, 3},
    {2, 3}
  };

  // Encontra todos os ciclos usando permutação de vértices
  vector<vector<int>> cycles = findCyclesWithPermutation(graph);

  // Imprime os ciclos encontrados
  cout << "Cycles found:" << endl;
  for (const auto& cycle : cycles) {
    for (int vertex : cycle) {
      cout << vertex << " ";
    }
    cout << endl;
  }

  return 0;
}
