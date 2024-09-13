#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    int number;

    while(cin >> input >> number){

        int cont = 0, result = 0;
        bool flag = false;

        for (char i : input) {

            if(i == 'W'){
                result++;
                flag = false;
            }else{

                if(flag){
                    cont++;
                }else{
                    result++;
                    cont = 0;
                }
                if(cont == number){
                    cont = 0;
                    result++;
                }
                flag = true;
            }

        }

        cout << result << endl;
    }



    return 0;
}
