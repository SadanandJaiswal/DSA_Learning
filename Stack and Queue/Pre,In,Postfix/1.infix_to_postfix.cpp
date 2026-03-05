#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string infixToPostfix(string& s) {
        // code here
        
        stack<char> st;
        string ans;
        
        unordered_map<char, int> priority = {
            {'^',3},
            {'*',2}, {'/',2},
            {'+',1}, {'-',1}
        };
        
        
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            
            if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
                ans+=ch;
            }else if (ch=='('){
                st.push(ch);
            }else if (ch==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }else{
                while(!st.empty() && 
                    (priority[st.top()]>priority[ch] || (priority[st.top()]==priority[ch] && ch!='^'))
                ){
                    ans+=st.top();
                    st.pop();
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
};


int main(){}