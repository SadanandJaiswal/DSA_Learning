#include<bits/stdc++.h>
using namespace std;

class StackUsingTwoQueue{
    private:
        queue<int> Q1;
        queue<int> Q2;
    
    public:
        void push(int x){
            Q2.push(x);
            while(Q1.size() != 0) {
                Q2.push(Q1.front());
                Q1.pop();
            }
            Q1 = Q2;
            while (!Q2.empty()) {
                Q2.pop();
            }
        }

        void pop(){
            if (Q1.empty()) {
                cout << "Stack is empty, cannot pop." << endl;
                return;
            }
            Q1.pop();
        }

        int top(){
            if(Q1.size() ==0){
                cout << "Stack is empty, cannot pop." << endl;
                return -1;
            }
            return Q1.front();
        }
};

class StackUsingSingleQueue{
    private: 
        queue<int> Q;
    public:
        void push(int num){
            Q.push(num);
            int size = Q.size();
            for(int i=0; i<size-1; i++){
                Q.push(Q.front());
                Q.pop();
            }
        }

        void pop(){
            if (Q.empty()) {
                cout << "Stack is empty, cannot pop." << endl;
                return;
            }
            Q.pop();
        }

        int top(){
            return Q.front();
        }
};

int main()
{
    return 0;
}