#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    // 2) adjacency list
    // use array of size n with empty list
    vector<int> alist[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        // u--->v
        alist[u].push_back(v);
        // alist[v].push_back(1);
    }
    // space complexity: O(E)   // only adjacent will be inserted

}