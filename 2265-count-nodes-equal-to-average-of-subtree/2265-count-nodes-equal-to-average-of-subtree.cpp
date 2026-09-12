/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    pair<int,int>rec(TreeNode* root){
        if(!root) return {0,0};
        pair<int,int>left=rec(root->left);
        pair<int,int>right=rec(root->right);
        int x=left.first + right.first + root->val;
        int c=left.second + right.second + 1;
        if(x/c == root->val){
            ans=ans+1;
        }
        return {x,c};
    }
    int averageOfSubtree(TreeNode* root) {
        ans=0;
        rec(root);
        return ans;
    }
};