// O(n * log n)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<pair<int, int>> jobs(n);
    //profits
    for(int i = 0; i < n; i++){
        cin>>jobs[i].first;
    }
    //deadlines
    for(int i = 0; i < n; i++){
        cin>>jobs[i].second;
    }

    sort(jobs.begin(), jobs.end(), [](const auto &a, const auto &b){
        return a.second < b.second;
    });

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++){
        if(jobs[i].second > pq.size()) pq.push(jobs[i].first);
        else if(!pq.empty() && pq.top() < jobs[i].first) {
            pq.pop();
            pq.push(jobs[i].first);
        }
    }

    int cnt = 0, total_profit = 0;

    while(!pq.empty()){
        cnt++;
        total_profit += pq.top();
         pq.pop();
    }
    cout<<cnt<<" "<<total_profit<<endl;
    return 0;
}