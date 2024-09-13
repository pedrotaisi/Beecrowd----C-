#include <bits/stdc++.h>

using namespace std;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(0);

    int a, b;
    cin >> a >> b;

    while(a != 0 and b != 0){

        vector<int> N(10,0);
        string numbers;

        for (int i = a; i <= b; ++i) {

            numbers = to_string(i);

            for(char c : numbers){
                N[c - '0']++;
            }
        }

        for (int i = 0; i < 10; ++i) {
            cout << N[i] << " ";
        }

        cin >> a >> b;
    }

    return 0;
}
