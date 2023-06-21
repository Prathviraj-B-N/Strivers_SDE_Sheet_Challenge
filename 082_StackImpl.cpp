#include <bits/stdc++.h> 
// Stack class.
class Stack {
private: 
    int *stack;
    int capacity = 0;
    int top_ptr = -1;
public:
    
    Stack(int capacity) {
        this->capacity = capacity;
        stack = new int[capacity];
    }

    void push(int num) {
        if(isFull()) return;
        stack[++top_ptr] = num;
    }

    int pop() {
        if(isEmpty()) return -1;
        return stack[top_ptr--];
    }
    
    int top() {
        if(isEmpty()) return -1;
        return stack[top_ptr];
    }
    
    int isEmpty() {
        return top_ptr == -1;
    }
    
    int isFull() {
        return top_ptr == capacity+1;
    }
    
};