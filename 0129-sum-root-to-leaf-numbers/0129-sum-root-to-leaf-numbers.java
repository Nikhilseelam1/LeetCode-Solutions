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
    int ans;
    public void back(TreeNode root,int sum){
        if(root.left==null && root.right==null){
            ans+=sum;
            return ;
        }else{
            TreeNode node=root;
            if(node.left!=null) back(node.left,sum*10+node.left.val);
            if(node.right!=null) back(node.right,sum*10+node.right.val);
        }
    }
    public int sumNumbers(TreeNode root) {
        ans=0;
        back(root,root.val);
        return ans;
    }
}