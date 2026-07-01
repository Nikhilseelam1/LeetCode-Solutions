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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp=head;
        if(temp.next==null) return null;
        int c=0;
        while(temp!=null){
            c++;
            temp=temp.next;
        }
        temp=head;
        int x=c-n;
        int i=0;
        ListNode prev=null;
        while(temp!=null && i<x){
            prev=temp;
            temp=temp.next;
            i++;
        }
        if(prev==null) return head.next;
        prev.next=temp.next;
        return head;
    }
}