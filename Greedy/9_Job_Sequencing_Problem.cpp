#include<bits/stdc++.h>
using namespace std;

class SolutionBruteForce {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int,int>> vec;
        
        vector<bool> vis(profit.size(), false);     // O(2*n)
        
        // Time : O(n)
        for(int i=0; i<profit.size(); i++){
            vec.push_back({profit[i], deadline[i]});    
        }
        
        // Time : O(nlogn)
        sort(vec.rbegin(), vec.rend());
        
        int cnt = 0;
        int netProfit = 0;
        
        // Time : O(n*n)
        for(auto v : vec){
            int p = v.first;
            int d = v.second;
            
            for(int i=d-1; i>=0; i--){
                if(!vis[i]){
                    vis[i]=true;
                    netProfit+=p;
                    cnt++;
                    break;
                }
            }
        }
        
        
        return {cnt,netProfit};
    }
};
// Time Complexity : O(nlogn) + O(n*n)
// Space Complexity : O(n) + O(n) for vis vector



class SolutionOptimal {
  public:
    int find(int i, vector<int>& parent){
        if(parent[i]==i)
            return i;
        
        return parent[i] = find(parent[i], parent);
    }
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int,int>> vec;
        
        int n = profit.size();
        
        vector<int> parent(n+1);
        
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
        
        for(int i=0; i<n; i++){
            vec.push_back({profit[i], deadline[i]});    
        }
        
        sort(vec.rbegin(), vec.rend());
        
        int cnt = 0;
        int netProfit = 0;
        
        for(auto [p,d] : vec){
            
            int slot = find(min(d,n), parent);
            
            if(slot==0) continue;
            
            netProfit+=p;
            cnt++;
            
            parent[slot] = find(slot-1, parent);
        }
        
        
        return {cnt,netProfit};
    }
};
// Time Complexity : O(nlogn) + O(n*(alpha)(n))))
// Space Complexity : O(n) + O(n) for parent vector