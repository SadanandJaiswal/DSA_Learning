#include<bits/stdc++.h>
using namespace std;

class ReplaceElementByRankBruteForce {
  public:
    void replaceWithRank(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n);
        
        for(int i=0; i<n; i++){
            int rank = 0;
            
            for(int j=0; j<n; j++){
                if(i==j) continue;
                
                if(arr[j]<arr[i]){
                    rank++;
                }else if(arr[j]==arr[i] && j<i){
                    rank++;
                }
            }
            
            ans[i] = rank;
        }
        
        arr = ans;
    }
};
// Time Complexity: O(N^2) where N is the number of elements in the array.
// Space Complexity: O(N) for the answer array.


class ReplaceElementByRankBetter {
  public:
    void replaceWithRank(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> sortedArray = arr;
        
        sort(sortedArray.begin(), sortedArray.end());
        
        unordered_map<int,queue<int>> mp;
        
        for(int i=0; i<n; i++){
            mp[arr[i]].push(i);
        }
        
        int rank = 0;
        
        for(int i=0; i<n; i++){
            arr[mp[sortedArray[i]].front()] = rank++;
            mp[sortedArray[i]].pop();
        }
    }
};
// Time Complexity: O(NlogN) where N is the number of elements in the array.
// Space Complexity: O(N) for the sorted array and the map.

class ReplaceElementByRank_IfRankSame_Better {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> sortedArray = arr;
        
        sort(sortedArray.begin(), sortedArray.end());
        
        unordered_map<int,int> mp; // elm, rank
        
        int rank = 0;

        for(int i=0; i<n; i++){
            if(mp.find(sortedArray[i])==mp.end()) 
                mp[sortedArray[i]]=++rank;
        }
        7
        for(int i=0; i<n; i++){
            sortedArray[i] = mp[arr[i]];
        }

        return sortedArray;
    }
};
// Time Complexity: O(NlogN) where N is the number of elements in the array.
// Space Complexity: O(N) for the sorted array and the map.

