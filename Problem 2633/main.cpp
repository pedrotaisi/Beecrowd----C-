#include <bits/stdc++.h>
using namespace std;

int main() {

    string met;
    int date, number;

    while(cin >> number){
        map<int, string> aux;
        int flag = 0;

        for (int i = 0; i < number; ++i) {
            cin >> met >> date;
            aux.emplace(date, met);
        }

        for(const auto& x : aux){

            flag++;

            if(flag == number){
                cout << x.second;
            }else{
                cout << x.second << " ";
            }

        }

        cout << endl;
    }
    return 0;
}
