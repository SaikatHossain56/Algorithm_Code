//There will be n items.
//weight[n]
//value[n]
//capacity
// The task is to fill the knapsack such that the total value become max
#include <bits/stdc++.h>
using namespace std;

// a: first, b: second
// first ratio > second ratio and so on
// Descending sorting 
bool comparator(pair<int, int> a, pair<int, int> b){
    return (1.0 * a.first / a.second) > (1.0 * b.first / b.second);
}

int main(){
    int n; cin>>n;
    // {val, weight}
    vector<pair<int, int>> items(n + 1);

    for(int i = 1; i <= n; i++){
        cin>>items[i].first;
    }
    for(int i = 1; i <= n; i++){
        cin>>items[i].second;
    }

    int capacity; cin>>capacity;
    // //Descending sort via val/ weight ratio
    // sort(items.begin() + 1, items.end(), comparator);

    sort(items.begin() + 1, items.end(), [] (const auto &a, const auto &b){
        return (1.0 * a.first / a.second) > (1.0 * b.first / b.second);
    });

    double total_profit = 0;
    for(int i = 1; i <= n; i++){
         if(items[i].second <= capacity) {
            total_profit += items[i]. first;
            capacity -= items[i].second;
         }
         else if(items[i].second > capacity){
            total_profit += (1.0 * items[i].first/ items[i].second) * capacity;
            break;
         }
    }

    cout<<total_profit<<endl;

    return 0;

}