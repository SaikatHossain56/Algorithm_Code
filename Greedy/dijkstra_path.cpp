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
    int s, dest; cin>>s>>dest;

    vector<long long> dist(n + 1, INF);
    vector<int> par(n + 1, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // dist, node

    dist[s] = 0;
    pq.push({dist[s], s});

    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d != dist[u]) continue;

        for(auto [v, w]: adj[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                par[v] = u;
                pq.push({dist[v], v});
            }
        }

    }

    if(par[dest] == -1) {
        cout<<"No path"<<endl;
        return 0;
    }

    vector<int> path;
    for(int i = dest; i != -1; i = par[i])  path.push_back(i);

    reverse(path.begin(), path.end());
    for(auto i: path) cout<<i<<" ";

    return 0;
}