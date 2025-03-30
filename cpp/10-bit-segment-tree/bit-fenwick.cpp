#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> ft;
public:
    FenwickTree(int m) {
        ft.assign(m+1, 0);
    }
    
    void build(const vector<long long> &f) {
        int m = (int)f.size()-1;
        ft.assign(m+1, 0);
        for (int i=1; i<=m; ++i) {
            ft[i] += f[i];
            if (i + (i & -i) <= m)
                ft[i + (i & -i)] += ft[i];
        }
    }

    FenwickTree(const vector<long long> &f) {
        build(f);
    }
    
    FenwickTree(int m, const vector<int> &s) {
        vector<long long> f(m+1, 0);
        for (int i=0; i<s.size(); ++i)
            ++f[s[i]];
        build(f);
    }

    int rsq(int j) { // range sum query [1..j]
        int sum = 0;
        for (; j; j -= (j & -j))
            sum += ft[j];
        return sum;
    }
    int rsq(int i, int j) { // range sum query [i..j]
        return rsq(j) - rsq(i-1);
    }
    
    void update(int i, int v) {
        for (; i < (int)ft.size(); i+= (i & -i))
            ft[i] += v;
    }
};


int main() {
    return 0;
}
