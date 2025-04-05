#include <cmath>
#include <vector>
#include <climits>

using namespace std;

struct Point {
    long long x, y;
};

int closestPairBruteForce(vector<Point> p) {
    int d = INT_MAX;
    for (int i=1; i<p.size()-1; i++) {
        for (int j=i+1; j<p.size(); j++) {
            d = min((double)d, sqrt((p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y)));
        }
    }
    return d;
}

int closestPairOptimized(vector<Point> p) {
    //TODO
    return 0;
}

int main() {
    return 0;
}
