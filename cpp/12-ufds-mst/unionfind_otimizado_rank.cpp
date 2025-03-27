#include <vector>

using namespace std;

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

int main() {
    return 0;
}
