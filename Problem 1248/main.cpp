#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string alimentos, cafe, almoco;
    int N;

    cin >> N;
    cin.ignore(); // Limpar o caractere de nova linha após ler N

    for (int j = 0; j < N; ++j) {
        vector<int> verify(26, -1); // Corrigido para 26 letras do alfabeto
        bool trapaca = false;
        set<char> result;

        getline(cin, alimentos);
        getline(cin, cafe);
        getline(cin, almoco);

        string aux = cafe + almoco;

        for (char alimento : alimentos) {
            verify[alimento - 'A'] = 0; // Inicializar a dieta
        }

        for (char auxs : aux) {
            if (auxs >= 'A' && auxs <= 'Z') { // Considerar apenas letras maiúsculas
                if (verify[auxs - 'A'] == -1) {
                    trapaca = true; // Comendo algo que não está na dieta
                } else if (verify[auxs - 'A'] == 0) {
                    verify[auxs - 'A']++; // Marcando que foi comido
                }
            }
        }

        if (trapaca) {
            cout << "CHEATER" << endl;
        } else {
            for (int i = 0; i < verify.size(); ++i) {
                if (verify[i] == 0) {
                    result.insert(char('A' + i));
                }
            }

            if (result.empty()) {
                cout << endl;
            } else {
                for (char resp : result) {
                    cout << resp;
                }
                cout << endl;
            }
        }
    }

    return 0;
}
