#include<bits/stdc++.h>
using namespace std;

// Cycle Detection in directed graph using bfs (kahn's algorithm)
bool isPossible(int V,int P, vector<pair<int, int> >& prerequisites) {
	    // Create the graph (adj list)
	    vector<int> adj[V];
	    
	    for(auto it: prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    
	    // check for topo sort
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
        
        return topo.size()==V;
	}
// Time Complexity: O(V+E);
// Space Complexity: O(V+E);

int main()
{
    return 0;
}