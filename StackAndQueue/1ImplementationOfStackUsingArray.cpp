#include<bits/stdc++.h>
using namespace std;

class Stack{
    int top;
    int arr[100];

    public:
    Stack(){
        top = -1;
    }

    bool isEmpty(){
        return top == -1;
    }

    void push(int num){
        if(top==99)
        {
            cout<<"Stack Overflow"<<endl;
        }
        arr[++top] = num;
    }

    void pop(){
        if(isEmpty())
        {
            cout<<"Stack Underflow"<<endl;
        }
        top--;
    }

    int peak(){
        return arr[top];
    }


};

int main()
{
    Stack s;
    s.push(1);
    s.push(3);
    s.push(2);
    s.pop();
    cout<<s.peak();
}