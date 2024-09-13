#include <bits/stdc++.h>
using namespace std;

int memomization(int n, vector<int> &dp){
    if(n==0) return 1;
    if(n==1) return 1;

    if(dp[n]!=-1){
        return dp[n];
    }

    return dp[n] = memomization(n-1, dp) + memomization(n-2, dp);
}
// Time Complexity: O(N);
// Space Complexity: O(N) + O(N) for recursive stack space

int tabulation(int n, vector<int> &dp){
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}
// Time Complexity: O(N);
// Space Complexity: O(N) 

int spaceOptimization(int n){
    int prev = 1, prev2 = 1;

    for(int i=2; i<=n; i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }

    return prev;
}
// Time Complexity: O(N);
// Space Complexity: O(1)

int climbStairs(int n) {
    vector<int> dp(n+1, -1);
    return spaceOptimization(n);
}

int main() {
    return 0;
}