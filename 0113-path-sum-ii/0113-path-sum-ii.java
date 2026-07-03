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
    int ta;
    public void back(List<List<Integer>>list,List<Integer>l,TreeNode root,int sum){
        // if(root==null) return ;
        // if(sum>ta) return ;
        if(root.left==null && root.right==null){
            if(sum==ta) list.add(new ArrayList<>(l));
            return ;
        }else{
            TreeNode temp=root;
            if(temp.left!=null){
                l.add(temp.left.val);
                back(list,l,temp.left,sum+temp.left.val);
                l.remove(l.size()-1);
            }
            if(temp.right!=null){
                l.add(temp.right.val);
                back(list,l,temp.right,sum+temp.right.val);
                l.remove(l.size()-1);
            }
        }
    }
    public List<List<Integer>> pathSum(TreeNode root, int t) {
        List<List<Integer>>list=new ArrayList<>();
        List<Integer>l=new ArrayList<>();
        if(root==null) return list;
        ta=t;
        l.add(root.val);
        back(list,l,root,root.val);
        return list;
    }
}