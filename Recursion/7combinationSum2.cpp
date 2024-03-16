#include<bits/stdc++.h>;
using namespace std;

// ***************** Approach 1 : using Set TC  = O(2^t * klogx) ********************** //
class Solution {
public:
    void solve(int i, int n, int target, vector<vector<int>> &result, vector<int> &v, vector<int> &a, set<vector<int>> &seen)
    {
        if(i>=n)
        {
            if(target==0)
            {
                if(seen.find(v)==seen.end())
                {
                    result.push_back(v);
                    seen.insert(v);
                }
            }
            return;
        }

        if(target>=a[i])
        {
            v.push_back(a[i]);
            solve(i+1, n, target - a[i], result, v, a, seen);
            v.pop_back();
        }

        solve(i+1, n, target, result, v, a, seen);
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        vector<vector<int>> result;
        vector<int> v;
        set<vector<int>> seen;
        sort(a.begin(), a.end());
        solve(0,a.size(), target, result, v, a, seen);
        return result;
    }
};


// T is target value, k is avg size of combinations, x is the size of set;



// ***************** Approach 2 : using backtracking ********************** //

class Solution {
public:
    void solve(int i, int n, int target, vector<vector<int>> &result, vector<int> &v, vector<int> &a)
    {
        if(target==0)
        {
            result.push_back(v);
            return;
        }

        for(int j=i; j<n; j++)
        {
            // skip the duplicate at same value of i continnuous
            if(j>i && a[j]==a[j-1]) continue;

            // terminate the current reccursion as all values are positive and target is becaume smaller than the a[j]
            if(target<a[j]) break;

            // recursion if we take the element
            v.push_back(a[j]);
            solve(j+1, n, target - a[j], result, v, a);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        vector<vector<int>> result;
        vector<int> v;
        sort(a.begin(), a.end());
        solve(0,a.size(), target, result, v, a);
        return result;
    }
};


//  Time complexity: O(2^T * k)
// T is target value, k is avg size of combinations, x is the size of set;

// Space Complexity: O(k*x) 
//  x is the number of possible combination