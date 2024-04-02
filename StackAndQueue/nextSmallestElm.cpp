#include<bits/stdc++.h>
using namespace std;

class NextSmallestElm{
    public:
        vector<int> solve(vector<int> v){
            vector<int> ans;
            stack<int> s;
            int n = v.size();

            for(int i=0; i<n; i++){
                while(!s.empty() && v[i]<=s.top()){
                    s.pop();
                }

                if(!s.empty()) ans[i] = s.top();
                s.push(v[i]);
            }
            return ans;
        }
};