class Solution {
public:
    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while( fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* rev(ListNode* head){
        ListNode * curr=head;
        ListNode* prev=NULL;
        while(curr){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;

    }
    int pairSum(ListNode* head) {
      ListNode* mid=middle(head); 
      ListNode* p=rev(mid);
      ListNode* q=head;
      int ans=0;
      while(p){
        ans=max(ans,p->val+q->val);
        p=p->next;
        q=q->next;
      } 
      return ans;
    }
};
