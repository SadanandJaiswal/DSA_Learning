#include <bits/stdc++.h>
using namespace std;

int recursion(int ind, int t, vector<vector<int>> &arr, int n){
    if(ind==0){
        int maxi = 0;
        for(int i=0; i<3; i++){
            if(i!=t){
                maxi = max(maxi, arr[0][i]);
            }
        }
        return maxi;
    }
    
    int maxi = 0;
    
    for(int i=0; i<3; i++){
        if(i!=t){
            int points = recursion(ind-1, i, arr, n) + arr[ind][i];
            maxi = max(maxi, points);
        }
        
    }
    
    return maxi;
}
// Time Complexity: O(3^N)
// Space Complexity: O(N)

int memomization(int ind, int t, vector<vector<int>> &dp, vector<vector<int>> &arr, int n){
    if(ind==0){
        int maxi = 0;
        for(int i=0; i<3; i++){
            if(i!=t){
                maxi = max(maxi, arr[0][i]);
            }
        }
        return maxi;
    }
    
    if(dp[ind][t] != -1){
        return dp[ind][t];
    }
    
    int maxi = 0;
    
    for(int i=0; i<3; i++){
        if(i!=t){
            int points = memomization(ind-1, i, dp, arr, n) + arr[ind][i];
            maxi = max(maxi, points);
        }
        
    }
    
    return dp[ind][t] = maxi;
}
// Time Complexity: O(N*4)*3
// Space Complexity: O(N*4) + O(N)

int tabulation(vector<vector<int>> &dp, vector<vector<int>> &arr, int n){
    for(int t=0; t<3; t++){
        int maxi = 0;
        for(int i=0; i<3; i++){
            if(i!=t){
                maxi = max(maxi, arr[0][i]);
            }
        }
        dp[0][t] = maxi;
    }
    
    for(int d=1; d<n; d++){
        for(int t=0; t<4; t++){
            int maxi = 0;
            for(int i=0; i<3; i++){
                if(i!=t){
                    int points = dp[d-1][i] + arr[d][i];
                    maxi = max(maxi, points);
                    dp[d][t] = maxi;
                }
            }
        }
    }
    
    return dp[n-1][3];
}
// Time Complexity: O(N*4)*3
// Space Complexity: O(N*4)

int spaceOptimization(vector<vector<int>> &arr, int n){
    vector<int> prev(4, -1);
    vector<int> curr(4, -1);
    
    for(int t=0; t<3; t++){
        int maxi = 0;
        for(int i=0; i<3; i++){
            if(i!=t){
                maxi = max(maxi, arr[0][i]);
            }
        }
        prev[t] = maxi;
    }
    
    for(int d=1; d<n; d++){
        for(int t=0; t<4; t++){
            int maxi = 0;
            for(int i=0; i<3; i++){
                if(i!=t){
                    int points = prev[i] + arr[d][i];
                    maxi = max(maxi, points);
                    curr[t] = maxi;
                }
            }
        }
        
        prev = curr;
    }
    
    return prev[3];
}
// Time Complexity: O(N*4)*3
// Space Complexity: O(2*4)

int maximumPoints(vector<vector<int>>& arr, int n) {
    // Recursion
    // return recursion(n-1, 3, arr, n);
    
    vector<vector<int>> dp(n, vector<int>(4, -1));
    
    // // Memomization
    // return memomization(n-1, 3, dp, arr, n);
    
    // // // Tabulation
    // return tabulation(dp, arr, n);
    
    // // Space Optimization
    return spaceOptimization(arr, n);
}

int main() {
    return 0;
}