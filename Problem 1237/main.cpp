#include <bits/stdc++.h>

using namespace std;

// Função para remover espaços em branco de uma string
void remove_space(string& str) {
    auto new_end = remove_if(str.begin(), str.end(), [](char c) {
        return isspace(static_cast<unsigned char>(c));
    });
    str.erase(new_end, str.end());
}

// Função para converter uma string para letras minúsculas
void to_lowercase(string& input) {
    transform(input.begin(), input.end(), input.begin(), [](unsigned char c) {
        return tolower(c);
    });
}

// Função para encontrar o c std::cout << "Hello, World!" << std::endl;omprimento da maior subsequência comum contínua
int max_substring(const string& X, const string& Y) {
    int m = X.size();
    int n = Y.size();

    // Criação da tabela dp com (m+1) x (n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int max_length = 0;

    // Preenchendo a tabela dp
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                max_length = max(max_length, dp[i][j]);
            } else {
                dp[i][j] = 0; // Resetar a contagem para subsequência contínua
            }
        }
    }

    // O valor max_length contém o tamanho da maior subsequência comum contínua
    return max_length;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string X, Y;

    getline(cin, X);
    getline(cin, Y);

    remove_space(X);
    remove_space(Y);

    to_lowercase(X);
    to_lowercase(Y);

    cout << max_substring(X, Y) << endl;

    return 0;
}
