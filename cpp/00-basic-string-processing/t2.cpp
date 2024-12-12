#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main (int argc, char *argv[]) {
    ifstream entrada("t2.in");
    string T, P;
    vector<int> matches;
    getline(entrada, T);
    getline(entrada, P);
    for (int i=0; i<T.size(); i++) {
        if (T.substr(i, P.size()) == P)
            matches.push_back(i);
    }
    if (!matches.size())
        matches.push_back(-1);
    for (int i=0; i<matches.size(); i++) {
        cout << matches[i] << ' ';
    }
    cout << endl;
    return 0;
}
