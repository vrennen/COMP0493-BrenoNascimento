#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

string vogais = "aeiouAEIOU";

int main (int argc, char *argv[]) {
    ifstream entrada("t3.in");
    string T, R="";
    int numDigitos=0, numVogais=0, numConsoantes=0;
    getline(entrada, T);
    for (char l: T) {
        R += tolower(l);
        if (isdigit(l))
            numDigitos++;
        if (isalpha(l)) {
            if (vogais.find(l) != -1)
                numVogais++;
            else {
                numConsoantes++;
            }
        }
    }
    cout << R << endl;
    cout << "Digitos: " << numDigitos << endl;
    cout << "Vogais: " << numVogais << endl;
    cout << "Consoantes: " << numConsoantes << endl;

    return 0;
}
