#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int precedence(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        // if (c == '+' || c == '-') return 1;
        return 1;
        // return -1;
    }

    string infixToPostfix(string &s){
        stack<char> st;
        string ans;
        
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            
            if(isalnum(ch)){
                ans+=ch;
            }
            else if(ch=='('){
                st.push(ch);
            }
            else if(ch==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                if(s[i]=='^'){
                    while(!st.empty() && precedence(ch)<=precedence(st.top())){
                        ans+= st.top();
                        st.pop();
                    }
                }else{
                    while(!st.empty() && precedence(ch)<precedence(st.top())){
                        ans+=st.top();
                        st.pop();
                    }
                }
                    st.push(ch);
            }
        }
        
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        return ans;
    }
    
    string infixToPrefix(string &s) {
        // step 1: reverse string
        reverse(s.begin(), s.end());
        
        // step 2: replace ( with ) and ) with (
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                s[i]=')';
            }else if(s[i]==')'){
                s[i]='(';
            }
        }
        
        // step 3: find postfix
        string postfix = infixToPostfix(s);
        
        // step 4: reverse string
        reverse(postfix.begin(), postfix.end());
        
        return postfix;
    }
};
