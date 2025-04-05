#include <vector>

using namespace std;

long long int fatorial(int n) {
    if (n < 1)
        return 1;
    return n * fatorial(n-1);
}

long long int combinacao(int n, int m) {
    return fatorial(n) / (fatorial(n-p) * fatorial(p));
}

int CoeficienteBinomialAnalitico(int n, int m) {
    //TODO
}

int CoeficienteBinomialRecursivo(int n, int m) {
    if (n == 0 || n == m)
        return 1;
    return CoeficienteBinomialRecursivo(n-1, m-1) + CoeficienteBinomialRecursivo(n-1, m);
}

int CoeficienteBinomialRecursivoDP(int n, int m) {
    vector<int> dp(m+1, 0);
    dp[0] = 1;

    for (int i=1; i<=n; i++) {
        for (int j=min(i,m); j>0; j--) {
            dp[j] = dp[j] + dp[j-1];
        }
    }
    return dp[m];
}

int main() {
    return 0;
}
