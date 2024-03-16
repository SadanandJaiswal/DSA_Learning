#include<bits/stdc++.h>
using namespace std;

// ************ Approach 1: take/no take, set ********************
class Solution {
public:
    void solve(int i, int n, vector<vector<int>> &result, vector<int> &v, vector<int> &nums, set<vector<int>> &seen)
    {
        if(i>=n)
        {
            if(seen.find(v)==seen.end())
            {
                result.push_back(v);
                seen.insert(v);
            }
            return ;
        }

        v.push_back(nums[i]);
        solve(i+1, n, result, v, nums, seen);
        v.pop_back();

        solve(i+1, n , result, v, nums, seen);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> result;
        // sort(nums.begin(),nums.end());   // there is no need of sorting the input array/vector
        set<vector<int>> seen;
        solve(0,nums.size(), result, v, nums, seen);
        return result;
    }
};

// Time complexity: O(2^n * logn) 
// Space complexity: O(2^n)


// *********************** Approach 2: (without using set) backtracking ********************

class Solution {
public:
    void solve(int i, int n, vector<vector<int>> &result, vector<int> &v, vector<int> &nums)
    {
        if(i>=n) return;

        for(int j=i; j<n; j++)
        {
            if(j>i && nums[j] == nums[j-1]) continue;
            v.push_back(nums[j]);
            result.push_back(v);
            solve(j+1, n, result, v, nums);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> result;
        result.push_back({});
        sort(nums.begin(), nums.end());
        solve(0,nums.size(), result, v, nums);
        return result;
    }
};