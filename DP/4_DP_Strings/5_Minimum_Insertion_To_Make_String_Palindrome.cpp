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

int spaceOptimization(int n, int m, string &s1, string &s2){
    vector<int> prev(n+1, 0), curr(n+1, 0);

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

int minInsertions(string s) {
    int n = s.size();
    string s2 = s;
    reverse(s2.begin(), s2.end());

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    // return n - memomization(n, n, dp, s, s2);

    // return n - tabulation(n, n, s, s2);

    return n - spaceOptimization(n, n, s, s2);
}

int main() {
    return 0;
}