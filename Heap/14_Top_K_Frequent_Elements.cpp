#include<bits/stdc++.h>
using namespace std;

// Better Approach: Using Min Heap
class SolutionBetter {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int it : nums) {
            mp[it]++;
        }

        priority_queue<tuple<int, int>, vector<tuple<int, int>>,
                       greater<tuple<int, int>>>
            pq;

        for (auto [num, freq] : mp) {
            if (pq.size() < k) {
                pq.push({freq, num});
            } else if (get<0>(pq.top()) < freq) {
                pq.pop();
                pq.push({freq, num});
            }
        }

        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(get<1>(pq.top()));
            pq.pop();
        }

        return ans;
    }
};
// Time Complexity: O(n log k) + O(k log k) ~ O(n log k)
// Space Complexity: O(n) + O(k) ~ O(n)


// Optimal Approach: Using Bucket Sort
class SolutionOptimal {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        int size = 0;

        for(int it: nums){
            mp[it]++;
        }

        vector<vector<int>> bucket(nums.size()+1);

        for(auto [num,count] : mp){
            bucket[count].push_back(num);
        }

        vector<int> ans;

        for(int i=nums.size(); i>=1 && ans.size()<k; i--){
            for(int num : bucket[i]){
                ans.push_back(num);
                if(ans.size()==k){
                    break;
                }
            }
        }

        return ans;
    }
};
// Time Complexity: O(n) + O(n) + O(n) ~ O(n)
// Space Complexity: O(n) + O(k) ~ O(n)