#include <vector>

using namespace std;

class UnionFind {
    vector<int> parent, size;
public:
    UnionFind(int tamanho) {
        parent.resize(tamanho);
        size.resize(tamanho);
        for (int i=0; i<tamanho; i++) {
            parent[i] = i;
            size[i] = 1;
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

        if (size[rep_i] < size[rep_j]) {
            parent[rep_i] = rep_j;
            size[rep_j] += size[rep_i];
        }
        else {
            parent[rep_j] = rep_i;
            size[rep_i] += size[rep_j];
        }
    }
private:
    
};

int main() {
    return 0;
}
