#include <iostream>
#include <vector>
using namespace std;

void Preprocessa_Sufixo_Forte(vector<int> &shift, vector<int> &bpos, string padrao, int m) {
    int i = m;
    int j = m + 1;
    bpos[i] = j;

    while (i>0) {
        while (j <= m && padrao[i-1] != padrao[j-1]) {
            if (shift[j] == 0)
                shift[j] = j-i;
            j = bpos[j];
        }
        i = i-1;
        j = j-1;
        bpos[i] = j;
    }
}

void Preprocessa_Caso2(vector<int> &shift, vector<int> &bpos, string padrao, int m) {
    int j = bpos[0];

    for (int i=0; i<m; i++) {
        if (shift[i] == 0) {
            shift[i] = j;
        }

        if (i==j)
            j = bpos[j];
    }
}

const int NUM_CARACTERES = 256;
vector<int> Funcao_Badchar_Heuristic(string padrao, int m) {
    vector<int> mauCaractere(NUM_CARACTERES, -1);
    
    for (int i=0; i<m-1; i++) {
        mauCaractere[(int)(padrao[i])] = i;
    }
    return mauCaractere;
}

void BM(string texto, string padrao) {
    int s = 0;
    int m = padrao.length();
    int n = texto.length();
    vector<int> bpos(m+1, 0);
    vector<int> shift(m+1, 0);

    Preprocessa_Sufixo_Forte(shift, bpos, padrao, m);
    Preprocessa_Caso2(shift, bpos, padrao, m);

    vector<int> badChar = Funcao_Badchar_Heuristic(padrao, m);

    while (s<=(n-m)) {
        int j = m-1;

        while (j>=0 && padrao[j] == texto[s+j]) {
            j = j-1;
        }
        if (j<0) {
            cout << "Padrão ocorre no índice " << s << endl;
            s = s+shift[0];
        }
        else {
            s = s + max(shift[j+1], j - badChar[(int)(texto[s+j])]);
        }
    }
}

int main() {
    BM("muinto facil", "facil");
    return 0;
}
