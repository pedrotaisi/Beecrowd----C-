#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    int n;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;

        int size_a = a.size();
        int size_b = b.size();

        // Verificar se b é menor ou igual a a
        if (size_b > size_a) {
            cout << "nao encaixa" << endl;
        } else {
            // Verificar se os últimos caracteres de b se encaixam em a
            bool encaixa = true;
            for (int j = 0; j < size_b; ++j) {
                if (a[size_a - size_b + j] != b[j]) {
                    encaixa = false;
                    break;
                }
            }
            if (encaixa) {
                cout << "encaixa" << endl;
            } else {
                cout << "nao encaixa" << endl;
            }
        }
    }

    return 0;
}
