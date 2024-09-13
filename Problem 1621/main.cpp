#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3

// BFS para encontrar a maior distância em um grafo não ponderado
pair<int, pair<int, int>> bfs(vector<vector<char>> &grid, int startX, int startY) {
    int N = grid.size();
    int M = grid[0].size();
    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int, int>> q;

    q.push({startX, startY});
    dist[startX][startY] = 0;

    pair<int, pair<int, int>> furthest = {0, {startX, startY}};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // Verifica as quatro direções (cima, direita, baixo, esquerda)
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == '.' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
                if (dist[nx][ny] > furthest.first) {
                    furthest = {dist[nx][ny], {nx, ny}};
                }
            }
        }
    }

    return furthest;
}

int main() {
    int N, M;
    while (cin >> N >> M and N != 0 and M != 0) {
        vector<vector<char>> grid(N, vector<char>(M));

        pair<int, int> start;
        bool foundStart = false;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> grid[i][j];
                if (!foundStart && grid[i][j] == '.') {
                    start = {i, j};
                    foundStart = true;
                }
            }
        }

        auto furthest = bfs(grid, start.first, start.second);
        auto result = bfs(grid, furthest.second.first, furthest.second.second);
        cout << result.first << endl;
    }

    return 0;
}
