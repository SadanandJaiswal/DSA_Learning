#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
    vis[node] =1 ;
    for(auto it : adj[node]){
        if(!vis[it]) dfs(it, adj, vis, st);
    }

    st.push(node);
}

vector<int> toposort(int v, vector<int> adj[]){
    vector<int> vis(v, 0);
    vector<int> ans;
    stack<int> st;

    for(int i=0; i<v; i++){
        if(!vis[i]) dfs(i, adj, vis, st);
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}
// Time Complexity: O(V+E);
// Space Complexity: O(V+E);

int main()
{
    return 0;
}