#include<bits/stdc++.h>
using namespace std;

// find the sum of edges in the minimum spanning tree
int spanningTree(int V, vector<vector<int>> adj[])
{
    // here we just need to find the minimum spanning tree weight, not the tree edges 
    // so we will not take parent, in priority queue

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    vector<int> vis(V, 0);
    pq.push({0,0}); // wt, node
    
    int sum = 0;
    
    // E times (run)
    while(!pq.empty()){

        // log E (times run)
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();
        
        if(vis[node]){
            continue;
        }
        
        vis[node] = 1;
        sum+= wt;
        
        // total ElogE times
        for(auto it: adj[node]){
            int adjNode = it[0];
            int edW = it[1];
            
            if(!vis[adjNode]){
                pq.push({edW, adjNode});
            }
        }
    }
    
    return sum;
}
// Time Complexity: O(E Log E)    // E: total number of edges in the graph
// Space Complexity: O(E)

// find the edges of minimum spanning tree
int spanningTreeEdges(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    
    vector<int> vis(V, 0);
    vector<pair<int,int>> mst;
    int sum = 0;
    
    pq.push({0,{0,-1}}); 
    
    while(!pq.empty()){
        auto it = pq.top();
        int wt = it.first;
        int node = it.second.first;
        int prt = it.second.second;
        pq.pop();
        
        if(vis[node]){
            continue;
        }
        
        vis[node] = 1;
        sum+= wt;
        
        if(prt!=-1){
            mst.push_back({node, prt});
        }
        
        for(auto it: adj[node]){
            int adjNode = it[0];
            int edW = it[1];
            
            if(!vis[adjNode]){
                pq.push({edW, {adjNode, node}});
            }
        }
    }
    
    return sum;
}
// Time Complexity: O(ELogV);
// Space Complexity: O(V+E)

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
}