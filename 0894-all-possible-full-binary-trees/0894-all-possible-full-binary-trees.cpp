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
    unordered_map<int,vector<TreeNode*>>mp;
    vector<TreeNode*> solve(int n){
        if(n%2==0) return {};
        vector<TreeNode*>ans;
        if(n==1){
            ans.push_back(new TreeNode(0));
            mp[1]=ans;
            return ans;
        }
        if(mp.count(n)) return mp[n];
        for(int i=1;i<n;i+=2){
            vector<TreeNode*>left=solve(i);
            vector<TreeNode*>right=solve(n-i-1);
            for(auto &l:left){
                for(auto &r:right){
                    TreeNode *root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        mp[n]=ans;
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};