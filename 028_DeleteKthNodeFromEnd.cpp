Node* removeKthNode(Node* head, int k)
{
    Node *fast = head;
    Node *slow = head;
    for(int i = 0; i<= k; i++){
        fast = fast->next;
        if(fast == nullptr){
            if(i < k) return head->next;
            break;
        }
    } 

    while(fast){
        fast = fast->next;
        slow = slow->next;
    }

    Node *temp = slow->next;
    slow->next = slow->next->next;
    temp->next = nullptr;
    delete temp;

    return head;

}