Node* findIntersection(Node *firstHead, Node *secondHead)
{
    // find len of both
    Node *f = firstHead;
    Node *s = secondHead;

    int l1 = 0;
    int l2 = 0;

    while(f){
        l1++;
        f=f->next;
    }

    while(s){
        l2++;
        s=s->next;
    }

    f = firstHead;
    s = secondHead;

    if(l1 > l2){
        int diff = l1-l2;
        for(int i = 0 ; i < diff; i++) f=f->next;
    }else if(l2 > l1){
            int diff = l2-l1;
            for(int i = 0 ; i < diff; i++) s=s->next;
    }

    while(f && s){
        if(f == s) return s;
        f = f->next;
        s = s->next;
    }

    return nullptr;
}