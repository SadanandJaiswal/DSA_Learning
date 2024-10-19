#include <bits/stdc++.h>
using namespace std;

int memoization(int i, bool buy, int cnt, vector<vector<vector<int>>> &dp, vector<int>& prices){
    if(cnt==0) return 0;
    if(i==prices.size()) return 0;

    if(dp[i][buy][cnt]!=-1) return dp[i][buy][cnt];

    if(buy){
        int take = -prices[i] + memoization(i+1, false, cnt, dp, prices);
        int notTake =  memoization(i+1, true, cnt, dp, prices);
        return dp[i][buy][cnt] = max(take, notTake);
    }

    int sell = prices[i] + memoization(i+1, true, cnt-1, dp, prices);
    int notSell = memoization(i+1, false, cnt, dp, prices);
    return dp[i][buy][cnt] = max(sell, notSell);
}
// Time Complexity: O(2*n*k+1)
// Space Complexiy: O(2*k+1*n) + O(n)

int tabulation(int n, int k, vector<int>&prices){
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<=1; buy++){
            for(int cnt=1; cnt<=k; cnt++){
                if(buy){
                    int take = -prices[i] + dp[i+1][0][cnt];
                    int notTake =  dp[i+1][1][cnt];
                    dp[i][buy][cnt] = max(take, notTake);
                }else{
                    int sell = prices[i] + dp[i+1][1][cnt-1];
                    int notSell = dp[i+1][0][cnt];
                    dp[i][buy][cnt] = max(sell, notSell);
                }
            }
        }
    }

    return dp[0][1][k];
}
// Time Complexity: O(2*n*k)
// Space Complexiy: O(2*k*n)

int spaceOptimization(int n, int k, vector<int> &prices){
    vector<vector<int>> prev(2, vector<int>(k+1, 0)), curr(2, vector<int>(k+1, 0));

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<=1; buy++){
            for(int cnt=1; cnt<=k; cnt++){
                if(buy){
                    int take = -prices[i] + prev[0][cnt];
                    int notTake =  prev[1][cnt];
                    curr[buy][cnt] = max(take, notTake);
                }else{
                    int sell = prices[i] + prev[1][cnt-1];
                    int notSell = prev[0][cnt];
                    curr[buy][cnt] = max(sell, notSell);
                }
            }
        }
        prev = curr;
    }

    return prev[1][k];
}
// Time Complexity: O(2*n*k)
// Space Complexiy: O(2*k)

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
    // return memoization(0, true, k, dp, prices);

    // return tabulation(n, k, prices);

    return spaceOptimization(n, k, prices);
}

int main() {
    return 0;
}