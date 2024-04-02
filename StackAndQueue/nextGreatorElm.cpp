#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach
vector<int> solve(vector<int> v){
    vector<int> result(v.size(),-1);
    for(int i=0; i<2*v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            if(v[j]>v[i])
            {
                result[i] = v[j];
                break;
            }
        }
    }
    return result;
}


// Optimal Approach Using stack
vector<int> OptimalSolve(vector<int> v){
    vector<int> result(v.size(),-1);
    stack<int> st;
    for(int i=v.size()-1; i>=0; i--){
        st.push(v[i]);
    }
    for(int i=v.size()-1; i>=0; i--)
    {
        while(!st.empty() && v[i]>=st.top())    // this will take maximmum n iteration for all the iteration of i included
        {
            st.pop();
        }

            if(!st.empty()){
                result[i] = st.top();
            }

        st.push(v[i%v.size()]);
    }
}
// Time Complexity: O(2*n) = O(n);

int main(){
    return 0;
}