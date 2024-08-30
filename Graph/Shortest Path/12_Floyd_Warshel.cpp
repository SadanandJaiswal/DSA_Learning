#include<bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>>&matrix){
    // We have to do in place, means we will not create dist/cost matrix we will do in matrix itself
    
    int n = matrix.size();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j]==-1){
                matrix[i][j] = 1e9;
            }
            if(i==j) matrix[i][j]=0;
        }
    }
    
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
            }
        }
    }

    // detect negative cycle
    //  for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         if(matrix[i][j]<0){
    //             // negative cycle detected
    //         }
    //     }
    // }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j]==1e9){
                matrix[i][j] = -1;
            }
        }
    }
}
// Time Complexity: O(V*V*V)
// Space Complexity: O(V*V);

// if negative is not given we can use dijkstra for all the nodes and it will take lesser time than this


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