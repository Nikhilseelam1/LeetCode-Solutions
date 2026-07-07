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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Queue<TreeNode>q=new LinkedList<>();
        List<List<Integer>>list=new ArrayList<>();
        List<Integer>x=new ArrayList<>();
        if(root==null) return list;
        x.add(root.val);
        list.add(x);
        boolean f=true;
        q.offer(root);
        while(!q.isEmpty()){
            int n=q.size();
            List<Integer>l=new ArrayList<>();
            while(n>0)
            {
                n--;
                TreeNode node=q.poll();
                if(node.left!=null){
                    l.add(node.left.val);
                    q.offer(node.left);
                }
                if(node.right!=null){
                    l.add(node.right.val);
                    q.offer(node.right);
                }
            }
            if(f){
                Collections.reverse(l);
            }
            f=!f;
            list.add(l);
        }
        list.remove(list.size()-1);
        return list;
    }
}