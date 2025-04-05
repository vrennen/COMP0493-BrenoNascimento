#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    long long x, y;
};

bool compare(const Point &a, const Point &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

long long produtoVetorial(const Point &A, const Point &B, const Point &C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

vector<Point> convexHull(vector<Point> pts) {
    sort(pts.begin(), pts.end(), compare);
    // opcional
    pts.erase(unique(pts.begin(), pts.end(),
                [](const Point &p1, const Point &p2) {
                    return (p1.x == p2.x && p1.y == p2.y);
                }), 
            pts.end());
    if (pts.size() < 2)
        return pts;

    vector<Point> hull;
    for (int i=0; i<(int)pts.size(); i++) {
        while (hull.size() >= 2 && produtoVetorial(hull[hull.size()-2], hull[hull.size()-1], pts[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }
    for (int i=(int)pts.size()-2, t=hull.size()+1; i>=0; i--) {
       while ((int)hull.size() >= t && produtoVetorial(hull[hull.size()-2], hull[hull.size()-1], pts[i]) <= 0) { 
           hull.pop_back();
       }
       hull.push_back(pts[i]);
    }
    hull.pop_back();
    return hull;
}

int main() {
    return 0;
}
