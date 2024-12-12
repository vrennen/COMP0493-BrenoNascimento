#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main (int argc, char *argv[]) {
    ifstream entrada("t1.in");
    string linha, T="";
    string extra;

    while (getline(entrada, linha)) {
        if (linha.substr(0,7) == ".......") {
            getline(entrada, extra);
            break;
        }
        T += linha + ' ';
    }
    cout << T << endl;
    cout << "a linha extra tem " << extra.size() << " caracteres" << endl;
    return 0;
}
