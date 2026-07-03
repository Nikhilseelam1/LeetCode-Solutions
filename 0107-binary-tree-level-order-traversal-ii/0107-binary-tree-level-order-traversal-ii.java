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
 import java.util.*;
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        Queue<TreeNode>q=new LinkedList<>();
        q.offer(root);
        List<List<Integer>>list=new ArrayList<>();
        if(root==null) return list;
        while(!q.isEmpty()){
            int n=q.size();
            List<Integer>l=new ArrayList<>();
            while(n>0){
                n--;
                TreeNode node=q.poll();
                l.add(node.val);
                if(node.left!=null){
                    q.offer(node.left);
                }
                if(node.right!=null){
                    q.offer(node.right);
                }
            }
            list.add(l);
        }
        Collections.reverse(list);
        return list;
    }
}