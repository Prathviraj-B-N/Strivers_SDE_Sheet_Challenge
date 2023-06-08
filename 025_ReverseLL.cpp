#include <bits/stdc++.h>

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(!head || !head->next) return head;

    LinkedListNode<int> *prev = nullptr;
    LinkedListNode<int> *cur = head;
    LinkedListNode<int> *next = head->next;

    while(cur){
        cur->next = prev;
        prev = cur;
        cur = next;
        if(next)next = cur->next;
    }

    return prev;

}