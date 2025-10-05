#include <bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> s1, s2;
    
public:
    void push(int val){
        s1.push(val);
    }
    
    void pop(){
        if(s1.empty() && s2.empty()){
            cout << "Queue is empty\n";
            return;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }
    
    int peak(){
        if(s1.empty() && s2.empty()){
            cout << "Queue is empty\n";
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool isEmpty(){
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.peak() << endl; // Output: 10
    q.pop();
    cout << "Front after pop: " << q.peak() << endl; // Output: 20
    q.pop();
    q.pop();
    q.pop(); // Queue is empty
}
