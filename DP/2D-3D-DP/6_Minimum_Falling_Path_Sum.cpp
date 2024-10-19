#include <bits/stdc++.h>
using namespace std;

int recursion(int row, int col, int n, vector<vector<int>> &matrix){
    if(col>=n || col<0) return INT_MAX;
    if(row==0) return matrix[row][col];

    int s = recursion(row-1, col, n, matrix);
    int ld = recursion(row-1, col-1, n, matrix);
    int rd = recursion(row-1, col+1, n, matrix);

    return min(s, min(ld, rd)) + matrix[row][col];
}
// Time Complexity: O(N^3)
// Space Complexity: O(N)

int memomization(int row, int col, int n, vector<vector<int>> &dp, vector<vector<int>> &matrix){
    if(col>=n || col<0) return INT_MAX;
    if(row==0) return matrix[row][col];

    if(dp[row][col]!=-1) return dp[row][col];

    int s = memomization(row-1, col, n, dp, matrix);
    int ld = memomization(row-1, col-1, n, dp, matrix);
    int rd = memomization(row-1, col+1, n, dp, matrix);

    return dp[row][col] = min(s, min(ld, rd)) + matrix[row][col];
}
// Time Complexity: O(N*N)
// Space Complexity: O(N*N) + O(N)

int tabulation(vector<vector<int>> &dp, vector<vector<int>> &matrix){
    int n = matrix.size();
    for(int i=0; i<n; i++){
        dp[0][i] = matrix[0][i];
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            int s = INT_MAX, ld=INT_MAX, rd=INT_MAX;
            if(i-1>=0){
                s = dp[i-1][j] + matrix[i][j];
                if(j-1>=0){
                    ld = dp[i-1][j-1] + matrix[i][j];
                }
                if(j+1<n){
                    rd = dp[i-1][j+1] + matrix[i][j];
                }
            }

            dp[i][j] = min(s, min(ld, rd));
        }
    }

    int minPathSum = INT_MAX;
    for(int j = 0; j < n; j++) {
        minPathSum = min(minPathSum, dp[n-1][j]);
    }

    return minPathSum;
}
// Time Complexity: O(N*N)
// Space Complexity: O(N*N) + O(N)

int spaceOptimization(vector<vector<int>> &matrix){
    int n = matrix.size();
    
    vector<int> prev(n, INT_MAX), curr(n, 0);
    for(int i=0; i<n; i++){
        prev[i] = matrix[0][i];
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            int s = INT_MAX, ld=INT_MAX, rd=INT_MAX;
            if(i-1>=0){
                s = prev[j] + matrix[i][j];
                if(j-1>=0){
                    ld = prev[j-1] + matrix[i][j];
                }
                if(j+1<n){
                    rd = prev[j+1] + matrix[i][j];
                }
            }

            curr[j] = min(s, min(ld, rd));
        }
        prev = curr;
    }

    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        ans = min(ans, prev[i]);
    }

    return ans;
}
// Time Complexity: O(N*N)
// Space Complexity: O(N)

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int ans = INT_MAX;

    vector<vector<int>> dp(n, vector<int>(n, -1));

    for(int i=0; i<n; i++){
        // Recursion
        int temp = recursion(n-1, i, n, matrix);
        
        // Memomization
        temp = memomization(n-1, i, n, dp, matrix);
        ans = min(ans, temp);
    }

    // Tabulation
    ans = tabulation(dp, matrix);

    // Space Optimization
    ans = spaceOptimization( matrix);


    return ans;
}


int main() {
    return 0;
}