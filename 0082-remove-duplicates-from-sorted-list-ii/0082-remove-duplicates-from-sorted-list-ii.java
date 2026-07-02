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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode temp=head;
        ListNode prev=head;
        HashMap<Integer,Integer>mp=new HashMap<>();
        while(temp!=null){
            mp.put(temp.val,mp.getOrDefault(temp.val,0)+1);
            temp=temp.next;
        }
        temp=head;
        boolean f1=false;
        while(temp!=null && temp.next!=null){
             int v=mp.get(temp.val);
             int c=v;
             boolean f=false;
             while(temp!=null && v>1 && c>0){
                if(temp.val==head.val) f1=true;
                temp=temp.next;
                c--;
                f=true;
             }
             if(f1==true){
                f1=false;
                head=temp;
             }
             if(f==false){
                prev=temp;
                temp=temp.next;
             }else{
                prev.next=temp;
             }
        }
        return head;
    }
}