#include <bits/stdc++.h>
using namespace std;

int recursion(int row, int col, vector<vector<int>> &triangle){
    int n = triangle.size();
    
    if(row==n-1){
        return triangle[row][col];
    }
    // no outside bound condition

    int down = recursion(row+1, col, triangle);
    int diag = recursion(row+1, col+1, triangle);

    return min(down, diag) + triangle[row][col];
}
// Time Complexity: O(2^(n*n))
// Space Complexity: O(n)

int memomization(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &triangle){
    int n = triangle.size();

    if(row==n-1){
        return triangle[row][col];
    }

    if(dp[row][col]!=-1) return dp[row][col];

    int down = memomization(row+1, col, dp, triangle);
    int diag = memomization(row+1, col+1, dp, triangle);

    return dp[row][col] = min(down, diag) + triangle[row][col];
}
// Time Complexity: O(n*n)
// Space Complexity: O(n*n) + O(n)

int tabulation(int n, vector<vector<int>> &dp, vector<vector<int>> &triangle){
    for(int i=0; i<n; i++){
        dp[n-1][i] = triangle[n-1][i];
    }

    for(int i= n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            int down = dp[i+1][j] + triangle[i][j];
            int diag = dp[i+1][j+1] + triangle[i][j];

            dp[i][j] = min(down, diag);
        }
    }

    return dp[0][0];
}
// Time Complexity: O(n*n)
// Space Complexity: O(n*n)

int spaceOptimization(int n, vector<vector<int>> &triangle){
    vector<int> prev(n), curr(n,0);
    for(int i=0; i<n; i++){
        prev[i] = triangle[n-1][i];
    }

    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            int down = prev[j];
            int diag = prev[j+1];

            curr[j] = min(down,diag) + triangle[i][j];
        }
        prev = curr;
    }

    return prev[0];
}
// Time Complexity: O(n*n)
// Space Complexity: O(n)

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int m = n;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // return recursion(0,0,triangle);
    // return memomization(0,0,dp,triangle);
    // return tabulation(n,dp,triangle);
    return spaceOptimization(n,triangle);
}


int main() {
    return 0;
}