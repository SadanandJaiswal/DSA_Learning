#include <bits/stdc++.h>
using namespace std;

int memomization(int i, int j, vector<vector<int>> &dp, string &s1, string &s2){
    if(i==0 || j==0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i-1]==s2[j-1]){
        return dp[i][j] = 1 + memomization(i-1, j-1, dp, s1, s2);
    }

    return dp[i][j] = max(memomization(i-1, j, dp, s1, s2), memomization(i, j-1, dp, s1, s2));
}
// Time Complexity: O(n*m)
// Space Complexity: O(n+m)

int tabulation(int n, int m, string &s1, string &s2){
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}
// Time Complexity: O(n*m)
// Space Complexity: O(n*m) + O(n+m)

int spaceOptimization(int n, int m, string &s1, string &s2){
    vector<int> prev(m+1, 0), curr(m+1, 0);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1]==s2[j-1]){
                curr[j] = 1 + prev[j-1];
            }else{
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }

    return prev[m];
}
// Time Complexity: O(n*m)
// Space Complexity: O(m)

int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    // int lcs = memomization(n, m, dp, word1, word2);

    // int lcs = tabulation(n, m, word1, word2);

    int lcs = spaceOptimization(n, m, word1, word2);

    return n + m - 2*lcs;
}

int main() {
    // Find the longest common subsequence in both the string, to make string equal by deleting, delete all the extra character from both the string that are not present in longest common subsequence of the two string
    return 0;
}