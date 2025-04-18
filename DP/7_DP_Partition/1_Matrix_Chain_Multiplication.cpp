#include <bits/stdc++.h>
using namespace std;

int recursion(int i, int j, int arr[]){
    if(i==j) return 0;
    
    int mini = 1e9;
    
    for(int k=i; k<j; k++){
        int steps = arr[i-1]*arr[k]*arr[j] + recursion(i, k, arr) + recursion(k+1, j, arr);
        mini = min(mini, steps);
    }
    
    return mini;
}
// Time Complexity: O(2^N)
// space Complexity: O(N)

int memoization(int i, int j, vector<vector<int>> &dp, int arr[]){
    if(i==j) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int mini = 1e9;
    
    for(int k=i; k<j; k++){
        int steps = arr[i-1]*arr[k]*arr[j] + memoization(i, k, dp, arr) + memoization(k+1, j, dp, arr);
        mini = min(mini, steps);
    }
    
    return dp[i][j] = mini;
}
// Time Complexity: O(N*N*N)
// space Complexity: O(N*N) + O(N)

int tabulation(int N, int arr[]){
    vector<vector<int>> dp(N, vector<int>(N, 0));
    
    for(int i=N-1; i>0; i--){
        // Don't start with 1 to N-1, j will always right to i, j=i+1 to N-1
        for(int j=i+1; j<N; j++){
            int mini = 1e9;
            
            for(int k=i; k<j; k++){
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, steps);
            }
            
            dp[i][j] = mini;
        }
    }
    
    return dp[1][N-1];
}

// Space Optimization is May be not possible, not sure


int matrixMultiplication(int N, int arr[])
{
    // return recursion(1, N-1, arr);
    
    // vector<vector<int>> dp(N, vector<int>(N, -1));
    // return memoization(1, N-1, dp, arr);
    
    return tabulation(N, arr);
    
    // return spaceOptimization(N, arr);
}

int main() {
    return 0;
}