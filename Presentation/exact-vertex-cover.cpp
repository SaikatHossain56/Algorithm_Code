#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin>>n >>m;

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> best;
    int minSize = n + 1;

    for(int mask = 0; mask < (1 << n); mask++){
        vector<int> S;
        vector<bool> selected(n + 1, false);

        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                S.push_back(i + 1);
                selected[i + 1] = true;
            }
        }

        if (S.size() >= minSize)
            continue;

        bool covered = true;

        for(int u = 1; u <= n && covered; u++){
            for(int v : adj[u]) {
                if(!selected[u] && !selected[v]){
                    covered = false;
                    break;
                }
            }
        }

        if(covered){
            best = S;
            minSize = S.size();
        }
    }

    cout<<"Minimum Vertex Cover: ";
    for(int v : best)
        cout<<v<< " ";

    cout<<endl<<"Size: " <<best.size()<<endl;

    return 0;
}