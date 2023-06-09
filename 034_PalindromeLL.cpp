// O(3n/2) = O(1.5 * n) = O(n)
#include <bits/stdc++.h> 

bool isPalindrome(LinkedListNode<int> *head) {
    if(!head || !head->next) return true;

    LinkedListNode<int>* fast = head->next;
    LinkedListNode<int>* slow = head;

    // O(n/2)
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    LinkedListNode<int> *prev = nullptr;
    LinkedListNode<int> *cur = slow->next;
    LinkedListNode<int> *next = cur->next;

    // + O(n/2)
    while(cur){
        cur->next = prev;
        prev = cur;
        cur = next;
        if(cur)next = cur->next;
    }

    slow->next = prev;
    slow = slow->next;
    
    // + O(n/2)
    while(slow && slow->data == head->data){
        slow = slow->next;
        head = head->next;
    }

    if(!slow) return true;
    return false;

}