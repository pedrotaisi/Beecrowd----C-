#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n_palavras, n_linhas, n_caracteres;

    while (cin >> n_palavras >> n_linhas >> n_caracteres) {
        cin.ignore(); // Ignora a nova linha após os três inteiros

        vector<int> t(n_palavras);
        string palavra;
        for (int i = 0; i < n_palavras; ++i) {
            cin >> palavra;
            t[i] = palavra.size();
        }

        int aux = 0;
        int linhas = 0;
        int paginas = 1;

        for (int i = 0; i < n_palavras; ++i) {
            if (aux + t[i] > n_caracteres) {
                linhas++;
                aux = 0;
            }

            if (linhas >= n_linhas) {
                paginas++;
                linhas = 0;
            }

            aux += t[i] + 1; // Inclui o espaço após a palavra
            if (aux > n_caracteres) {
                aux = t[i] + 1;
                linhas++;
                if (linhas >= n_linhas) {
                    paginas++;
                    linhas = 0;
                }
            }
        }

        if (aux > 0) linhas++;
        if (linhas > n_linhas) {
            paginas++;
        }

        cout << paginas << endl;
    }

    return 0;
}
