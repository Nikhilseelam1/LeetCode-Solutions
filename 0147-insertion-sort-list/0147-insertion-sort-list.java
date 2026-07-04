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
    public ListNode sort(ListNode head){
        if(head==null || head.next==null) return head;
        ListNode slow=head;
        ListNode fast=slow.next;
        while(fast!=null && fast.next!=null){
            fast=fast.next.next;
            slow=slow.next;
        }
        ListNode se=slow.next;
        slow.next=null;
        ListNode left=sort(head);
        ListNode right=sort(se);
        return merge(left,right);
    }
    public ListNode merge(ListNode left,ListNode right){
        ListNode d=new ListNode(-1);
        ListNode temp=d;
        while(left!=null && right!=null){
            if(left.val<=right.val){
                temp.next=left;
                left=left.next;
            }else{
                temp.next=right;
                right=right.next;
            }
            temp=temp.next;
        }
        if(left!=null){
            temp.next=left;
        }else{
            temp.next=right;
        }
        return d.next;
    }
    public ListNode insertionSortList(ListNode head) {
        return sort(head);
    }
}