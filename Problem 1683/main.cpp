#include <bits/stdc++.h>

using namespace std;

long long MaxArea(vector<int>& high){

    stack<int> S;
    int n = int(high.size());
    long long result = 0;


    for (int i = 0; i < n; ++i) {

        while(!S.empty() and high[S.top()] > high[i]){

            int h = high[S.top()];
            S.pop();

            int width;

            if(S.empty())
                width = i;
            else
                width = i - S.top() - 1;

            result = max(result, (long long)h * width);

        }
        S.push(i);
    }

    while(!S.empty()){

        int h = high[S.top()];
        S.pop();

        int width;

        if(S.empty())
            width = n;
        else
            width = n - S.top() - 1;

        result = max(result, (long long)h * width);
    }

    return result;
}

int main() {

    int number, aux;

    cin >> number;

    while(number != 0){

        vector<int> high;

        for (int i = 0; i < number; ++i) {
            cin >> aux;
            high.emplace_back(aux);
        }

        cout << MaxArea(high) << endl;

        cin >> number;
    }

    return 0;
}
