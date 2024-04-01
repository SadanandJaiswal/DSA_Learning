#include<bits/stdc++.h>
using namespace std;

class Queue{
    private:
       int * arr;
       int front, rear, count, n = 100;
    public:
        Queue(){
            arr = new int[n];
            front = -1;
            rear = -1;
            count =0;
        }

        ~Queue() {
            delete[] arr;
        }

        void push(int num){
            if(count==n){
                cout<<"Queue Overflow"<<endl;
                exit(1);
            }
            if(rear == -1)
            {
                rear = 0;
                front = 0;
            }else{
                rear = (rear+1) % n;
                arr[rear] = num;
                count++;
            }
        }

        void pop(){
            if(count==0){
                cout<<"Queue Underflow"<<endl;
            }
            if(count==1){
                front = -1;
                rear = -1;
            }else{
                front = (front+1) % n;
                count--;
            }
        }

        int top(){
            if(count==0){
                cout<<"Queue is Empty"<<endl;
                exit(1);
            }
            return arr[front];
        }

        int size(){
            return count;
        }
};
