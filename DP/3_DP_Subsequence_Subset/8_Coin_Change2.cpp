#include <bits/stdc++.h>
using namespace std;

int recursion(int i, int amount, vector<int> &coins){
    if(i==0){
        if(amount%coins[i]==0) return 1;
        return 0;
    }       

    int notTake = recursion(i-1, amount, coins);
    int take = 0;
    if(amount>=coins[i]) take = recursion(i, amount - coins[i], coins);

    return take + notTake; 
}
// Time Complexity: exponential -> >>O(2^n)
// Space Complexity: O(target)

int memomization(int i, int amount, vector<vector<int>> &dp, vector<int> &coins){
    if(i==0){
        if(amount%coins[i]==0) return 1;
        return 0;
    }      

    if(dp[i][amount]!=-1) return dp[i][amount]; 

    int notTake = memomization(i-1, amount, dp, coins);
    int take = 0;
    if(amount>=coins[i]) take = memomization(i, amount - coins[i], dp, coins);

    return dp[i][amount] = take + notTake; 
}
// Time Complexity: O(n*target)
// Space Complexity: O(n*target) + O(n)

int tabulation(int amount, vector<int> &coins){
    int n = coins.size();
    vector<vector<long>> dp(n, vector<long>(amount+1, 0));

    for(int i = 0; i <= amount; i++) {
        if(i % coins[0] == 0) {
            dp[0][i] = 1; 
        }
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=amount; j++){
            long  notTake = dp[i-1][j];
            notTake = notTake%INT_MAX;
            long  take = 0;
            if(j>=coins[i]) take = dp[i][j - coins[i]];
            take = take%INT_MAX;

            dp[i][j] = (take + notTake);
        }
    }

    return dp[n-1][amount];
}
// Time Complexity: O(n*target)
// Space Complexity: O(n*target)

int spaceOptimization(int amount, vector<int> &coins){
    int n = coins.size();
    vector<long> prev(amount+1, 0), curr(amount+1, 0);

    for(int i = 0; i <= amount; i++) {
        if(i % coins[0] == 0) {
            prev[i] = 1; 
        }
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=amount; j++){
            long notTake = prev[j]%INT_MAX;
            long take = 0;
            if(j>=coins[i]) take = (curr[j - coins[i]])%INT_MAX;

            curr[j] = (take + notTake);
        }
        prev = curr;
    }

    return prev[amount];
}
// Time Complexity: O(n*target)
// Space Complexity: O(target)

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    // return recursion(n-1, amount, coins);

    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    // return memomization(n-1, amount, dp, coins);

    // return tabulation(amount, coins);
    return spaceOptimization(amount, coins);
}

int main() {
    return 0;
}