#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool detect(int src, int parent, vector<int> adj[], int vis[]){
    vis[src] =1;

    for(auto it: adj[src]){
        if(!vis[it]){
            vis[it]=1;
            if(detect(it, src, adj, vis)==true){
                return true;
            }
        }else if(it!=src){  // if node is already visited and also not the parent of the current node
                return true;
        }
    }
    
    return false;
}
// Time Complexity: O(V+E)
// Space Complexity: O(V)

bool isCyclicDFS(int V, vector<int> arr[]){
    int vis[V] = {0};

    for(int i=0; i<V; i++){ // if there are connected component in the graph
        if(!vis[i]){
            if(detect(i, -1, arr, vis)){
                return true;
            }
        }
    }

    return false;
}

int main(){
    return 0;
}