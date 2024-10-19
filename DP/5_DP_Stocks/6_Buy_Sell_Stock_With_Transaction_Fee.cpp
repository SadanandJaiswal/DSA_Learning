#include <bits/stdc++.h>
using namespace std;

int recursion(int i, bool buy, int fee, vector<int> &prices){
    if(i==prices.size()) return 0;  // get nothing from market if already buy still get negative so better to have zero

    if(buy){
        int take = -prices[i] + recursion(i+1, false, fee, prices);
        int notTake = recursion(i+1, true, fee, prices);
        return max(take, notTake);
    }

    int sell = prices[i] -fee + recursion(i+1, true, fee, prices);
    int notSell = recursion(i+1, false, fee, prices);
    return max(sell, notSell);
}
// Time Complexity: O(2^n) -> exponential
// Space Complexity: O(n)

int memoization(int i, bool buy, vector<vector<int>> &dp, int fee, vector<int> &prices){
    if(i==prices.size()) return 0;  

    if(dp[i][buy]!=-1) return dp[i][buy];

    if(buy){
        int take = -prices[i] + memoization(i+1, false, dp, fee, prices);
        int notTake = memoization(i+1, true, dp, fee, prices);
        return dp[i][buy] = max(take, notTake);
    }

    int sell = prices[i] -fee + memoization(i+1, true, dp, fee, prices);
    int notSell = memoization(i+1, false, dp, fee, prices);
    return dp[i][buy] = max(sell, notSell);
}
// Time Complexity: O(2*n) 
// Space Complexity: O(2*n) + O(n)

int tabulation(int fee, vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for(int i=n-1; i>=0; i--){
        dp[i][1] = max( -prices[i] + dp[i+1][0], dp[i+1][1]);

        dp[i][0] = max(prices[i] - fee + dp[i+1][1], dp[i+1][0]);
    }

    return dp[0][1];
}
// Time Complexity: O(2*n) 
// Space Complexity: O(2*n)

int spaceOptimization(int fee, vector<int> &prices){
    int n = prices.size();
    vector<int> prev(2, 0), curr(2, 0);

    for(int i=n-1; i>=0; i--){
        curr[1] = max( -prices[i] + prev[0], prev[1]);

        curr[0] = max(prices[i] - fee + prev[1], prev[0]);

        prev = curr;
    }

    return prev[1];
}
// Time Complexity: O(2*n) 
// Space Complexity: O(2*2)

int maxProfit(vector<int>& prices, int fee) {
    // return recursion(0, true, fee, prices);

    // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    // return memoization(0, true, dp, fee, prices);

    return tabulation(fee, prices);
}

int main() {
    // Transaction fee is applicable when transaction is completed
    return 0;
}