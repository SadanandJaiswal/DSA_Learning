#include <bits/stdc++.h>
using namespace std;

int recursion(int l1, int l2, string &s1, string &s2){
    if(l1<0 || l2<0) return 0;

    if(s1[l1]==s2[l2]){
        return 1 + recursion(l1-1, l2-1, s1, s2);
    }

    return max(recursion(l1-1, l2, s1, s2), recursion(l1, l2-1, s1, s2));
}
// Time Complexity: O(2^n * 2^m)
// Space Complexity: O(n+m) -> recursive stack space

int memoization(int l1, int l2, vector<vector<int>> &dp, string &s1, string &s2){
    if(l1<0 || l2<0) return 0;

    if(dp[l1][l2]!=-1) return dp[l1][l2];

    if(s1[l1]==s2[l2]){
        return dp[l1][l2] = 1 + memoization(l1-1, l2-1, dp, s1, s2);
    }

    return dp[l1][l2] =  max(memoization(l1-1, l2, dp, s1, s2), memoization(l1, l2-1, dp, s1, s2));
}
// Time Complexity: O(n*m)
// Space Complexity: O(n*m) + O(n+m)

int memoization2(int l1, int l2, vector<vector<int>> &dp, string &s1, string &s2){
    if(l1==0 || l2==0) return 0;

    if(dp[l1][l2]!=-1) return dp[l1][l2];

    if(s1[l1-1]==s2[l2-1]){
        return dp[l1][l2] = 1 + memoization2(l1-1, l2-1, dp, s1, s2);
    }

    return dp[l1][l2] =  max(memoization2(l1-1, l2, dp, s1, s2), memoization2(l1, l2-1, dp, s1, s2));
}
// Time Complexity: O(n*m)
// Space Complexity: O(n*m) + O(n+m)

int tabulation(int l1, int l2, string &s1, string &s2){
    vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));

    // we can't write dp[-1], we will do shifting of index
    // shift the index by one in right -> -1 will be 0

    for(int i=0; i<=l2; i++){
        dp[0][i] = 0;
    }
    for(int i=0; i<=l1; i++){
        dp[i][0] = 0;
    }

    for(int i=1; i<=l1; i++){
        for(int j=1; j<=l2; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[l1][l2];
}
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

int spaceOptimization(int l1, int l2, string &s1, string &s2){
    vector<int> prev(l2+1, 0), curr(l2+1, 0);

    for(int i=1; i<=l1; i++){
        for(int j=1; j<=l2; j++){
            if(s1[i-1] == s2[j-1]){
                curr[j] = 1 + prev[j-1];
            }else{
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }

    return prev[l2];
}
// Time Complexity: O(n*m)
// Space Complexity: O(m)

int longestCommonSubsequence(string text1, string text2) {
    int l1 = text1.size();
    int l2 = text2.size();

    // return recursion(l1-1, l2-1, text1, text2);

    vector<vector<int>> dp(l1, vector<int>(l2, -1));
    // return memoization(l1-1, l2-1, dp, text1, text2);

    // we can't write dp[-1], we will do shifting of index
    // shift the index by one in right -> -1 will be 0
    vector<vector<int>> dp2(l1+1, vector<int>(l2+1, -1));
    // return memoization2(l1, l2, dp2, text1, text2);

    // return tabulation(l1, l2, text1, text2);

    return spaceOptimization(l1, l2, text1, text2);
}

int main() {
    return 0;
}