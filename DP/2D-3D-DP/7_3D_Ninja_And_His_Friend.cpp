#include <bits/stdc++.h>
using namespace std;

int recursion(int row, int col1, int col2, int n, int m, vector<vector<int>> &grid){
    if(col1<0 || col1>=m || col2<0 || col2>=m){
        return -1e8;
    }
    
    if(row==n-1){
        if(col1==col2){
            return grid[row][col1];
        }
        return grid[row][col1] + grid[row][col2];
    }
    
    int maxi = 0;
    
    for(int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            if(col1==col2){
                maxi = max(maxi, grid[row][col1] + recursion(row+1, col1+i, col2+j, n, m, grid));
            }
            else{
                maxi = max(maxi, grid[row][col1] + grid[row][col2] + recursion(row+1, col1+i, col2+j, n, m, grid));
            }
        }
    }
    
    return maxi;
}
// Time Complexity: O(3^n * 3^n)
// Space Complexity: O(N) -> auxiliary recursive stack space

int memomization(int row, int col1, int col2, int n, int m, vector<vector<vector<int>>> &dp, vector<vector<int>> &grid){
    if(col1<0 || col1>=m || col2<0 || col2>=m){
        return -1e8;
    }
    
    if(row==n-1){
        if(col1==col2){
            return dp[row][col1][col2] = grid[row][col1];
        }
        return dp[row][col1][col2] = grid[row][col1] + grid[row][col2];
    }
    
    if(dp[row][col1][col2]!=-1){
        return dp[row][col1][col2];
    }
    
    int maxi = -1e8;
    
    for(int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            int val = 0;
            if(col1==col2){
                val = grid[row][col1];
            }
            else{
                val = grid[row][col1] + grid[row][col2];
            }
            val+= memomization(row+1, col1+i, col2+j, n, m, dp, grid);
            maxi = max(maxi, val);
        }
    }
    
    return dp[row][col1][col2] = maxi;
}
// Time Complexity: O(N*M*M)
// Space Complexity: O(N*M*M) + O(N)

int tabulation(int n, int m, vector<vector<vector<int>>> &dp, vector<vector<int>> &grid){
    // Base Condition
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            if(i==j){
                dp[n-1][i][j] = grid[n-1][i];
            }else{
                dp[n-1][i][j] = grid[n-1][i] + grid[n-1][j];
            }
        }
    }
    
    for(int r=n-2; r>=0; r--){
        for(int c1 = 0; c1<m; c1++){
            for(int c2 = 0; c2<m; c2++){
                int maxi = -1e8;
                
                for(int i=-1; i<2; i++){
                    for(int j=-1; j<2; j++){
                        if(c1+i>=0 && c1+i<m && c2+j>=0 && c2+j<m){
                            int val = 0;
                            if(c1==c2) val+= grid[r][c1];
                            else val+= grid[r][c1] + grid[r][c2];
                            val+= dp[r+1][c1+i][c2+j];
                            maxi = max(maxi, val);
                        }
                    }
                }
                dp[r][c1][c2] = maxi;
            }
        }
    }
    
    return dp[0][0][m-1];
}
// Time Complexity: O(N*M*M)
// Space Complexity: O(N*M*M)

int spaceOptimization(int n, int m, vector<vector<int>>& grid){
    vector<vector<int>> prev(m, vector<int>(m, 0)), curr(m, vector<int>(m));
    
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            if(i==j){
                prev[i][j] = grid[n-1][i];
            }
            else{
                prev[i][j] = grid[n-1][i] + grid[n-1][j];
            }
        }
    }
    
    for(int r=n-2; r>=0; r--){
        for(int c1=0; c1<m; c1++){
            for(int c2=0; c2<m; c2++){
                int maxi = -1e8;
                
                for(int i=-1; i<2; i++){
                    for(int j=-1; j<2; j++){
                        if(c1+i>=0 && c1+i<m && c2+j>=0 && c2+j<m){
                            int val = 0;
                            if(c1==c2) val+= grid[r][c1];
                            else val+= grid[r][c1] + grid[r][c2];
                            
                            val+= prev[c1+i][c2+j];
                            maxi = max(maxi, val);
                        }
                    }
                }
                
                curr[c1][c2] = maxi;
            }
        }
        prev = curr;
    }
    
    return prev[0][m-1];
}
// Time Complexity: O(N*M*M*9)
// Space Complexity: O(M*M)

int solve(int n, int m, vector<vector<int>>& grid) {
    // code here
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    // return recursion(0, 0, m-1, n, m, grid);
    // return memomization(0, 0, m-1, n, m, dp, grid);
    // return tabulation(n, m, dp, grid);
    return spaceOptimization(n, m, grid);
}

int main() {
    return 0;
}