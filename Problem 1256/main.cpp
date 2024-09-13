#include <bits/stdc++.h>
using namespace std;

int main() {
    int number, n_cases, input;
    int cases;
    bool flag = false;
    cin >> cases;

    for (int y = 0; y < cases; ++y) {
        cin >> number >> n_cases;
        vector<queue<int>> vect(number); // ajustar o tamanho do vetor

        if(y == cases - 1)
            flag = true;

        for (int i = 0; i < n_cases; ++i) {
            cin >> input;
            vect[input % number].emplace(input);
        }

        for (int i = 0; i < vect.size(); ++i) {
            cout << i << " -> ";
            while (!vect[i].empty()) {
                cout << vect[i].front() << " -> ";
                vect[i].pop();
            }
            cout << "\\" << endl;
        }

        if(!flag)
            cout << endl;
    }

    return 0;
}
