#include<bits/stdc++.h>
using namespace std;

vector<int> toposort(int V, vector<int> adj[]){
        vector<int> indegree;
        
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(int it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        return topo;
    }
    string findOrder(string dict[], int N, int k) {
        //code here
        vector<int> adj[k];
        
        for(int i=0; i<N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int l = min(s1.size(), s2.size());
            
            for(int p =0; p<l; p++){
                if(s1[p]!=s2[p]){
                    adj[s1[p] - 'a'].push_back(s2[p] - 'a');
                    break;
                }
            }
        }
        
        vector<int> topo = toposort(k, adj);
        string ans = "";
        for(auto it: topo){
            ans+= char(it + 'a');
        }
        
        return ans;
    }

int main()
{
    return 0;
}