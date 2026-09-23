struct Node{
    long long count[5];
    long long prod=0;
    };
class SegmentTree{
public:
    int n;
    int k;
    vector<Node>tree;
    SegmentTree(vector<int>nums,int k){
        this->n=nums.size();
        tree.resize(4*n+5,Node());
        this->k=k;
        build(0,0,n-1,nums);
    }
    Node merge(Node left,Node right){
        Node res;
        res.prod=(left.prod % k  *  right.prod % k)%k ;
        for(int i=0;i<k;i++){
            res.count[i]=left.count[i];
        }
        for(int i=0;i<k;i++){
            int newrem= (i * left.prod)%k;
            res.count[newrem] += right.count[i]; 
        }
        return res;
    }
    void LeafNode(int i,int val){
        for(int j=0;j<k;j++){
            tree[i].count[j]=0;
        }
        tree[i].count[val%k]=1;
        tree[i].prod=val%k;
    }
    void build(long long node,int l,int r,vector<int>&nums){
        if(l==r){
            LeafNode(node,nums[l]);
            return ;
        }
        int mid=l + (r-l)/2;
        build(2*node+1,l,mid,nums);
        build(2*node+2,mid+1,r,nums);
        tree[node]=merge(tree[2*node+1],tree[2*node+2]);
    }
    void updateTree(long long node,int l,int r,int ind,int val){
        if(l==r){
            LeafNode(node,val);
            return ;
        }
        int mid=l + (r-l)/2;
        if(ind<=mid){
            updateTree(2*node+1,l,mid,ind,val);
        }else{
            updateTree(2*node+2,mid+1,r,ind,val);
        }
        tree[node]=merge(tree[2*node+1],tree[2*node+2]);
    }
    Node queryTree(long long node,int s,int e,int l,int r){

        if(l>=s && r<=e){
            return tree[node];
        }
        int mid= l+ (r-l)/2;
        if(e<=mid){
            return queryTree(2*node+1,s,e,l,mid);
        }
        if(s>mid){
            return queryTree(2*node+2,s,e,mid+1,r);
        }
        Node left=queryTree(2*node+1,s,e,l,mid);
        Node right=queryTree(2*node+2,s,e,mid+1,r);
        return merge(left,right);
    }
    void update(int ind,int val){
        updateTree(0,0,n-1,ind,val);
    }
    Node query(int l,int r){
        return queryTree(0,l,r,0,n-1);
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& q) {
        int n=nums.size();
        int m=q.size();
        vector<int>res;
        SegmentTree tree(nums,k);
        for(int i=0;i<m;i++){
            tree.update(q[i][0],q[i][1]);
            Node ans=tree.query(q[i][2],n-1);
            res.push_back(ans.count[q[i][3]]);
        }
        return res;
    }
};