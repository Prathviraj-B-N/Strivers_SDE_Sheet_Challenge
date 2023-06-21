#include <bits/stdc++.h> 
class Queue {

private:
    int front_ptr = -1;
    int back  = -1;
    int *q;
    int size = 1;

public:
    Queue() {
        q = new int[size];
        front_ptr = 0;
        back = 0;
    }

    bool isEmpty() {
        return front_ptr == back;
    }

    void enqueue(int data) {
        if(back == size-1) resize();
        q[back++] = data;
    }

    int dequeue() {
        if(isEmpty()) return -1;
        return q[front_ptr++];
    }

    int front() {
        if(isEmpty()) return -1;
        return q[front_ptr];
    }

    void resize(){
        int oldSize = size;
        size = size << 1;
        int *temp = new int[size];
        int i;
        for(i = 0; i < oldSize ; i++){
            temp[i] = q[i];
        }
        int *del = q;
        q = temp;
        free(del);
        del = nullptr;
    }
};