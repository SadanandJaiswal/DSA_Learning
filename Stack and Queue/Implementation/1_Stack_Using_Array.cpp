#include <bits/stdc++.h>
using namespace std;

class Stack{
    int top;
    int * arr;
    int capacity;
    
    public:
    
    Stack(int size){
        top = -1;
        capacity = size;
        arr = new int[size];   
    }
    
    ~Stack(){
        delete[] arr;
    }
    
    void push(int value){
        if(top==capacity-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        arr[++top] = value;
    }
    
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
    }
    
    int peek(){
        if(top==-1){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        return arr[top];
    }
    
    bool isEmpty(){
        return top==-1;
    }
    
    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
	// your code goes here
	Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.display();  // 10 20 30

    st.pop();
    st.display();  // 10 20

    cout << "Top element: " << st.peek() << endl;

    return 0;

}
  