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
    public void reorderList(ListNode head) {
        if(head==null || head.next==null) return ;
        Stack<ListNode>st=new Stack<>();
        ListNode slow=head;
        ListNode fast=head;
        int c=0;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
            c++;
        }
        System.out.println(slow.val);
        ListNode temp=slow.next;
        while(temp!=null){
            st.push(temp);
            temp=temp.next;
            c++;
        }
        temp=head;
        ListNode x=head;
        while(temp!=slow && !st.isEmpty()){
            ListNode top=st.pop();
            x=temp.next;
            temp.next=top;
            top.next=x;
            temp=x;
            // System.out.println(temp.val);
        }
        if(c%2==0){
            temp.next=null;
        }else{
            temp.next=slow;
            slow.next=null;
        }
    }
}