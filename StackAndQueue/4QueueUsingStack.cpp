#include<bits/stdc++.h>
using namespace std;

class QueueUsingStack{
    private:
        stack<int> S1;
        stack<int> S2;
    
    public:
        void push(int num){
            S2 = S1;
            S1.push(num);
            while(!S2.empty()){
                S1.push(S2.top());
                S2.pop();
            }
        }

        int pop(){
            if(S1.empty()){
                cout<<"Queue is Empty"<<endl;
                return -1;
            }
            return S1.top();
        }
};

// Time Complexity: O(N)


// optimise code
// Time Complexity: push-> O(1); rest O(N);
class QueueUsingStackOptimize{
    private: 
        stack<int> input;
        stack<int> output;
    
    public:
        void push(int num){
            input.push(num);
        }

        void pop(){
            if(output.empty()){
                while(!input.empty()){
                    output.push(input.top());
                    input.pop();
                }
            }
            output.pop();
        }

        int top(){
            if(output.empty()){
                while(!input.empty()){
                    output.push(input.top());
                    input.pop();
                }
            }
            return output.top();
        }

        int size(){
            return input.size() + output.size();
        }
};