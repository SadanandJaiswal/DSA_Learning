#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void solve(int i, int j, int n, vector<vector<int>> &m , vector<vector<int>> &vis, string s, vector<string> &result)
    {
        if(i==m.size()-1 && j==m.size()-1)
        {
            result.push_back(s);
            return;
        }
    
        // down
        if(i+1<n && m[i+1][j]==1 && vis[i+1][j]==0)
        {
            vis[i][j]=1;
            solve(i+1, j, n, m, vis, s+"D", result);
            vis[i][j] = 0;
        }

    
        // left
        if(j-1>=0 && m[i][j-1]==1 && vis[i][j-1]==0)
        {
            vis[i][j]=1;
            solve(i, j-1, n, m, vis, s+"L", result);
            vis[i][j] = 0;
        }
    
        // right
        if(j+1<n && m[i][j+1]==1 && vis[i][j+1]==0)
        {
            vis[i][j]=1;
            solve(i, j+1, n, m, vis, s+"R", result);
            vis[i][j] = 0;
        }
    
        // up
        if(i-1>=0 && m[i-1][j]==1 && vis[i-1][j]==0)
        {
            vis[i][j]=1;
            solve(i-1, j, n, m, vis, s+"U", result);
            vis[i][j] = 0;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> result;
        vector<int> v(n,0);
        vector<vector<int>> visited(n,v);
        string s;
        if(m[0][0]==1) solve(0,0,n,m,visited,s,result);
        sort(result.begin(), result.end());
        return result;
    }
};