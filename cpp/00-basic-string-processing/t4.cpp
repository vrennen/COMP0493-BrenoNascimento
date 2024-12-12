#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
using namespace std;

string vogais = "aeiouAEIOU";

int main (int argc, char *argv[]) {
    ifstream entrada("t4.in");
    string T, R="";
    getline(entrada, T);
    vector<string> tokens;
    for (char l: T) 
        R += tolower(l);
    int pos = 0;
    while (R.find(" ") != -1 || R.find(".") != -1) {
        pos = min((unsigned int)R.find(' '), (unsigned int)R.find("."));
        string token = R.substr(0, pos);
        if (!token.empty())
            tokens.push_back(token);
        R.erase(0, pos+1);
    }
    tokens.push_back(R);

    for (int i=0; i<tokens.size()-1; i++) {
        int menor = i;
        for (int j=i; j<tokens.size(); j++) {
            if (tokens[menor].compare(tokens[j]) > 0)
                menor = j;
        }
        string temp = tokens[i];
        tokens[i] = tokens[menor];
        tokens[menor] = temp;
    }

    for (string s: tokens) {
        cout << s << endl;
    }

    return 0;
}
