#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    cin.ignore();

    for (int i = 0; i < N; ++i) {

        bool flag = true;
        string input;
        vector<char> result;

        getline(cin,input);


        for(char c : input){

            if(c == ' ')
                flag = true;
            else if(flag){
                result.emplace_back(c);
                flag = false;
            }
        }

        for(char c : result)
            cout << c;

        cout << endl;
    }

    return 0;
}
