/*
You are given N. you have to place N queens in a N*N grid, such that no queen attack each other.
Return the list of columns associated with rows at indices.
*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> board; // col choosen for i'th row
vector<bool> col, d1, d2;
vector<vector<int>> sol;

void backtrack(int row){
    // 
    if(row == n + 1) {
        sol.push_back(board);
        return;
    }

    for(int c = 1; c <= n; c++){
        int i = row - c + n; // 1 to 2n - 1
        int j = row + c; // 2 to 2n

        if(col[c] || d1[i] || d2[j]) continue;

        board[row] = c;
        col[c] = d1[i] = d2[j] = true;
        backtrack(row + 1);

        //undo
        col[c] = d1[i] = d2[j] = false;
    }

}

int main(){
    cin>>n;

    board.assign(n + 1, 0);
    col.assign(n + 1, false);
    d1.assign(2*n + 1, false);
    d2.assign(2*n + 1, false);

    backtrack(1);
   int i = 0;
   // print all possible solutions
   while( i < sol.size()){
        for(int j = 1; j <= n; j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
        i++;
    }

     
    return 0;
}