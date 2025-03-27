//#include <vector>
//#include <pair>
//#include <priority_queue>
//#include <utility>
#include <bits/stdc++.h>

using namespace std;

/*
 * Função Prim(Grafo G, Vértice raiz):
 *     Inicialize um vetor 'key' com INFINITO para todos os vértices
 *     inicialize 'key[raiz] = 0'
 *     Inicialize um vetor 'parent' com -1
 *     Crie uma fila de prioridade (min-heap) 'pq' e insira (0, raiz)
 *     Inicialize um vetor 'visited' como falso
 *
 *     Enquanto pq não estiver vazia:
 *         u = extrair vértice com menor 'key' de pq
 *         Se visited[u] é verdadeiro, continue
 *         Marque visited[u] como verdadeiro
 *
 *         Para cada vértice v adjacente a u:
 *             Se visited[v] é falso E peso(u, v) < key[v]:
 *                 Atualize key[v] = peso(u, v)
 *                 Atualize parent[v] = u
 *                 Insira (key[v], v) em pq
 *     Retorne parent e key
 */
int prim(vector<vector<pair<int, int>>> adj, int M) {
    vector<int> key(M, INT_MAX);
    key[0] = 0;
    vector<int> parent(M, -1);
    vector<bool> visited(M, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, 0);

    int total = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int current_lkey = pq.top().first;
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        total += current_lkey;

        for (auto &edge: adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (!visited[v] && w < key[v]) {
                key[v] = w;
                pq.emplace(w, v);
            }
        }
    }
    return total;
}
int main() {
    return 0;
}
