#include <bits/stdc++.h>
using namespace std;

int recursion(int i, int amount, vector<int>&coins){
    if(i==0){
        if(amount%coins[i]==0) return amount/coins[i];
        return 1e9;
    }

    int nottake = recursion(i-1, amount, coins);
    int take = INT_MAX;
    if(amount>=coins[i]) take = 1 + recursion(i, amount - coins[i], coins);

    return min(take, nottake);
} 
// Time Complexity: exponential -> >>O(2^n)
// Space Complexity: O(target)

int memomization(int i, int amount, vector<vector<int>> &dp, vector<int>&coins){
    if(i==0){
        if(amount%coins[i]==0) return amount/coins[i];
        return 1e9;
    }

    if(dp[i][amount]!=-1) return dp[i][amount];

    int nottake = memomization(i-1, amount, dp, coins);
    int take = INT_MAX;
    if(amount>=coins[i]) take = 1 + memomization(i, amount - coins[i], dp, coins);

    return dp[i][amount] = min(take, nottake);
}
// Time Complexity: O(n*target)
// Space Complexity: O(n*target) + O(n)

int tabulation(int amount, vector<int>&coins){
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, 0));

    for(int i=0; i<=amount; i++){
        if(i%coins[0]==0){
            dp[0][i] = i/coins[0];
        }else{
            dp[0][i] = 1e9;
        }
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=amount; j++){
            int nottake = dp[i-1][j];
            int take = 1e9;
            if(j>=coins[i]) take = 1 + dp[i][j - coins[i]];

            dp[i][j] = min(take, nottake);
        }
    }

    return dp[n-1][amount];
}
// Time Complexity: O(n*target)
// Space Complexity: O(n*target)

int spaceOptimization(int amount, vector<int>& coins){
    int n = coins.size();
    vector<int> prev(amount+1, 0), curr(amount+1, 0);

    for(int i=0; i<=amount; i++){
        if(i%coins[0]==0){
            prev[i] = i/coins[0];
        }else{
            prev[i] = 1e9;
        }
    }

    for(int i=1; i<n; i++){
        // for (int j = 0; j <= amount; j++) {
            int nottake = prev[j];
            int take = 1e9;
            if(j>=coins[i]) take = 1 + curr[j - coins[i]];
            // Didn't understand why curr is used instead of prev

            curr[j] = min(take, nottake);
        }
        prev = curr;
    }

    return prev[amount];
}
// Time Complexity: O(n*target)
// Space Complexity: O(target)

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    // int ans =  recursion(n-1, amount, coins);

    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    // int ans =  memomization(n-1, amount, dp, coins);
    // int ans =  tabulation(amount, coins);
    int ans =  spaceOptimization(amount, coins);
    return ans!=1e9?ans:-1;
}

int main() {
    return 0;
}