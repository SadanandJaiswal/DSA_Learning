#include <bits/stdc++.h>
using namespace std;

int recursion(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    return recursion(n-1) + recursion(n-2);
}
// Time Complexity: O(2^N);
// Space Complexity: O(N) for recursive stack space

int memomization(int n, vector<int> &dp){
    if(n==0) return 0;
    if(n==1) return 1;

    if(dp[n]!=-1){
        return dp[n];
    }

    return dp[n] = memomization(n-1) + memomization(n-2);
}
// Time Complexity: O(N);
// Space Complexity: O(N) + O(N) for recursive stack space

int tabulation(int n, vector<int> &dp){
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-2] + dp[i-1];
    }

    return dp[n];
}
// Time Complexity: O(N);
// Space Complexity: O(N) 

int spaceOptimization(int n){
    int prev = 1;
    int prev2 = 0;

    for(int i=2; i<=n; i++){
        int curr = prev + prev2;

        prev2 = prev;
        prev = curr;
    }

    return prev;
}
// Time Complexity: O(N);
// Space Complexity: O(1);

int fibonacci(int n){
    vector<int> dp(n+1, -1);
    // return recursion(n);
    // return memomization(n, dp);
    // return tabulation(n, dp);
    return spaceOptimization(n);
}

int main() {
    return 0;
}