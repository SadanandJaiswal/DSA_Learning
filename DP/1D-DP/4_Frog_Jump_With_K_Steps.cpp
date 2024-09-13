#include <bits/stdc++.h>
using namespace std;

int memo(int ind, vector<int> &dp, int k, vector<int> &h){
    if(ind==0) return 0;    
    if(ind==1) return abs(h[1] - h[0]);
    
    if(dp[ind] != -1) return dp[ind];
    
    int ans = INT_MAX;
    
    for(int i=1; i<=k; i++){
        if(ind-i>=0){
            ans = min(ans, memo(ind-i, dp, k, h) + abs(h[ind] - h[ind-i]));
        }
    }
    
    return dp[ind] = ans;
}
// Time Complexity: O(N);
// Space Complexity: O(N) + O(N) for recursive stack space

int tabulation(int n, int k, vector<int> &dp, vector<int> &h){
    dp[0] = 0;
    // dp[1] = abs(h[1] - h[0]);

    for(int ind = 1; ind<n; ind++){
        int ans = INT_MAX;
        for(int i=1; i<=k; i++){
            if(ind-i>=0){
                ans = min(ans, dp[ind-i] + abs(h[ind] - h[ind-i]));
            }
        }
        dp[ind] = ans;
    }

    return dp[n-1];
}
// Time Complexity: O(N);
// Space Complexity: O(N) 

int spaceOptimization(int n, int k, vector<int> &h){
    deque<int> dp;
    dp.push_back(0);

    for(int i=1; i<n; i++){
        int curr = INT_MAX;
        for(int j=1; j<=k; j++){
            if(i-j>=0){
                curr = min(curr, dp[dp.size()-j] + abs(h[i] - h[i-j]));
            }
        }

        dp.push_back(curr);

        if (dp.size() > k) {
            dp.pop_front();
        }
    }

    return dp[k-1];
}
// Time Complexity: O(N);
// Space Complexity: O(1)

int minimizeCost(vector<int>& arr, int& k) {
    // Code here
    int n = arr.size();
    vector<int> dp(n+1, -1);
    // return memo(n-1, dp, k, arr);
    // return tabulation(n, k, dp, arr);
    return spaceOptimization(n, k, arr);
}

int main() {
return 0;
}