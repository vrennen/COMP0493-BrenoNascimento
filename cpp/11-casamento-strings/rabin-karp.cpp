#include <iostream>
#include <vector>
using namespace std;

vector<int> RK(string T, string P) {
    int n = T.length();
    int b = P.length();
    if (b == 0 || b > n)
        return vector<int>(0);
    int p = 1e9 + 7;
    int c = 256;
    int h = 1;
    for (int i=1; i<=b-1; i++) {
        h = (h*c) % p;
    }
    int p_hash = 0;
    int t_hash = 0;

    for (int i=0; i<=b-1; i++) {
        p_hash = (c * p_hash + P[i]) % p;
        t_hash = (c * t_hash + T[i]) % p;
    }
    vector<int> ocorrencias;

    for (int i=0; i<=n-b; i++) {
        if (p_hash == t_hash) {
            bool combina = true;
            for (int j=0; j<=b-1; j++) {
                if (T[i+j] != P[j]) {
                    combina = false;
                    break;
                }
            }
            if (combina)
                ocorrencias.push_back(i);
        }
        if (i<n-b) {
            t_hash = ((t_hash - ((int)T[i]) * h) * c + ((int)T[i+b])) % p;
            if (t_hash<0) {
                t_hash = t_hash + p;
            }
        }
    }
    return ocorrencias;
}

int main() {
    vector<int> s = RK("muinto facil", "facil");
    for (int i: s) {
        cout << i << " " << endl;
    }
    return 1;
}
