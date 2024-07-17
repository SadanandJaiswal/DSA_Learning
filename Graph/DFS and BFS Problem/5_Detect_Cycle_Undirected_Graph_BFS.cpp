#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int> arr[], int vis[]){
    // queue to store parent and the node
    queue<pair<int,int>> q;
    q.push({src, -1});

    vis[src]=1;

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it: arr[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push({it,node});
            }else if(parent != it){
                // if it is visited and it is not the parent node of the curr node then we can say cycle is detected
                return true;
            }
        }

    }
    return false;
}
// Time Complexity: O(V+E)
// Space Complexity: O(V)

bool isCyclicBFS(int V, vector<int> arr[]){
    int vis[V] = {0};

    for(int i=0; i<V; i++){
        if(!vis[i]){
            if(detect(i, arr, vis)){
                return true;
            }
        }
    }

    return false;
}

int main(){
    return 0;
}