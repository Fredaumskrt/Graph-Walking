#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Grafo {
int V; // vertices

vector<vector<int>> adj; // lista 

public:
Grafo(int V) {
this->V = V;
adj.resize(V);
}


void adicionarAresta(int v, int w) {
adj[v].push_back(w);
adj[w].push_back(v);
}


bool bfs(int origem, int destino) {

vector<bool> visitado(V, false);
    vector<int> pai(V, -1); // Armazena o vértice que originou a visita


queue<int> fila;

visitado[origem] = true;
fila.push(origem);

while (!fila.empty()) {

int atual = fila.front();
fila.pop();


if (atual == destino) {
  // Reconstruindo o caminho
  vector<int> caminho;
  int v = destino;
  while (v != origem) {
    caminho.push_back(v);
    v = pai[v];
  }
  caminho.push_back(origem);

  // Revertendo a ordem do caminho
  reverse(caminho.begin(), caminho.end());

  // Imprimindo o caminho
  cout << "Caminho entre " << origem << " e " << destino << ": ";
  for (int i : caminho) {
    cout << i << " ";
  }
  cout << endl;

  return true;
}


for (int i : adj[atual]) {
if (!visitado[i]) {
visitado[i] = true;
          pai[i] = atual;
fila.push(i);
}
}
}


return false;
}
};

int main() {
// Grafo 1
Grafo grafo1(5);
grafo1.adicionarAresta(0, 1);
grafo1.adicionarAresta(0, 2);
grafo1.adicionarAresta(2, 3);
grafo1.adicionarAresta(3, 4);
grafo1.bfs(0, 4);

// Grafo 2
Grafo grafo2(5);
grafo2.adicionarAresta(0, 1);
grafo2.adicionarAresta(0, 2);
grafo2.adicionarAresta(1, 2);
grafo2.adicionarAresta(1, 3);
grafo2.adicionarAresta(2, 4);
grafo2.bfs(0, 4);

return 0;
}
