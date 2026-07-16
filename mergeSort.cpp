#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int l, int mid, int r){

    vector<int> temp;

    int i = l;
    int j = mid + 1;

    while(i <= mid && j <= r) {
        if(v[i] < v[j]) temp.push_back(v[i++]);
        else temp.push_back(v[j++]);
    }
    while(i <= mid) temp.push_back(v[i++]);
    while(j <= r) temp.push_back(v[j++]);

    for(int i = l; i <= r; i++){
        v[i] = temp[i - l];
    }
}

void mergeSort(vector<int> &v, int l, int r){
    if(l < r){
        int mid = l + (r - l) / 2;
        mergeSort(v, l, mid);
        mergeSort(v, mid + 1, r);
        merge(v, l, mid, r);
    }
}

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int &i: v) cin>>i;

    mergeSort(v, 0, n - 1);

    for(auto i: v) cout<<i<<" ";
    

    return 0;
}