#include <bits/stdc++.h>
using namespace std;

int recursion(int i, int target, int price[], int n){
    if(i==0){
        if(target>=1){
            return target*price[0];
        }
        return 0;
    }
    
    int notTake = recursion(i-1, target, price, n);
    int take = 0;
    if(target>=i+1){
        take = price[i] + recursion(i, target-i-1, price, n);
    }
    
    return max(take, notTake);
}
// Time Complexity: exponential -> >>O(2^n)
// Space Complexity: O(n)

int memomization(int i, int target, vector<vector<int>> &dp, int price[], int n){
    if(i==0){
        if(target>=1){
            return target*price[0];
        }
        return 0;
    }
    
    if(dp[i][target]!=-1) return dp[i][target];
    
    int notTake = memomization(i-1, target, dp, price, n);
    int take = 0;
    if(target>=i+1){
        take = price[i] + memomization(i, target-i-1, dp, price, n);
    }
    
    return dp[i][target] = max(take, notTake);
}
// Time Complexity: O(n*(n+1))
// Space Complexity: O(n*(n+1)) + O(n)

int tabulation(int target, int price[], int n){
    vector<vector<int>> dp(n, vector<int>(n+1, 0));
    
    for(int i=1; i<=n; i++){
        dp[0][i] = i*price[0];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0; j<=n; j++){
            int notTake = dp[i-1][j];
            int take = 0;
            if(j>=i+1){
                take = price[i] + dp[i][j - i-1];
            }
            
            dp[i][j] = max(take, notTake);
        }
    }
    
    return dp[n-1][n];
}
// Time Complexity: O(n*(n+1))
// Space Complexity: O(n*(n+1)) 

int spaceOptimization(int target, int price[], int n){
    vector<int> prev(n+1, 0), curr(n+1, 0);
    
    for(int i=1; i<=n; i++){
        prev[i] = i*price[0];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0; j<=n; j++){
            int notTake = prev[j];
            int take = 0;
            if(j>=i+1){
                take = price[i] + curr[j - i-1];
            }
            
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    
    return prev[n];
}
// Time Complexity: O(n*(n+1))
// Space Complexity: O(2(n+1))

int spaceOptimization2(int target, int price[], int n){
    vector<int> prev(n+1, 0);
    
    for(int i=1; i<=n; i++){
        prev[i] = i*price[0];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0; j<=n; j++){
            int notTake = prev[j];
            int take = 0;
            if(j>=i+1){
                take = price[i] + prev[j - i-1];
            }
            
            prev[j] = max(take, notTake);
        }
    }
    
    return prev[n];
}
// Time Complexity: O(n*(n+1))
// Space Complexity: O(n+1)


int cutRod(int price[], int n) {
    //code here
    // return recursion(n-1, n, price, n);
    
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    // return memomization(n-1, n, dp, price, n);
    
    // return tabulation(n, price, n);
    
    // return spaceOptimization(n, price, n);
    
    return spaceOptimization2(n, price, n);
}

int main() {
    return 0;
}