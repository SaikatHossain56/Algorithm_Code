//Job Sequencing Problem
// Naive: O(n ^ 2)
#include <bits/stdc++.h>
using namespace std;

struct Job{
    int deadline;
    int profit;
};

int main(){
    int n; cin>>n;
    vector<Job> jobs(n);
    for(int i = 0; i < n; i++){
        cin>>jobs[i].profit;
    }
      for(int i = 0; i < n; i++){
        cin>>jobs[i].deadline;
    }

    sort(jobs.begin(), jobs.end(), [] (Job &a, Job &b){
        return a.profit > b.profit;
    });

    vector<int> slots(n, 0);
    int cnt = 0;
    int total_profit = 0;
    for(int i = 0; i < n; i++){
        int start = min(n, jobs[i].deadline) - 1;
        for(int j = start; j >= 0; j--){
            if(!slots[j]) {
                cnt ++;
                total_profit += jobs[i].profit;
                slots[j] = 1;
                break;
            }
        }
    }

    cout<<cnt<<" " <<total_profit<<endl;
    
    return 0;
}