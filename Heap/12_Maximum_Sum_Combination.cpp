#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        
        vector<int> vec;
        int n = a.size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                vec.push_back(a[i]+b[j]);
            }    
        }
        
        sort(vec.begin(), vec.end(), greater<int>());
        vector<int> ans;
        
        for(int i=0; i<k; i++){
            ans.push_back(vec[i]);
        }
        
        return ans;
    }
};
// Time Complexity: O(n^2 log n^2) + O(k log k) ~ O(n^2 log n) + O(k log k)
// Space Complexity: O(n^2) + O(k) ~ O(n^2)


// Optimized Approach: Using Max Heap
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        
        priority_queue<tuple<int,int,int>> pq;   //sum,index
        
        pq.push({a[0]+b[0],0,0});
        
        set<pair<int,int>> vis;
        vis.insert({0,0});
        
        vector<int> ans;
        
        int n = a.size();
        
        while(!pq.empty() && ans.size()<k){
            auto [sum, i, j] = pq.top();
            pq.pop();
            
            ans.push_back(sum);
            
            if(i+1<n && !vis.count({i+1,j})){
                pq.push({a[i+1]+b[j],i+1,j});
                vis.insert({i+1,j});
            }
            
            if(j+1<n && !vis.count({i,j+1})){
                pq.push({a[i]+b[j+1],i,j+1});
                vis.insert({i,j+1});
            }
        }
        
        return ans;
    }
};
// Time Complexity: O(n log n) + O(n log n) + O(k log k) ~ O(n log n) + O(k log k)
// Space Complexity: O(n) + O(n) + O(k) ~ O(n) + O(k)