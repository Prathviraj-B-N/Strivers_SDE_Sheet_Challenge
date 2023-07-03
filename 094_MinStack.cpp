#include <bits/stdc++.h> 

typedef struct stack1{
	int data;
	stack1 *next = nullptr;
	stack1 *prev = nullptr;
} customStack;

class minStack
{	
	customStack *head;
	stack<customStack *> minStore;
	int size;

	public:
		minStack() 
		{ 
			head = nullptr;
			size = 0;
		}

		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			if(!head){
				head = new customStack();
				head->data = num;
            } else {
                head->next = new customStack();
                customStack *temp = head;
                temp = temp->next;
                temp->prev = head;
            	head = head->next;
				head->data = num;
            }
            
			if(minStore.empty() || num < minStore.top()->data){
				minStore.push(head);
			}
			size++;
		}
		
		int pop()
		{
			if(minStore.empty() || size <= 0) return -1;
			if(head == minStore.top()) minStore.pop();
			if(size == 1){
				int ele = head->data;
				free(head);
				head = nullptr;
				size = 0;
				return ele;
			}
			customStack *temp = head;
			int ele = head->data;
			temp = head->prev;
			free(head);
			temp->next = nullptr;
			head = temp;
			size--;
			return ele;
		}
		
		int top()
		{
			return size?head->data:-1;
		}
		
		int getMin()
		{
			return minStore.empty()?-1:minStore.top()->data;
		}
};