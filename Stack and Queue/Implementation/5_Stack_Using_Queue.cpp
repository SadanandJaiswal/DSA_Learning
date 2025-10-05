#include <bits/stdc++.h>
using namespace std;

// Method 1: Expensive Push
class Stack{
    queue<int> q;
    
public:
    void push(int val){
        int nelm = q.size();
        q.push(val);
        while(nelm--){
            int top = q.front();
            q.pop();
            q.push(top);
        }
    }
    
    void pop(){
        if(q.empty()){
            cout << "Stack is empty\n";
            return;
        }
        q.pop();
    }
    
    int peak(){
        if(q.empty()){
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }
    
    bool isEmpty(){
        return q.empty();
    }
    
    void display(){
        queue<int> newq = q;
        while(!newq.empty()){
            cout << newq.front() << " ";
            newq.pop();
        }
        cout << endl;
    }
};

// Method 2: Expensive pop and peak 
class Stack2{
    
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Stack elements: ";
    st.display(); // Output: 30 20 10
    
    cout << "Top element: " << st.peak() << endl; // Output: 30
    
    st.pop();
    cout << "Stack after pop: ";
    st.display(); // Output: 20 10
    
    cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;
}
