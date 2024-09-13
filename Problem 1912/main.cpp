#include <bits/stdc++.h>

using namespace std;

int verification(vector<double> &H, double number) {
    double sum = accumulate(H.begin(), H.end(), 0.0);
    if (sum == number)
        return 0;
    else if (number > sum)
        return -1;
    else
        return 1;
}

double check(vector<double> &H, double number) {
    double result = 0;
    for (double i : H) {
        if (i > number)
            result += (i - number);
    }
    return result;
}

double ideal_cut(vector<double> &H, double number) {
    int verify = verification(H, number);

    if (verify == 0) return 0;
    if (verify == -1) return -1;

    double limit_max = *max_element(H.begin(), H.end());
    double limit_min = 0.0;
    double epsilon = 1e-7;

    while (limit_max - limit_min > epsilon) {
        double middle = (limit_max + limit_min) / 2;
        double count = check(H, middle);

        if (abs(count - number) < epsilon) {
            return middle;
        } else if (count > number) {
            limit_min = middle;
        } else {
            limit_max = middle;
        }
    }
    return limit_min;
}

int main() {
    int N;
    double A;

    while (cin >> N >> A, N != 0 && A != 0) {
        vector<double> vect(N);

        for (int i = 0; i < N; ++i) {
            cin >> vect[i];
        }

        double result = ideal_cut(vect, A);

        if (result == 0)
            cout << ":D" << endl;
        else if (result == -1)
            cout << "-.-" << endl;
        else {
            cout << fixed << setprecision(4);
            cout << result << endl;
        }
    }

    return 0;
}
