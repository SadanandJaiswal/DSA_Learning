#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string preToPost(string pre_exp) {
        stack<string> st;
        int n = pre_exp.size();
        
        for(int i=n-1; i>=0; i--){
            char ch = pre_exp[i];
            
            if(isalnum(ch)){
                st.push(string(1,ch));
            }else{
                string operand1 = st.top();
                st.pop();
                
                string topElm = operand1+st.top()+ch;
                st.pop();
                
                st.push(topElm);
            }
        }
        
        return st.top();
    }
};
