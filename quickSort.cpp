#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int l, int r){

    int pivot_index = l + rand() % (r - l + 1);
    swap(v[r], v[pivot_index]);

    int pivot = v[r];
    // j -> upper bound of elements <= pivot.
    int j = l - 1;
    for(int i = l; i < r; i++){
        if(v[i] <= pivot) swap(v[i], v[++j]);
    }
    swap(v[j + 1], v[r]);
    return j + 1;
}

void quickSort(vector<int>&v, int l, int r){
    if(l < r){
        int pivot_index  = partition(v, l, r);
        quickSort(v, l, pivot_index - 1);
        quickSort(v, pivot_index + 1, r);
    }
}
int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int &i: v) cin>>i;
    quickSort(v, 0, n - 1);
    for(int i: v) cout<<i<<" ";
    return 0;
}