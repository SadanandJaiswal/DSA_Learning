#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    // 1) adjacency matrix
    int adj[n+1][n+1];
    // m-lines to take edges 
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        // non weighted graph./
        adj[u][v] = 1;
        adj[v][u] = 1;

        // weighted graph
        // adj[u][v] = w;
        // adj[u][v] = w;
    }
    // space Complexity: O(N*N)

    // 2) adjacency list
    // use array of size n with empty list
    vector<int> alist[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        alist[u].push_back(v);
        alist[v].push_back(u);

         // weighted graph
        // adj[u].push_back({v,w})
    }
    // space complexity: O(2*E)

}