Node *firstNode(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    do{
        if(fast && fast->next)fast = fast->next->next;
        else return NULL;
        slow = slow->next;
    }while(fast!=slow);

    fast = head;

    while(fast && slow && fast != slow){
        fast = fast->next;
        slow = slow->next;
    }

    if(fast == slow) return fast;
    return NULL;
}