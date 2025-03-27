#include <vector>

using namespace std;

class UnionFind {
    vector<int> parent;
public:
    UnionFind(int tamanho) {
        parent.resize(tamanho);
        for (int i=0; i<tamanho; i++)
            parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return find(parent[i]);
    }
    void unite(int i, int j) {
        int rep_i = find(i);
        int rep_j = find(j);
        parent[rep_i] = rep_j;
    }
private:
    
};

int main() {
    return 0;
}
