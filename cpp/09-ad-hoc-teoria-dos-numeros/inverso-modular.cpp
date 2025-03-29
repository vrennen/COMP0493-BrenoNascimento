using namespace std;

int extEuclid(int a, int b, int &x, int &y) {
    int xx = y = 0;
    int yy = x = 1;
    while (b) {
        int q = a/b;
        int t = b; b = a%b; a = t;
        t = xx; xx = x - q * xx; x = t;
        t = yy; yy = y - q * yy; y = t;
    }
    return a;
}

int mod(int a, int m) {
    return ((a%m) + m) % m;
}

int modInverse(int b, int m) {
    int x,y;
    int d = extEuclid(b, m, x, y);
    if (d != 1) return -1;
    return mod(x, m);
}

int main() {
    return 0;
}
