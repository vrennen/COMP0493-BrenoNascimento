#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main (int argc, char *argv[]) {
    ifstream entrada("t1.in");
    string linha, T="";

    while (getline(entrada, linha)) {
        if (linha.substr(0,7) == ".......")
            break;
        T += linha + ' ';
    }
    cout << T << endl;
    return 0;
}
