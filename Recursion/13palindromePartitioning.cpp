#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string s)
{
    while(i<j)
    {
        if(s[i++]!=s[j--]) return false;
    }
    return true;
}

void solve(int i, int n, string s, vector<string> &path, vector<vector<string>> &result)
{
    if(i==n)
    {
        result.push_back(path);
        return;
    }

    for(int j=i; j<n; j++)
    {
        if(isPalindrome(i,j,s))
        {
            path.push_back(s.substr(i,j-i+1));
            solve(j+1, n, s, path, result);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> path;
    solve(0,s.size(),s,path, result);

    return result;


}
