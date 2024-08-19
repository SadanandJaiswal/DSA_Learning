#include<bits/stdc++.h>
using namespace std;

vector<int> eventual_safe_node_bfs(int V, vector<int> graph[]){
        // reverse the graph
        vector<int> indegree;

        vector<int> adj[V];
        for(int i = 0; i < V; i++){
            for(auto it: graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
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

        sort(topo.begin(), topo.end());
        
        return topo;    
    }

    // Time Complexity: O(V+E) + O(VlongV)
    // Space Complexity: O(V+E)

int main()
{
    return 0;
}