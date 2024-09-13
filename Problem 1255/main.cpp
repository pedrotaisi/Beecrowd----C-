#include <bits/stdc++.h>

using namespace std;

void to_lowercase(string& input) {
    transform(input.begin(), input.end(), input.begin(), [](unsigned char c) {
        return tolower(c);
    });
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    int n;

    cin >> n;
    cin.ignore();

    for (int j = 0; j < n; ++j) {

        vector<int> verify(26,0);
        vector<int> copy_verify(26);
        set<char> result;

        getline(cin, input);
        to_lowercase(input);

        for(char aux : input){

            if(aux >= 97 and aux <= 122){
                verify[aux - 'a']++;
            }
        }

        copy_verify = verify;

        sort(verify.begin(), verify.end());
        int bigger = verify[25];

        for (int i = 0; i < copy_verify.size(); ++i) {
            if(copy_verify[i] == bigger){
                result.insert(char('a' + i));
            }
        }

        for(char resp : result){
            cout << resp;
        }

        cout << endl;
    }
    return 0;
}
