// Given Two string patter and text, if char in patter is ? it can match to any single character, if * it can match sequence of character including empty string, return weather both string are equal or not

#include <bits/stdc++.h>
using namespace std;

bool recursion(int i, int j, string &p, string &s){
   if(i<0 && j<0) return true;
   if(i<0 && j>=0) return false;

   if(j<0 && i>=0){
      for(int k=0; k<=i; k++){
         if(p[k]!='*') return false;
      }
      return true;
   }

   if(p[i]==s[j] || p[i]=='?'){
      return recursion(i-1, j-1, p, s);
   }
   else if(p[i]=='*'){
      bool empty = recursion(i-1, j, p, s);
      bool nonempty = recursion(i, j-1, p, s);
      return empty || nonempty;
   }

   return false;
}
// Time Complexity: O(2^(n+m)) -> exponential
// Space Complexity: O(n+m)

bool memoization(int i, int j, vector<vector<int>> &dp, string &p, string &s){
   if(i<0 && j<0) return true;
   if(i<0 && j>=0) return false;

   if(j<0 && i>=0){
      for(int k=0; k<=i; k++){
         if(p[k]!='*') return false;
      }
      return true;
   }

   if(dp[i][j]!=-1) return dp[i][j];

   if(p[i]==s[j] || p[i]=='?'){
      return dp[i][j] = memoization(i-1, j-1, dp, p, s);
   }
   else if(p[i]=='*'){
      bool empty = memoization(i-1, j, dp, p, s);
      bool nonempty = memoization(i, j-1, dp, p, s);
      return dp[i][j] = empty || nonempty;
   }

   return dp[i][j] = false;
}
// Time Complexity: O(n*m) 
// Space Complexity: O(n*m) + O(n+m)

bool tabulation(int n, int m, string &p, string &s){
   vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

   dp[0][0] = true;

   // No need for this as, by default all values are false
   // for(int j=1; j<=m; j++){
   //    dp[0][j] = false;
   // }

   bool flag = true;
   for(int i=1; i<=n; i++){
      if(p[i-1]!='*'){
         flag = false;
      }
      dp[i][0] = flag;
   }

   for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
         if(p[i-1]==s[j-1] || p[i-1]=='?'){
            dp[i][j] = dp[i-1][j-1];
         }
         else if(p[i-1]=='*'){
            bool empty = dp[i-1][j];
            bool nonempty = dp[i][j-1];
            dp[i][j] = empty || nonempty;
         } else {
            dp[i][j] = false;
         }
      }
   }

   return dp[n][m];
}
// Time Complexity: O(n*m) 
// Space Complexity: O(n*m)

bool spaceOptimization(int n, int m, string &p, string &s){
   vector<bool> prev(m+1, false), curr(m+1, false);

   prev[0] = true;

   bool flag = true;

   for(int i=1; i<=n; i++){
      if(p[i-1]!='*') flag = false;
      curr[0] = flag;

      for(int j=1; j<=m; j++){
         if(p[i-1]==s[j-1] || p[i-1]=='?'){
            curr[j] = prev[j-1];
         }
         else if(p[i-1]=='*'){
            bool empty = prev[j];
            bool nonempty = curr[j-1];
            curr[j] = empty || nonempty;
         } else {
            curr[j] = false;
         }
      }

      prev = curr;
   }

   return prev[m];
}
// Time Complexity: O(n*m) 
// Space Complexity: O(m)

bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   int n = pattern.size();
   int m = text.size();

   // return recursion(n-1, m-1, pattern, text);

   // vector<vector<bool>> dp(n, vector<bool>(m, -1));
   // return memoization(n-1, m-1, dp, pattern, text);

   // return tabulation(n, m, pattern, text);

   return spaceOptimization(n, m, pattern, text);
}

int main() {
    return 0;
}