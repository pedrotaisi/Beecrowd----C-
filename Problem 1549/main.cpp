#include <bits/stdc++.h>
using namespace std;

double V_max(double h, int n, double R, double r){
    double V = (1.0 / 3) * M_PI * h * (pow(R, 2) + pow(r, 2) + R * r);
    return V * n;
}

double solve(int r, int R, int h, int n, int L_max){
    double limit_min = 0.0;
    double limit_max = h;
    double middle;

    double epsilon = 1e-7;

    while(limit_max - limit_min > epsilon){

        middle = (limit_max + limit_min)/2;

        double new_R = r + (double(R - r) / h) * middle;
        double count = V_max(middle, n, new_R, r);

        if(count > L_max){
            limit_max = middle;
        }else if (count < L_max){
            limit_min = middle;
        }

    }

    return middle;
}

int main() {

    int number;
    int N,L;
    int r,R,H;

    cin >> number;

    for (int i = 0; i < number; ++i) {
        cin >> N >> L;
        cin >> r >> R >> H;

        cout << fixed << setprecision(2);
        cout << solve(r,R,H,N,L) << endl;
    }

    return 0;
}
