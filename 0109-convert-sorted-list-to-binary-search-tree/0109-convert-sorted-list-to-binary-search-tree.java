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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode solve( ListNode node)
    {
        if(node==null) return null;
        if(node.next==null) return new TreeNode(node.val);
        ListNode fast=node,slow=node,prev=null;
        while(fast!=null && fast.next!=null)
        {
            prev=slow;
            fast=fast.next.next;
            slow=slow.next;
        }
        prev.next=null;
        TreeNode mid=new TreeNode(slow.val);
        mid.right=solve(slow.next);
        mid.left=solve(node);
        return mid;
    }
    public TreeNode sortedListToBST(ListNode head) {
         return solve(head);
    }
}