#include<bits/stdc++.h>
using namespace std;

// approach 1 
// time complexity: O(n*n!)
// extra n due to visited
void solve(int i, vector<string> &result, string &s, string str, vector<bool> & visited)
{
    if(i == str.size())
    {
        result.push_back(s);
        return; 
    }

    for(int j=0; j<str.size(); j++)
    {
        if(visited[j]==false)
        {
            s.push_back(str[j]);
            solve(i+1,  result, s, str, visited);
            s.pop_back();
        }
    }
}

// approach2
// time complexity: O(n!)
void solve2(int i, vector<string> &result, string &s)
{
    if(i==s.size())
    {
        result.push_back(s);
        return;
    }

    for(int j=i; j<s.size(); j++)
    {
        swap(s[i], s[j]);
        solve(i+1, result, s);
        swap(s[i], s[j]);
    }
}



int main(){
    string str = "abcd";
    vector<string> result;
    string s = "";
    vector<bool> visited = {false};
    solve(0, result, s, str, visited);
    sort(result.begin(), result.end());
    
}