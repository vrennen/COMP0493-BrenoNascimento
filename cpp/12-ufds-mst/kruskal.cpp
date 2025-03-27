#include <bits/stdc++.h>

using namespace std;

/*
 * kruskal's algorithm for mst
 * 1: Input: Graph G = (V,E) with weights on edges
 * 2: Output: Minimum Spanning Tree T
 * 3: Sort edges E by increasing weight
 * 4: Initialize T <- {}
 * 5: for each edge e in E do
 * 6:     if adding e to T does not form a cycle then
 * 7:         Add e to T
 * 8:     else
 * 9:         Ignore e
 * 10:    end if
 * 11:end for
 * 12:return T
 */
class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int tamanho) {
        parent.resize(tamanho);
        rank.resize(tamanho);
        for (int i=0; i<tamanho; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return find(parent[i]);
    }
    void unite(int i, int j) {
        int rep_i = find(i);
        int rep_j = find(j);
        if (rep_i == rep_j) return;

        if (rank[rep_i] < rank[rep_j])
            parent[rep_i] = rep_j;
        else if (rank[rep_j] < rank[rep_i])
            parent[rep_j] = rep_i;
        else {
            parent[rep_j] = rep_i;
            rank[rep_i]++;
        }
    }
private:
    
};
bool comparator(vector<int> &a, vector<int> &b) {
    if (a[2] <= b[2]) return true;
    return false;
}
int kruskal(int V, vector<vector<int>> &edges) {
    sort(edges.begin(), edges.end(),comparator);
    
    UnionFind uf(V);
    int cost = 0, count = 0;
    
    for (auto &e : edges) {
        int x = e[0], y = e[1], w = e[2];
        
        // Make sure that there is no cycle
        if (uf.find(x) != uf.find(y)) {
            uf.unite(x, y);
            cost += w;
            if (++count == V - 1) break;
        }
    }
    return cost;
}
int main() {
    return 0;
}
