#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> removed(n + 1, false);
    vector<int> C;

    for(int u = 1; u <= n; u++){
        for(int v : adj[u]){
            if(!removed[u] && !removed[v]){
                C.push_back(u);
                C.push_back(v);
                removed[u] = removed[v] = true;
            }
        }
    }

    cout<<"Vertex Cover: ";
    for(int v : C)
        cout << v << " ";

    cout<<endl<<"Size: "<<C.size()<<endl;

    return 0;
}