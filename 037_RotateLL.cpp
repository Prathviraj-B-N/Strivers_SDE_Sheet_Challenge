Node *rotate(Node *head, int k) {
     if(!head || !head->next || k == 0) return head;

     Node *cnt = head;
     int n = 0;
     while(cnt){cnt = cnt->next;n++;}

     Node *temp = head;     

     Node *fast = head;
     Node *slow = head;

     k = k%n;
     if(k == 0) return head;
     for(int i = 0; i<k; i++){
          fast= fast->next;
     }

     while(fast->next){
          fast = fast->next;
          slow = slow->next;
     }

     head = slow->next;
     fast->next = temp;
     slow->next = nullptr;

     return head;

}