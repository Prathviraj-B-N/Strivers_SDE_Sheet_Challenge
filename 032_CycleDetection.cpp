bool detectCycle(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    do{
        if(fast && fast->next)fast = fast->next->next;
        else return false;
        slow = slow->next;
    }while(fast!=slow);

    fast = head;
        
    while(fast && slow && fast != slow){
        fast = fast->next;
        slow = slow->next;
    }

    return fast == slow;
}