#include<bits/stdc++.h>
using namespace std;

/* steps:
    1. if operand, add to ans
    2. if '(', push to stack
    3. if ')', pop from stack and add to ans until '(' is found, pop '(' as well
    4. if operator, pop from stack and add to ans until stack is empty or precedence of top of stack is less than precedence of current operator, then push current operator to stack
    5. after iterating through the string, pop from stack and add to ans until stack is empty
*/

    int priority(char ch){
        if(ch=='^') return 3;
        else if(ch=='*' || ch=='/') return 2;
        else if(ch=='+' || ch=='-') return 1;
        else return -1;
    }

    string infixToPostfix(string& s) {
        // code here
        
        stack<char> st;
        string ans;
        
        
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
                    (priority(st.top())>priority(ch) || (priority(st.top())==priority(ch) && ch!='^'))
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



int main(){}