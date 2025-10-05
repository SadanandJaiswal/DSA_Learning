#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Queue{
    int size;
    Node* start;
    Node* end;

    public: 
    Queue(){
        size = 0;
        start = end = nullptr;
    }

    void push(int value){
        Node * newNode = new Node(value);
        if(end==nullptr){
            start = end = newNode;
        }else{
            end->next = newNode;
            end = newNode;
        }
        size++;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        Node* temp = start;
        start = start->next;
        
        if(start==nullptr){
            end = nullptr;
        }
        
        delete temp;
        size--;
    }

    int peak(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return start->data;
    }
    
    int getSize() {
        return size;
    }

    bool isEmpty(){
        return start==nullptr;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = start;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    // q.display();         // Queue elements: 30 20 10
    cout << q.peak() << endl;  // 30
    q.pop();
    // q.display();         // Queue elements: 20 10
    cout << q.peak() << endl;  // 20
    return 0;
}