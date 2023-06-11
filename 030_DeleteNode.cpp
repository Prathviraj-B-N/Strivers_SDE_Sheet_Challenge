#include <bits/stdc++.h>

void deleteNode(LinkedListNode<int> * node) {
    if(node->next) node->data = -1;
    node->data = node->next->data;
    node->next = node->next->next;
}