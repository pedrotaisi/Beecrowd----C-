#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string one, two;
    int Max, Min, N;

    cin >> N;

    for (int j = 0; j < N; ++j) {

        vector<char> result;
        bool Max_one = false;

        cin >> one >> two;

        Max = max(one.size(), two.size());
        Min = min(one.size(), two.size());

        if(Max == one.size())
            Max_one = true;

        for (int i = 0; i < Max; ++i) {

            if(i < Min){
                result.push_back(one[i]);
                result.push_back(two[i]);
            }else{
                if(Max_one)
                    result.push_back(one[i]);
                else
                    result.push_back(two[i]);
            }
        }

        for (char i : result) {
            cout << i;
        }
        cout << endl;
    }


    
    return 0;
}
