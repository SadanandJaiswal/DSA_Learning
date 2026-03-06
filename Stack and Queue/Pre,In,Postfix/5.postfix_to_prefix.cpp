#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        
        stack<string> st;
        
        for(int i=0; i<post_exp.size(); i++){
            char ch = post_exp[i];
            
            if(isalnum(ch)){
                st.push(string(1,ch));
            }else{
                string operand2 = st.top();
                st.pop();
                
                string topElm = ch + st.top() + operand2;
                st.pop();
                
                st.push(topElm);
            }
        }
        
        return st.top();
    }
};