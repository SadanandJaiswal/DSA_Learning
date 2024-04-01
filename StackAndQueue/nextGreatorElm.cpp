#include<btis/stdc++.h>
using namespace std;

// Brute Force Approach
vector<int> solve(vector<int> v){
    vector<int> result(n,-1);
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            if(v[j]>v[i])
            {
                result[i] = v[j];
                break;
            }
            // else{
            //     result.push_back(-1);
            // }
        }
    }
    return result;
}

int main(){
    return 0;
}