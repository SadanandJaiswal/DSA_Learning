#include<bits/stdc++.h>
using namespace std;

// Cycle Detection in directed graph using bfs (kahn's algorithm)
bool topoSort(int V, vector<int> adj[]) {
        // code here
        int indegree[V] = {0};
        
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        vector<int> topo;
        
        for(int i=0; i<V; i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        return topo.size()!=V;
    }
// Time Complexity: O(V+E);
// Space Complexity: O(V+E);

int main()
{
    return 0;
}