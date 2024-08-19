#include<bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int>& arr, int start, int end) {
    // code here
    queue<pair<int,int>> q;
    q.push({0, start});
    // steps, multiplication
    
    vector<int> dist(100000, INT_MAX);
    dist[start] = 0;
    
    while(!q.empty()){
        int steps = q.front().first;
        int node = q.front().second;
        if(node==end) return steps;
        q.pop();
        
        for(int it: arr){
            long long  mul = (it*node)%100000;
            
            if(steps+1 < dist[mul]){
                dist[mul] = steps +1;
                if(mul==end){
                    return steps+1;
                }
                q.push({steps+1, mul});
            }
        }
    }
    
    return -1;
}
// map will not work in this  case nor the unordered_map, it will give tle
// Time Complexity: O(n*10e5);
// Space Complexity: O(10e5);

int main()
{
    return 0;
}