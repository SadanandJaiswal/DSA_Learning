#include<bits/stdc++.h>
using namespace std;

vector<int> drow = {-1,0,0,1};
vector<int> dcol = {0,-1,1,0};

// if the two island are in identical shape at its original structure without any rotation then both island will be treated as a single island
void dfs(int row, int col, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int,int>> &vec, int rowB, int colB){
    vis[row][col] = 1;
    vec.push_back({row - rowB, col-colB});

    for(int i=0; i<4; i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
            if(grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                dfs(nrow, ncol, n, m, grid, vis, vec, rowB, colB);
            }
        }
    }
}
int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m,0));

    set<vector<pair<int,int>>> st;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1 && !vis[i][j]){
                vector<pair<int,int>> vec;
                dfs(i, j, n, m, grid, vis, vec, i, j);
                st.insert(vec);
            }   
        }
    }

    return st.size();
}
// Time complexity: O(N*M*log(N*M)) + O(N*M*4)  // set: log(n*m)
// Space Complexity: O(N*M) 

int main()
{
    
    return 0;
}