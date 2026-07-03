/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        if(root==null) return null;
        Queue<Node>q=new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
            int n=q.size();
            Node first=root;
            boolean f=true;
            while(n>0){
                n--;
                Node it=q.poll();
                if(it.left!=null) q.offer(it.left);
                if(it.right!=null) q.offer(it.right);
                if(f){
                    first=it;
                    first.next=null;
                    f=false;
                }else{
                    first.next=it;
                    first=it;
                    first.next=null;
                }
            }
        }
        return root;
    }
}