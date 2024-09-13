#include <bits/stdc++.h>
using namespace std;

int memo(int i, vector<int> &dp, vector<int> &height){
    if(i==0) return 0;
    
    if(dp[i]!=-1) return dp[i];
    
    int left = memo(i-1, dp, height) + abs(height[i] - height[i-1]);
    int right = INT_MAX;
    if(i>1){
        right = memo(i-2, dp, height) + abs(height[i] - height[i-2]);
    }
    
    return dp[i] = min(left, right);
}
// Time Complexity: O(N);
// Space Complexity: O(N) + O(N) for recursive stack space

int tabulation(int n, vector<int> &dp, vector<int> &height){
    dp[0] = 0;
    dp[1] = abs(height[1] - height[0]);

    for(int i=2; i<n; i++){
        int left = dp[i-1] + abs(height[i-1] - height[i]);
        int right = dp[i-2] + abs(height[i-2] - height[i]);
        dp[i] = min(left, right);
    }

    return dp[n-1];
}
// Time Complexity: O(N);
// Space Complexity: O(N) 

int spaceOptimization(int n, vector<int> &height){
    int first = 0;
    int second = abs(height[1] - height[0]);
    
    if(n<2){
        return first;
    }

    for(int i=2; i<n; i++){
        int left = second + abs(height[i] - height[i-1]);
        int right = first + abs(height[i] - height[i-2]);
        int curr = min(left, right);

        first = second;
        second = curr;
    }

    return second;
}
// Time Complexity: O(N);
// Space Complexity: O(1)

int minimumEnergy(vector<int>& height, int n) {
    vector<int> dp(n+1, -1);
    // return tabulation(n, dp, height);
    return spaceOptimization(n, height);
}

int main() {
    return 0;
}