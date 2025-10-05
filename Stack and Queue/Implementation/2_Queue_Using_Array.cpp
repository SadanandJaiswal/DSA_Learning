#include <bits/stdc++.h>
using namespace std;

class Queue{
    int * arr;
    int start, end;
    int capacity, currsize;
    
    public:
    
    Queue(int size){
        capacity = size;
        start = 0;
        end = -1;
        currsize = 0;
        arr = new int[size];
    }
    
    ~Queue(){
        delete[] arr;
    }
    
    void push(int value){
        if(currsize==capacity){
            cout<<"Queue overflow"<<endl;
            return;
        }
        end = (end + 1)%capacity;
        arr[end] = value;
        currsize++;
    }
    
    void pop(){
        if(currsize==0){
            cout<<"Queue is empty"<<endl;
            return;
        }
        start = (start+1)%capacity;
        currsize--;
    }
    
    int top(){
        if(currsize == 0){
            cout << "Queue is empty\n";
            return -1; // or throw an exception
        }
        return arr[start];
    }
    
    bool isEmpty(){
        return currsize==0;
    }
};

int main() {
	// your code goes here
	Queue q(3);
	
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << "Is empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
	cout<<q.top()<<endl;
	q.pop();
	cout<<q.top()<<endl;
}
