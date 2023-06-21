#include <bits/stdc++.h> 
class Stack {
   private:
    queue<int> q1;
    queue<int> q2;
   
   public:
    Stack() {
    }

    int getSize() {
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q1.size() == 0;
    }

    void push(int element) {
        q1.push(element);
    }

    int pop() {
        if(!q1.size()) return -1;

        while(q1.size()>1){
            q2.push((int)q1.front());
            q1.pop();
        }

        int ele = q1.front();
        q1.pop();

        while(q2.size()){
            q1.push((int)q2.front());
            q2.pop(); 
        }

        return ele;

    }

    int top() {
        if(!q1.size()) return -1;
        return q1.back();
    }
};