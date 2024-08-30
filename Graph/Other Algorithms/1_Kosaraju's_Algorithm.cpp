#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st){ // pass by reference for adj also
	    vis[node] = 1;
	    
	    for(auto it: adj[node]){
	        if(!vis[it]){
	            dfs(it, adj, vis,st);
	        }
	    }
	    
	    st.push(node);
	} 
	
	void dfs2(int node, vector<vector<int>> &adj, vector<int> &vis){    // pass by reference for adj also
	    vis[node] = 1;
	    
	    for(auto it: adj[node]){
	        if(!vis[it]){
	            dfs2(it, adj, vis);
	        }
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //step 1
        stack<int> st;
        vector<int> vis(V,0);
        
        // O(V+E)
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        // Step 2:
        vector<vector<int>> adj2(V);
        
        // O(V+E)
        for(int i=0; i<V; i++)
        {
            // mark unvisted as we are going to use the same
            vis[i] = 0;
            for(auto v: adj[i])
            {
                adj2[v].push_back(i);
            }
        }
        
        // Step 3:
        int cnt = 0;
        
        // O(V+E)
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                cnt++;
                dfs2(node,adj2,vis);
            }
        }
        
        return cnt;
    }
};
//  Time Complexity: O(V+E);
//  Space Complexity: O(2*V); 

int main() {
    return 0;
}