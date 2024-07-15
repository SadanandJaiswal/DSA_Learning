#include <bits/stdc++.h>
using namespace std;

// All the neighbour oranges will become rotten if curr is rooten except the diagonal one
// We will use BFS as we want to find the minimum number of time to rotten all, in bfs we will take all the same order simultaneously
int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
        int m = grid[0].size();

    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> vis = grid;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
            }
        }
    }

    vector<int> drow = {-1,0,0,1};
    vector<int> dcol = {0,-1,1,0};

    int ans =0;

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                if(vis[nrow][ncol]==1)
                {
                    vis[nrow][ncol]==2;
                    q.push({{nrow,ncol}, t+1});
                }
            }
        }
    }

    for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==1) return -1;
            }
        }

        return ans;
}
// Time Complexity: O(N*M): N*M for travel through all node, and 4*N*M queue will be called for N*M time and to handle all the 4 nodes extra 4 multiplication
// Space Complexity: O(N*M + N*M) // N*M for queue and N*M for Visited


int main()
{
    int n, m;
    cin >> n >> m;

    // 2) adjacency list
    // use array of size n with empty list
    vector<int> alist[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // u--->v
        alist[u].push_back(v);
        // alist[v].push_back(1);
    }
    // space complexity: O(E)   // only adjacent will be inserted
}