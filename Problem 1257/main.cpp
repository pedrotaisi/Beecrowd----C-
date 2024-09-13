#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int line, n;
    string input;

    cin >> n;

    for (int k = 0; k < n; ++k) {
        int soma = 0;
        int element = 0;

        cin >> line;

        for (int i = 0; i < line; ++i) {
            cin >> input;

            for (int j = 0; j < input.size(); ++j) {
                // cout << int(input[j] - 'A') << " " << element << " " << j << endl;
                soma += (int(input[j] - 'A') + element + j);
            }
            element++;
        }

        cout << soma << endl;
    }
    
    return 0;
}
