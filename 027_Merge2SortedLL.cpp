#include <bits/stdc++.h>

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(!first) return second;
    if(!second) return first;

    Node<int>* ans = new Node<int>(0);
    Node<int>* temp = ans;

    while(first && second){

        if(first->data <= second->data){
            temp->data = first->data;
            first = first->next;
        }else{
            temp->data = second->data;
            second = second->next;
        }
        if (first && second) {
          temp->next = new Node<int>(0);
          temp = temp->next;
        }
    }

    if(first){
        temp->next = first;
    }

    if(second){
      temp->next = second;
    }
    
    return ans;

}