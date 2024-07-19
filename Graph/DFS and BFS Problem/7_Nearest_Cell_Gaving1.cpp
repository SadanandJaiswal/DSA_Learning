#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> nearestCellWith1(vector<vector<int>> adj){
    int n = adj.size();
    int m = adj[0].size();
    vector<vector<int>> ans(n, vector<int>(m, -1));
    vector<vector<int>> vis = adj;

    queue<pair<pair<int,int>,int>> q;

    // put all the elm with 1 into the q
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(adj[i][j] == 1){
                vis[i][j]=1;
                q.push({{i,j},0});
            }
        }
    }

    vector<int> drow = {-1,0,0,1};
    vector<int> dcol = {0,-1,1,0};

    // This while loop will run for n*m times
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        ans[row][col] = dist;

        q.pop();

        // this loop will run for 4 time
        for(int i=0; i<4; i++){ 
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                if(adj[nrow][ncol] == 0 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},dist+1});
                }
            }
        }
    }

    return ans;
}
// Time complexity: O(N*M*4)
// Space Complexity: O(N*M);

int main(){
    return 0;
}