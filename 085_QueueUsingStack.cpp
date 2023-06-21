#include<stack>
class Queue {
    stack<int> st1;
    stack<int> st2;

    public:
    Queue() {}

    void enQueue(int val) {
        st1.push(val);
    }

    int deQueue() {
        if(!st1.size()) return -1;
        while(st1.size()>1){
            st2.push(st1.top());
            st1.pop();
        }
        
        int ele = st1.top();
        st1.pop();

        while(st2.size()){
            st1.push(st2.top());
            st2.pop();
        }

        return ele;
    }

    int peek() {
        
        if(!st1.size()) return -1;
        while(st1.size()>1){
            st2.push(st1.top());
            st1.pop();
        }
        
        int ele = st1.top();

        while(st2.size()){
            st1.push(st2.top());
            st2.pop();
        }

        return ele;
    }

    bool isEmpty() {
        return 0 == st1.size();
    }
};