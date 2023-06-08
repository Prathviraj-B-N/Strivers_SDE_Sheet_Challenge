
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* num1, ListNode* num2) {
        int carry = 0;
        ListNode* ans = new ListNode();
        ListNode* temp = ans;

        while(num1 && num2){
            int sum = num1->val + num2->val + carry;
            carry = (sum > 9)?1:0;

            temp->val = (sum > 9)?(sum%10):sum;
            
            num1 = num1->next;        
            num2 = num2->next;
            
            if (num1 && num2) {
            temp->next = new ListNode(0);
            temp = temp->next;
            }

        }

        while(num1 && carry){
            int sum = num1->val + carry;
            carry = (sum > 9)?1:0;
            temp->val = (sum > 9)?9:sum;
            num1 = num1->next;
            if(num2) temp->next = new ListNode(0);
        }

        if(num1) temp->next = num1;

        while(num2 && carry){
                int sum = num2->val + carry;
                carry = (sum > 9)?1:0;
                temp->val = (sum > 9)?9:sum;
                num2 = num2->next;
                if(num2) temp->next = new ListNode(0);
        }

        if(num2) temp->next = num2;

        if(carry) temp->next = new ListNode(1);


        return ans;
    }
};