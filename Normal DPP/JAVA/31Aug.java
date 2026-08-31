/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        if(head==null || head.next==null || head.next.next==null)
        return new int []{-1,-1};
       ListNode p=head.next;
       int first=-1;
       int last=-1;
       int mn =1000000000+7;
       ListNode prev=head;
       int prev_count=1;
        int count =1;
       while(p.next!=null){
        ListNode nxt=p.next;
        if((p.val> nxt.val && p.val > prev.val) || (p.val<nxt.val && p.val < prev.val))
        {
            if(first==-1)
            first=count;
            else
            mn =Math.min(mn , count -prev_count);
             prev_count=count ;
             last=count;
        }
             prev=p;
             p=p.next;
            count++;
       }
       return mn==1000000000+7 ? new int[]{-1,-1}:new int []{mn, last-first};

    }
}
