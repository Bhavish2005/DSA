class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* dummy =new ListNode (-1);
        dummy->next= head;
        ListNode* prev=dummy;
         ListNode* fast=head;
         ListNode* slow=head;
            while(fast && fast->next){
                prev=prev->next;
                fast=fast->next->next;
                slow=slow->next;
            }
          prev->next=slow->next;
        return dummy->next;
    }
};
