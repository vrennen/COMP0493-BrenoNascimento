#include <iostream>
#include <vector>
using namespace std;

string LongestCommonPrefix(string S, int m) {
    string lps;
    int i = 1;
    int j = 0;
    while (i<m) {
        if (S[i] == S[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else {
            if (j != 0) {
                j = lps[j-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMP(string T, int n, string S, int m) {
    string lps = LongestCommonPrefix(S, S.size());
    int i=0, j=0;
    vector<int> posicoes;
    while (i<n) {
        if (S[j] == T[i]) {
            i++;
            j++;
            if (j==m) {
                posicoes.push_back(i-j);
                j = lps[j-1];
            }
        }
        else {
            if (j != 0)
                j = lps[j-1];
            else 
                i++;
        }
    }
    return posicoes;
}

int main() {
    string t = "muinto facil";
    string s = "facil";
    vector<int> posi = KMP(t, t.length(), s, s.length());
    for (int i: posi) {
        cout << i << " " << endl;
    }
    return 0;
}
