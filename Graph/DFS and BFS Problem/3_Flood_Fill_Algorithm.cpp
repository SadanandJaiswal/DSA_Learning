#include <bits/stdc++.h>
using namespace std;

// Flood Fill Algorithm
// starting row, col will be given and change the all the neighbour of starting with initialColor and its negihbour with initial color with newcolor
void dfs(int row, int col, int color, int initialColor, vector<vector<int>> &grid, vector<int> drow, vector<int> dcol){
    grid[row][col] = color;
    int n = grid.size();
    int m = grid[0].size();

    for(int i=0; i<4; i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == initialColor){
            dfs(nrow, ncol, color, initialColor, grid, drow, dcol);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int initialColor = image[sr][sc];
    vector<vector<int>> grid = image;
    vector<int> drow = {-1, 0, 0, 1};
    vector<int> dcol = {0, -1, 1, 0};

    if (initialColor != color)
    {
        dfs(sr, sc, color, initialColor, grid, drow, dcol);
    }

    return grid;
}
// Time Complexity: O(4*N*M): 4 times dfs for each elm in matrix in worst case
// Time complexity: O(N*M + N*M): N*M for grid and N*M for stack space in worst case 

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