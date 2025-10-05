#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Stack{
    int size;
    Node* head;

    public: 
    Stack(){
        size = 0;
        head = new Node(-1);
    }

    void push(int value){
        Node * newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        Node * temp = head; // we are using extra temp just because we want to free the memory used by top node
        head = head->next;
        delete temp;
        size--;
    }

    int peak(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        return head->data;
    }

    bool isEmpty(){
        return head==nullptr;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    // st.display();         // Stack elements: 30 20 10
    cout << st.peak() << endl;  // 30
    st.pop();
    // st.display();         // Stack elements: 20 10
    cout << st.peak() << endl;  // 20
    return 0;
}