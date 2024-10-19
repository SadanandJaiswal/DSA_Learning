#include <bits/stdc++.h>
using namespace std;

int recursion(int i, bool buy, vector<int> &prices){
    if(i==prices.size()) return 0;  // get nothing from market if already buy still get negative so better to have zero

    if(buy){
        int take = -prices[i] + recursion(i+1, false, prices);
        int notTake = recursion(i+1, true, prices);
        return max(take, notTake);
    }

    int sell = prices[i] + recursion(i+1, true, prices);
    int notSell = recursion(i+1, false, prices);
    return max(sell, notSell);
}
// Time Complexity: exponential -> O(2^n)
// Space Complexiy: O(n)

int memoization(int i, bool buy, vector<vector<int>> &dp, vector<int> &prices){
    if(i==prices.size()) return 0;  

    if(dp[i][buy]!=-1) return dp[i][buy];

    if(buy){
        int take = -prices[i] + memoization(i+1, false, dp, prices);
        int notTake = memoization(i+1, true, dp, prices);
        return dp[i][buy] = max(take, notTake);
    }

    int sell = prices[i] + memoization(i+1, true, dp, prices);
    int notSell = memoization(i+1, false, dp, prices);
    return dp[i][buy] = max(sell, notSell);
}
// Time Complexity: O(2*n)
// Space Complexiy: O(2*n) + O(n)

int tabulation(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    // dp[n][0] = dp[n][1] = 0;

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<=1; buy++){
            if(buy){
                int take = -prices[i] + dp[i+1][0];
                int notTake = dp[i+1][1];
                dp[i][buy] = max(take, notTake);
            }else{
                int sell = prices[i] + dp[i+1][1];
                int notSell = dp[i+1][0];
                dp[i][buy] = max(sell, notSell);
            }
        }
    }

    return dp[0][1];    // not dp n,1
}
// Time Complexity: O(2*n)
// Space Complexiy: O(2*n)

int spaceOptimization(vector<int> &prices){
    int n = prices.size();
    vector<int> prev(2, 0), curr(2, 0);

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<=1; buy++){
            if(buy){
                int take = -prices[i] + prev[0];
                int notTake = prev[1];
                curr[buy] = max(take, notTake);
            }else{
                int sell = prices[i] + prev[1];
                int notSell = prev[0];
                curr[buy] = max(sell, notSell);
            }
        }
        prev = curr;
    }

    return prev[1];
}
// Time Complexity: O(2*n)
// Space Complexiy: O(2)

int maxProfit(vector<int>& prices) {
    // return recursion(0, true, prices);

    // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    // return memoization(0, true, dp, prices);

    // return tabulation(prices);

    return spaceOptimization(prices);
}

int main() {
    // Multiple Buy and Sell
    return 0;
}