#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int, long long>>> adj(n + 1);
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});// node, weight
        adj[v].push_back({u, w}); //undirected
        
    }
    int s; cin>>s;

    vector<bool> visited(n + 1, false);
    vector<long long> dist(n + 1, INF);
    //priority_queue <Type, vector<Type>, ComparisonType > min_heap;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // dist, node

    dist[s] = 0;
    pq.push({dist[s], s});

    while(!pq.empty()){
        auto [d, u] = pq.top();
        //choice
        pq.pop();
        if(visited[u]) continue; // ignores duplicates
        visited[u] = true;
        // Traverse all edges
        for(auto [v, w]: adj[u]){
            if(visited[v]) continue; // enables only forward movement
            //one node can be updated multiple times, min-heap contains all versions.
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }

    }

    for(int i = 1; i <= n; i++){
        if(dist[i] == INF) cout<<"No Path Exists!"<<endl;
        else {
            cout<<"Shortest Path from "<<s<<" to "<<i<<": "<<dist[i]<<endl;
        }
    }


    return 0;
}