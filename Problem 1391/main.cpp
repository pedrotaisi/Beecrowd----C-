#include <bits/stdc++.h>

using namespace std;
#define INF 0x3f3f3f

int solve(vector<vector<pair<int, int>>> &graph, int node, int final) {
    vector<int> dist(int(graph.size()), INF);
    vector<int> second_dist(int(graph.size()), INF);
    priority_queue<pair<int, int>> Q;
    dist[node] = 0;
    second_dist[node] = 0;
    Q.emplace(dist[node], node);

    while (!Q.empty()) {
        int v = Q.top().second; //verice
        int c = -Q.top().first; // custo
        Q.pop();

        if (c != dist[v])
            continue;

        for (auto current: graph[v]) {
            int neighbor = current.first;
            int cost = current.second;

            if (dist[neighbor] > dist[v] + cost) {
                dist[neighbor] = dist[v] + cost;
                Q.emplace(-dist[neighbor], neighbor);
            }

            if (dist[neighbor] < dist[v] + cost && second_dist[neighbor] > dist[v] + cost) {
                second_dist[neighbor] = second_dist[v] + cost;
            }
        }
    }
    return second_dist[final];
}


int main() {

    int N,M,start,final;
    cin >> N >> M >> start >> final;

    vector<vector<pair<int, int>>> graph(N);

    for (int i = 0; i < M; ++i) {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b,c);
    }

    cout << solve(graph,start, final) << endl;

    return 0;
}
