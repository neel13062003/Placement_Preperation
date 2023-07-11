https://leetcode.com/problems/implement-queue-using-stacks/
************************************

class MyQueue {
public:
    
    stack<int> input,output;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        //int value=output.top();   give error some time if outputtop is empty
        int value=peek();
        output.pop();
        return value;
    }
    
    int peek() {
         if(output.empty()){
            while(input.empty() == false){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */









************************************************
#include <bits/stdc++.h> 
class Queue{
    // Stacks to be used in the operations.
    stack<int> st1, st2;
    
    public:
    // Enqueues 'X' into the queue. Returns true after enqueuing.
    bool enqueue(int X){
        st1.push(X);
    }

     bool empty() {
        return st1.empty() && st2.empty();
    }


    /*
      Dequeues top element from queue. Returns -1 if the queue is empty, 
      otherwise returns the popped element.
    */
    int dequeue(){
        if (empty())
            return -1;
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int ans = st2.top();
        st2.pop();
        return ans;
    }
};