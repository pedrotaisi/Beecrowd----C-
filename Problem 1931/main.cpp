#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f

int solve(vector<vector<pair<int, int>>>& graph, int node){
    int MAX = int(graph.size()) + 1;
    priority_queue<pair<int, int>> Q;
    vector<int> dist(MAX, INF);
    dist[node] = 0;

    Q.emplace(dist[node], node);

    while(!Q.empty()){

        int v = Q.top().second;
        int c = -Q.top().first;

        Q.pop();

        if(c != dist[v])
            continue;

        for(auto current : graph[v]){
            int neighbor = current.first;
            int cost = current.second;

            if(dist[neighbor] > dist[v] + cost){
                dist[neighbor] = dist[v] + cost;
                Q.emplace(-dist[neighbor], neighbor);
            }
        }
    }
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
