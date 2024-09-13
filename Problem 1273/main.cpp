#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string input;
    bool first_case = true;

    while(cin >> n and n != 0){

        if (!first_case) {
            cout << endl; // Adiciona uma nova linha antes de cada caso, exceto o primeiro
        }
        first_case = false;

        int max_lenth = 0;
        queue<string> Q;

        for (int i = 0; i < n; ++i) {

            cin >> input;

            if(input.size() > max_lenth)
                max_lenth = input.size();

            Q.push(input);
        }

        while(!Q.empty()){
            string aux  = Q.front();
            Q.pop();

            if(aux.size() < max_lenth){

                for (int i = 0; i < max_lenth - aux.size(); ++i) {
                    cout << " ";
                }

                for (char i : aux) {
                    cout << i;
                }

            }else{
                for(char c : aux){
                    cout << c;
                }
            }
            cout << endl;
        }

        cout << endl;

    }

    return 0;
}
