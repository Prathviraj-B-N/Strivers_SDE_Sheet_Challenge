Node *findMiddle(Node *head) {
    if(!head || !head->next) return head;

    Node *fast = head;
    Node *slow = head;

    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }

    return slow;

}