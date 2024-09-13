#include <bits/stdc++.h>

using namespace std;

int main() {

    string input;

    while(getline(cin, input)){

        bool find_ = false;
        bool as = false;

        for (int i = 0; i < input.size(); ++i) {
            if(input[i] == '_'){

                if(!find_){
                    cout << "<i>";
                    find_ = true;
                }else{
                    cout << "</i>";
                    find_ = false;
                }

            }else if(input[i] == '*'){

                if(!as){
                    cout << "<b>";
                    as = true;
                }else{
                    cout << "</b>";
                    as = false;
                }

            }else
                cout << input[i];
        }
        cout << endl;
    }

    return 0;
}
