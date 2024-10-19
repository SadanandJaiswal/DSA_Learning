#include <bits/stdc++.h>
using namespace std;

int recursion(int row, int col){
    if(row == 0 && col==0){
        return 1;
    }

    if(row<0 || col<0){
        return 0;
    }

    int l = recursion(row-1, col);
    int u = recursion(row, col-1);

    return l + u;
}
// Time Complexity: O(2^(n*m))
// Space Complexity: O((n-1)+(m-1));

int memomization(int row, int col, vector<vector<int>> &dp){
    if(row == 0 && col==0){
        return 1;
    }

    if(row<0 || col<0){
        return 0;
    }

    if(dp[row][col]!=-1) return dp[row][col];

    int l = memomization(row-1, col, dp);
    int u = memomization(row, col-1, dp);

    return dp[row][col] = l + u;
}
// Time Complexity: O((n*m))
// Space Complexity: O(n+m) + O(n*m);

int tabulation(int n, int m, vector<vector<int>> &dp){
    dp[0][0] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) continue;

            int l = 0, u = 0;
            if(i-1>=0) l = dp[i-1][j];
            if(j-1>=0) u = dp[i][j-1];

            dp[i][j] = l + u ;
        }
    }

    return dp[n-1][m-1];
}
// Time Complexity: O((n*m))
// Space Complexity: O(n*m);

int spaceOptimization(int n, int m){
    vector<int> prev(m, 0), curr(m, 0);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0){
                curr[j] = 1;
            }else{
                int l=0, u=0;
                if(j-1>=0) l = curr[j-1];
                u = prev[j];
                curr[j] = l+u;
            }
        }
        prev = curr;
    }

    return prev[m-1];
}
// Time Complexity: O((n*m))
// Space Complexity: O(2m)

int uniquePaths(int m, int n) {
    // // Recursive Solution
    // return recursion(m-1, n-1);

    vector<vector<int>> dp(m, vector<int>(n, -1));

    // // Memomization Solution
    // return memomization(m-1, n-1, dp);
    
    // // Tabulation Solution
    // return tabulation(m, n, dp);
    
    // Space Optimization Solution
    return spaceOptimization(m, n);
}

int main() {
    return 0;
}