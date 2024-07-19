#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int drow[] = {-1, 0, 1, 0};
int dcol[] = {0, 1, 0, -1};

// We can use both bfs and dfs to solve this
void dfs(int row, int col, int n, int m, vector<vector<char>> &mat, vector<vector<int>> &vis){
    vis[row][col] =1;
    
    for(int i=0; i<4; i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
            if(mat[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                dfs(nrow, ncol, n, m, mat, vis);
            }
        }
    }
}
vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j]=='O' && vis[i][j]==0) {
                if(i==0 || i==n-1 || j==0 || j==m-1) {
                    dfs(i,j,n,m,mat,vis);
                }
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j =0; j<m; j++){
            if(!vis[i][j]){
                mat[i][j] = 'X';
            }
        }
    }
    
    return mat;
}
// Time Complexity: O(N*M*4 + N*M) == O(N*M)
// Space Complexity: O(N*M + N*M)   // N*M for recursive stack in worst case and another is for vis

int main(){
    return 0;
}