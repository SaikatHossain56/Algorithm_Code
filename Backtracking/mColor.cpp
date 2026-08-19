/*
You have an undirected graph, you have to color the vertices with atmost k color 
such that no two adjecent vertices have the same color.
Return "YES" followed by the colorOf vertices if it is possible
return "No" otherwise
*/
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector< vector<int> > adj;
vector<int> colorOf;

bool backtrack(int u){
    if(u == n + 1){
        return true;
    }
    for(int c = 1;  c <= k; c++){
        bool flag = true;
        // checks for both isolated, connected vertices
        for(int v: adj[u]){
            if(colorOf[v] == c){
                flag = false;
                break;
            }
        }    
        if(flag){

        colorOf[u] = c;
        if(backtrack(u + 1)) return true;

        colorOf[u] = 0;
        }
        
    
    }
    return false;
}


int main(){
    int m;
    cin>>n>>m>>k;

    adj.resize(n + 1);
    colorOf.assign(n + 1, 0);

    for(int i = 1; i <= m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(backtrack(1)){
        cout<<"YES"<<endl;
        for(int i = 1; i <= n; i++){
            cout<<colorOf[i]<<" \n"[i == n];
        }
    }
    else 
        cout<<"NO"<<endl;


    return 0;
}