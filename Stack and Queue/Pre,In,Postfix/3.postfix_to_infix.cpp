#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string postToInfix(string &exp) {
        // Write your code here
        stack<string> st;
        
        for(int i=0; i<exp.size(); i++){
            char ch = exp[i];
            if(isalnum(ch)){
                st.push(string(1,ch));
            }else{
                string operand1, operand2;
                operand2 = st.top();
                st.pop();
                operand1 = st.top();
                st.pop();
                
                string topElm = '('+operand1+ch+operand2+')';
                
                st.push(topElm);
            }
        }
        
        return st.top();
    }
};