/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        ListNode temp=node;
        while(temp.next!=null){
            int x=temp.next.val;
            temp.val=x;
            if(temp.next.next==null){
                temp.next=null;
                break;
            }
            temp=temp.next;
        }
    }
}