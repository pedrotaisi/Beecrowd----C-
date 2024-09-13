#include <bits/stdc++.h>

using namespace std;

int main() {

    int grid[3][3];

    for (int i = 0; i <2 ; ++i) {
        for (int j = 0; j < 2; ++j) {

            cin >> grid[i][j];

        }

    }

    int grid2[3][3] = grid*grid;

    return 0;
}
