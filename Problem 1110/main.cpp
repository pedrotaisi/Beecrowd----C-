#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int number;
    cin >> number;

    while(number != 0){

        vector<int> trash;
        queue<int> Q;


        for (int i = 1; i < number + 1; i++) {
            Q.push(i);
        }

        cout << "Discarded cards: ";

        while (Q.size() > 1) {
            trash.emplace_back(Q.front());
            Q.pop();
            Q.push(Q.front());
            Q.pop();
        }

        for (int i = 0; i < trash.size(); ++i) {

            if(i != int(trash.size()) - 1){
                cout << trash[i] << ", ";
            }else
                cout << trash[i];

        }

        cout << endl;

        cout << "Remaining card: " << Q.front() << endl;

        cin >> number;
    }



    return 0;
}
