#include <cmath>
using namespace std;

bool isPrimeBruteForce(int n) {
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    for (int i=2; i<n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isPrimeOtimizado(int n) {
    if (n < 2)
        return false;
    if (n ==2)
        return true;
    int limit = sqrt(n) +1;
    for (int i=0; i<limit; i+=2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    return 0;
}
