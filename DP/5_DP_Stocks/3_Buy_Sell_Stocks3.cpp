#include <bits/stdc++.h>
using namespace std;

int recursion(int i, bool buy, int cnt, vector<int>& prices){
    if(cnt==2) return 0;
    if(i==prices.size()) return 0;

    if(buy){
        int take = -prices[i] + recursion(i+1, false, cnt, prices);
        int notTake = recursion(i+1, true, cnt, prices);
        return max(take , notTake);
    }

    int sell = prices[i] + recursion(i+1, true, cnt+1, prices);
    int notSell = recursion(i+1, false, cnt, prices);
    return max(sell, notSell);
}
// Time Complexity: exponential -> O(2^n)
// Space Complexiy: O(n)

int memoization(int i, bool buy, int cnt, vector<vector<vector<int>>> &dp, vector<int>& prices){
    if(cnt==2) return 0;
    if(i==prices.size()) return 0;

    if(dp[i][buy][cnt]!=-1){
        return dp[i][buy][cnt];
    }

    if(buy){
        int take = -prices[i] + memoization(i+1, false, cnt, dp, prices);
        int notTake = memoization(i+1, true, cnt, dp, prices);
        return dp[i][buy][cnt] =  max(take , notTake);
    }

    int sell = prices[i] + memoization(i+1, true, cnt+1, dp, prices);
    int notSell = memoization(i+1, false, cnt, dp, prices);
    return dp[i][buy][cnt] = max(sell, notSell);
}
// Time Complexity: O(2*n*3)
// Space Complexiy: O(2*3*n) + O(n)

int tabulation(vector<int>& prices){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

    // for(int i=0; i<=n; i++){
    //     for(int buy=0; buy<=1; buy++){
    //         dp[i][buy][0] = 0;
    //     }
    // }

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<=1; buy++){
            for(int cnt=1; cnt<=2; cnt++){
                if(buy){
                    int take = -prices[i] + dp[i+1][0][cnt];
                    int notTake = dp[i+1][1][cnt];
                    dp[i][buy][cnt] =  max(take , notTake);
                }
                else{
                    int sell = prices[i] + dp[i+1][1][cnt-1];
                    int notSell = dp[i+1][0][cnt];
                    dp[i][buy][cnt] = max(sell, notSell);
                }
            }
        }
    }
    
    return dp[0][1][2];
}
// Time Complexity: O(2*n*3)
// Space Complexiy: O(2*3*n)

int spaceOptimization(vector<int>& prices){
    int n = prices.size();
    vector<vector<int>> prev(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<=1; buy++){
            for(int cnt=1; cnt<=2; cnt++){
                if(buy){
                    int take = -prices[i] + prev[0][cnt];
                    int notTake = prev[1][cnt];
                    curr[buy][cnt] =  max(take , notTake);
                }
                else{
                    int sell = prices[i] + prev[1][cnt-1];
                    int notSell = prev[0][cnt];
                    curr[buy][cnt] = max(sell, notSell);
                }
            }
        }
        prev = curr;
    }

    return prev[1][2];
}
// Time Complexity: O(2*n*3)
// Space Complexiy: O(2*3)

int maxProfit(vector<int>& prices) {
    // return recursion(0, true, 0, prices);

    // int n = prices.size();

    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
    // return memoization(0, true, 0, dp, prices);

    // return tabulation(prices);

    return spaceOptimization(prices);
}

int main() {
    // At most 2 Buy and Sell
    return 0;
}