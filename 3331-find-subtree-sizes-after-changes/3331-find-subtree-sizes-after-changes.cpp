class Solution {
public:
    vector<vector<int>>adj,new_adj;
    vector<int>ans,last;
    int n;
    void build(int node,string &s){
        int c=(unsigned char)s[node];
        int prev=last[(unsigned char)s[node]];
        last[c]=node;
        for(int x:adj[node]){
            int p=last[(unsigned char)s[x]];
            if(p==-1) p=node;
            new_adj[p].push_back(x);
            build(x,s);
        }
        last[c]=prev;
    }
    int dfs(int node){
        int z=1;
        for(auto it:new_adj[node]){
            z+=dfs(it);
        }
        ans[node]=z;
        return z;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        n=parent.size();
        last.assign(150,-1);
        ans.assign(n,1);
        adj.assign(n,{});
        new_adj.assign(n,{});
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        build(0,s);
        dfs(0);
        return ans;
    }
};