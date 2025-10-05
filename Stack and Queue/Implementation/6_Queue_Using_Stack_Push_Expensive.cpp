#include <bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> s1, s2;
    
    public:
    
    void push(int val){
        // Step 1: S1 --> S2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        
        // Step 2: push to s1
        s1.push(val);
        
        // Step 3: S2 --> S1 
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    void pop(){
        s1.pop();
    }
    
    int peak(){
        return s1.top();
    }
    
    bool isEmpty(){
        return s1.empty();
    }
    
    void display(){
        stack<int> s3 = s1;
        while(!s3.empty()){
            cout << s3.top() << " ";
            s3.pop();
        }
        cout << endl;
    }
};

int main() {
	// your code goes here

}
