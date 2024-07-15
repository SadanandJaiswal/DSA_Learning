#include<bits/stdc++.h>
using namespace std;

// No of connected components: no of island
// we will use bfs if vis[row][col]==false and count++
void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> grid){
    queue<pair<int, int>> q;
    q.push({row,col});
    vis[row][col]=1;

    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty()){
        row = q.front().first;
        col = q.front().second;
        q.pop();

        // explore all 8 neighbors
        for(int drow= 0; drow<=1; drow++){
            for(int dcol=0; dcol<=1; dcol++){
                if(abs(drow)==abs(dcol)) continue;  // this is for if no diagonal are considered
                int nrow = row + drow;
                int ncol = col + dcol;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                    q.push({nrow, ncol});
                    vis[nrow][ncol]=1;  // mark as visited in next step of bfs, to avoid revisiting same node again in next iteration.
                }
            }
        }
    }
}
int numOfIsland(vector<vector<char>> grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int numOfIsland=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]=='1' && !vis[i][j]){
                bfs(i,j,vis,grid);
                numOfIsland++;
            }
        }
    }

    return numOfIsland;
}
// Time Complexity: O(
// Space Complexity: O( )


int main(){
    int n,m;
    cin>>n>>m;

    // 2) adjacency list
    // use array of size n with empty list
    vector<int> alist[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        // u--->v
        alist[u].push_back(v);
        // alist[v].push_back(1);
    }
    // space complexity: O(E)   // only adjacent will be inserted

}