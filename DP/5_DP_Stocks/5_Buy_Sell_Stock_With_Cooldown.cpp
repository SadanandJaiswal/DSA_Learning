#include <bits/stdc++.h>
using namespace std;

int memoization(int i, bool buy, vector<vector<int>> &dp, vector<int>& prices){
    if(i>=prices.size()) return 0;

    if(dp[i][buy]!=-1) return dp[i][buy];

    if(buy){
        int take = -prices[i] + memoization(i+1, false, dp, prices);
        int notTake =  memoization(i+1, true, dp, prices);
        return dp[i][buy] = max(take, notTake);
    }

    int sell = prices[i] + memoization(i+2, true, dp, prices);
    int notSell = memoization(i+1, false, dp, prices);
    return dp[i][buy] = max(sell, notSell);
}
// Time Complexity: O(2*n)
// Space Complexity: O(2*n) + O(n)

int tabulation(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n+2, vector<int>(2, 0));

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<=1; buy++){
            if(buy){
                int take = -prices[i] + dp[i+1][0];
                int notTake = dp[i+1][1];
                dp[i][buy] = max(take, notTake);
            }else{
                int sell = prices[i] + dp[i+2][1];
                int notSell = dp[i+1][0];
                dp[i][buy] = max(sell, notSell);
            }
        }
    }

    return dp[0][1];    // not dp n,1
}
// Time Complexity: O(2*n)
// Space Complexity: O(2*n)

int tabulation2(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n+2, vector<int>(2, 0));

    for(int i=n-1; i>=0; i--){
        dp[i][1] = max( -prices[i] + dp[i+1][0], dp[i+1][1]);

        dp[i][0] = max( prices[i] + dp[i+2][1], dp[i+1][0]);
    }

    return dp[0][1];
}
// Time Complexity: O(2*n)
// Space Complexity: O(2*n)

int spaceOptimization(vector<int> &prices){
    int n = prices.size();
    vector<int> prev2(2, 0), prev(2, 0), curr(2, 0);

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<=1; buy++){
            if(buy){
                int take = -prices[i] + prev[0];
                int notTake = prev[1];
                curr[buy] = max(take, notTake);
            }else{
                int sell = prices[i] + prev2[1];
                int notSell = prev[0];
                curr[buy] = max(sell, notSell);
            }
        }
        prev2 = prev;
        prev = curr;
    }

    return prev[1];
}
// Time Complexity: O(2*n)
// Space Complexity: O(2*3)

int spaceOptimization2(vector<int> &prices){
    int n = prices.size();
    vector<int> prev2(2, 0), prev(2, 0), curr(2, 0);

    for(int i=n-1; i>=0; i--){
        curr[1] = max( -prices[i] + prev[0], prev[1]);

        curr[0] = max( prices[i] + prev2[1], prev[0]);

        prev2 = prev;
        prev = curr;
    }

    return prev[1];
}
// Time Complexity: O(n)
// Space Complexity: O(2*3)

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    // vector<vector<int>> dp(n+1, vector<int>(2, -1));
    // return memoization(0, true, dp, prices);

    // return tabulation(prices);

    // return tabulation2(prices);

    // return spaceOptimization(prices);

    return spaceOptimization2(prices);
}

int main() {
    // Buy and Sell Stock with CoolDown
    return 0;
}