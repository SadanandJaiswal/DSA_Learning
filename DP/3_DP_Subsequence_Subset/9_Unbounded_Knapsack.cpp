#include <bits/stdc++.h>
using namespace std;

int recursion(int i, int W, vector<int> &profit, vector<int> &weight){
    if(i==0){
        if(weight[0]<=W){
            return (W/weight[0])*profit[0];
        }
        return 0;
    }

    int notTake = recursion(i-1, W, profit, weight);
    int take = 0;
    if(weight[i]<=W) take = profit[i] + recursion(i, W - weight[i], profit, weight);

    return max(take, notTake);
}
// Time Complexity: exponential -> >>O(2^n)
// Space Complexity: O(maxWeight)

int memomization(int i, int W, vector<int> &profit, vector<vector<int>> &dp, vector<int> &weight){
    if(i==0){
        if(weight[0]<=W){
            return (W/weight[0])*profit[0];
        }
        return 0;
    }

    if(dp[i][W]!=-1) return dp[i][W];

    int notTake = memomization(i-1, W, profit, dp, weight);
    int take = 0;
    if(weight[i]<=W) take = profit[i] + memomization(i, W - weight[i], profit, dp, weight);

    return dp[i][W] = max(take, notTake);
}
// Time Complexity: O(n*maxWeight)
// Space Complexity: O(n*maxWeight) + O(n)

int tabulation(int W, vector<int> &profit, vector<int> &weight){
    int n = profit.size();
    vector<vector<int>> dp(n, vector<int>(W+1, 0));

    for(int i=weight[0]; i<=W; i++){
        dp[0][i] = (i/weight[0])*profit[0];
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=W; j++){
            int notTake = dp[i-1][j];
            int take = 0;
            if(weight[i]<=j) take = profit[i] + dp[i][j - weight[i]];

            dp[i][j] = max(take, notTake);
        }
    }

    return dp[n-1][W];
}
// Time Complexity: O(n*maxWeight)
// Space Complexity: O(n*maxWeight)

int spaceOptimization(int W, vector<int> &profit, vector<int> &weight){
    int n = profit.size();
    vector<int> prev(W+1, 0), curr(W+1, 0);

    for(int i=weight[0]; i<=W; i++){
        prev[i] = (i/weight[0])*profit[0];
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=W; j++){
            int notTake = prev[j];
            int take = 0;
            if(weight[i]<=j) take = profit[i] + curr[j - weight[i]];

            curr[j] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[W];
}
// Time Complexity: O(n*maxWeight)
// Space Complexity: O(maxWeight)

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    // return recursion(n-1, w, profit, weight);

    vector<vector<int>> dp(n, vector<int>(w+1, -1));

    // return memomization(n-1, w, profit, dp, weight);

    // return tabulation(w, profit, weight);

    return spaceOptimization(w, profit, weight);
}

int main() {
    return 0;
}