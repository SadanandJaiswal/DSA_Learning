#include<bits/stdc++.h>
using namespace std;

// Priority Queue Approach 
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        priority_queue<pair<double,int>> maxHeap;
        
        double ans = 0.0;
        
        for(int i=0; i<val.size(); i++){    // O(nlogn)
            maxHeap.push({(double)val[i]/wt[i], wt[i]});    // O(logn)
        }
        
        while(!maxHeap.empty() && capacity>0){  // O(n*logn)
            auto [val, wt] = maxHeap.top();
            maxHeap.pop();  // O(logn)
            
            if(wt>capacity){
                ans+= capacity*val;
                capacity = 0;
            }else{
                capacity-=wt;
                ans+=wt*val;
            }
        }
        
        return ans;
    }
};
// Time Complexity : O(nlogn);
// Space Complexity : O(n);
// 0.42ms


// Sorting Approach
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        
        vector<pair<double,int>> items;
        
        for(int i=0; i<val.size(); i++){
            items.push_back({(double)val[i]/wt[i], wt[i]});
        }
        
        sort(items.rbegin(), items.rend());
        
        double ans = 0.0;
        
        for(auto [val, wt] : items){
            if(capacity>wt){
                ans+= val*wt;
                capacity-=wt;
            }else{
                ans+= val*capacity;
                capacity = 0;
                break;
            }
        }
        
        return ans;
    }
};
// Time Complexity : O(nlogn);
// Space Complexity : O(n);
// 0.39ms


// Sorting Approach (Optimized)
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        
        vector<pair<double,int>> items;
        
        for(int i=0; i<val.size(); i++){
            items.push_back({(double)val[i]/wt[i], wt[i]});
        }
        
        sort(items.begin(), items.end(), [](auto &a, auto&b){
            return a.first>b.first;
        });
        
        double ans = 0.0;
        
        for(auto [val, wt] : items){
            if(capacity>wt){
                ans+= val*wt;
                capacity-=wt;
            }else{
                ans+= val*capacity;
                capacity = 0;
                break;
            }
        }
        
        return ans;
    }
};
// Time Complexity : O(nlogn);
// Space Complexity : O(n);
// 0.33ms


// Sorting Approch + Structure
class Solution {
private:
    struct Item{
        double ratio;
        int weight;
    };
  public:
    
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<Item> items;
        
        for(int i=0; i<val.size(); i++){
            items.push_back({(double)val[i]/wt[i], wt[i]});
        }
        
        sort(items.begin(), items.end(), [](const Item &a, const Item &b){
            return a.ratio>b.ratio;
        });
        
        double ans = 0.0;

        for(auto item : items){
            if(capacity>item.weight){
                ans+= item.ratio*item.weight;
                capacity-=item.weight;
            }else{
                ans+= item.ratio*capacity;
                capacity = 0;
                break;
            }
        }

        return ans;
    }
};
// Time Complexity : O(nlogn);
// Space Complexity : O(n);
