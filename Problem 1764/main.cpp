#include <bits/stdc++.h>

#define INF 0x3f3f3f
#define MAX 1005

using namespace std;

int dijkstra(vector<vector<pair<int, int >> >& graph, int node){

    priority_queue<pair<int, int> > Q; //peso, vertice
    int result = 0;
    vector<int> dist(INF,MAX);
    dist[node] = 0;
    Q.push(make_pair(dist[node], node));

    while(!Q.empty()){

        int v = Q.top().second;//vertice
        int c = Q.top().first;//custo
        Q.pop();

        if(c != dist[v])
            continue;

        for(auto corrent : graph[v]){

            int neighbor = corrent.first;
            int cost = corrent.second;

            if(dist[neighbor] > dist[v] + cost){
                dist[neighbor] = dist[v] + cost;
                result += cost;
                cout << result << " ";
                Q.push(make_pair(-dist[neighbor], neighbor));
            }

        }
    }
    return result;
}



int main() {

    int node, edge;
    cin >> node >> edge;

    vector<vector<pair<int, int> >> graph(node);

    for (int i = 0; i < edge; ++i) {
        int a,b,cost;
        cin >> a >> b >> cost;

        graph[a].emplace_back(b,cost);
        graph[b].emplace_back(a,cost);
    }

    cout << dijkstra(graph, 1);

    
    return 0;
}
