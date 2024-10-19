// Two strings are given, you can perform either of operation: 1) insertion 2) deletion 3) replace on string s1 to make it equal to s2 with minimum number of operation

#include <bits/stdc++.h>
using namespace std;

public:
int recursion(int i, int j, string &s1, string &s2){
    if(j<0) return i+1;
    if(i<0) return j+1;

    if(s1[i]==s2[j]){
        return recursion(i-1, j-1, s1, s2);
    }

    int insert = 1+recursion(i,j-1, s1, s2);
    int del = 1+recursion(i-1, j, s1, s2);
    int replace = 1+recursion(i-1, j-1, s1, s2);

    return min(insert, min(del, replace));
}
// Time Complexity: O(3^(n+m))
// Space Complexity: O(n+m)

int memomization(int i, int j, vector<vector<int>> &dp, string &s1, string &s2){
    if(j==0) return i;
    if(i==0) return j;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i-1]==s2[j-1]){
        return dp[i][j] = memomization(i-1, j-1, dp, s1, s2);
    }

    int insert = 1+memomization(i,j-1, dp, s1, s2);
    int del = 1+memomization(i-1, j, dp, s1, s2);
    int replace = 1+memomization(i-1, j-1, dp, s1, s2);

    return dp[i][j] = min(insert, min(del, replace));
}
// Time Complexity: O(n*m)
// Space Complexity: O(n*m) + O(n+m)

int tabulation(int n, int m, string &s1, string &s2){
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=0; i<=n; i++){
        dp[i][0] = i;
    }

    for(int i=0; i<=m; i++){
        dp[0][i] = i;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                int insert = dp[i][j-1];
                int del = dp[i-1][j];
                int replace = dp[i-1][j-1];

                dp[i][j] = 1 + min(insert, min(del, replace));
            }
        }
    }

    return dp[n][m];
}
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

int spaceOptimization(int n, int m, string &s1, string &s2){
    vector<int> prev(m+1, 0), curr(m+1, 0);

    for(int i=0; i<=m; i++){
        prev[i] = i;
    }
    
    for(int i=1; i<=n; i++){
        curr[0] = i;
        for(int j=1; j<=m; j++){
            if(s1[i-1]==s2[j-1]){
                curr[j] = prev[j-1];
            }else{
                int insert = curr[j-1];
                int del = prev[j];
                int replace = prev[j-1];

                curr[j] = 1 + min(insert, min(del, replace));
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

    if(word1==word2) return 0;

    // return recursion(n-1, m-1, word1, word2);

    // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    // return memomization(n, m, dp, word1, word2);

    // return tabulation(n, m, word1, word2);

    return spaceOptimization(n, m, word1, word2);
}

int main() {
    return 0;
}