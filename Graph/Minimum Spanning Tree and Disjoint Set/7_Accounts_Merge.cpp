#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int> sizeVec, parent;
    DisjointSet(int n){
        sizeVec.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int upu = findParent(u);
        int upv = findParent(v);

        if(upu == upv) return;

        if(sizeVec[upu] < sizeVec[upv]){
            parent[upu] = upv;
            sizeVec[upv] += sizeVec[upu];
        }else{
            parent[upv] = upu;
            sizeVec[upu] += sizeVec[upv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n = details.size();
        unordered_map<string, int> mp;
        
        DisjointSet ds(n);
        
        for(int i=0; i<n; i++){
            for(int j=1; j<details[i].size(); j++){
                string mail = details[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail] = i;
                }else{
                    ds.unionBySize(i, mp[mail]);
                }
            }
        }
        
        vector<string> mergeMail[n];
        
        for(auto it: mp){
            string mail = it.first;
            int  node = ds.findParent(it.second);  // always be ultimate parent
            
            mergeMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        
        for(int i=0; i<n; i++){
            if(mergeMail[i].size()!=0){
                sort(mergeMail[i].begin(), mergeMail[i].end());
                mergeMail[i].insert(mergeMail[i].begin(),details[i][0]);
                ans.push_back(mergeMail[i]);
            }
        }
        
        return ans;
    }
};

int main()
{
    return 0;
}