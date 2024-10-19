#include <bits/stdc++.h>
using namespace std;

int recursion(int row, int col, vector<vector<int>> &grid){
    if(row==0 && col==0){
        if(grid[row][col]==1){
            return 0;
        }
        return 1;
    }

    if(row<0 || col<0) return 0;
    if(grid[row][col]==1) return 0;

    int l = recursion(row-1, col, grid);
    int u = recursion(row, col-1, grid);

    return l+u;
}
// Time Complexity: O(2^(n*m))
// Space Complexity: O(n+m)

int memomization(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &grid){
    if(row==0 && col==0){
        if(grid[row][col]==1){
            return 0;
        }
        return 1;
    }

    if(row<0 || col<0) return 0;
    if(grid[row][col]==1) return 0;

    if(dp[row][col]!=-1) return dp[row][col];

    int l = memomization(row-1, col, dp, grid);
    int u = memomization(row, col-1, dp, grid);

    return dp[row][col] = l+u;
}
// Time Complexity: O(n*m)
// Space Complexity: O(n+m) + O(n*m)

int tabulation(int n, int m, vector<vector<int>> &dp, vector<vector<int>> &grid){
    if(grid[0][0]==1){
        dp[0][0] = 0;
    }else{
        dp[0][0] = 1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) continue;
            if(grid[i][j]==1){
                dp[i][j] = 0;
                continue;
            }

            int l = 0, u = 0;
            if(i-1>=0) l = dp[i-1][j];
            if(j-1>=0) u = dp[i][j-1];

            dp[i][j] = l + u;
        }
    }

    return dp[n-1][m-1];
}
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

int spaceOptimization(int n, int m, vector<vector<int>> &grid){
    vector<int> prev(m, 0), curr(m,0);
    curr[0] = 1;
    if(grid[0][0]==1){
        curr[0] = 0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) continue;

            if(grid[i][j]==1){
                curr[j] = 0;
                continue;
            }

            int l =0, u=0;
            if(j-1>=0) l = curr[j-1];
            u = prev[j];

            curr[j] = l+u;
        }
        prev = curr;
    }

    return prev[m-1];
}
// Time Complexity: O(n*m)
// Space Complexity: O(2*m)

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    // return recursion(n-1,m-1,obstacleGrid);
    // return memomization(n-1,m-1,dp,obstacleGrid);
    // return tabulation(n,m,dp,obstacleGrid);
    return spaceOptimization(n,m,obstacleGrid);
}

int main() {
    return 0;
}