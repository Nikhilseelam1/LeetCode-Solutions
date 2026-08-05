class Solution {
public:
    vector<bool>vis;
    void dfs(int node,vector<vector<int>>&adj){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,adj);
        }
    }
    bool dfs2(int node,vector<vector<int>>&adj){
        for(int it:adj[node]){
            if(vis[it]) return false;
            return dfs2(it,adj);
        }
        return true;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        vector<vector<int>>adj(n+1);
        for(auto it:inv){
            adj[it[0]].push_back(it[1]);
        }
        vis.resize(n+1,false);
        dfs(k,adj);
        bool f=true;
        // for(int i=0;i<n;i++){
        //     if(i==k) continue;
        //     if(!vis[i]){
        //         f=dfs2(i,adj);
        //     }
        // }
        for (auto &e : inv) {
            int u = e[0];
            int v = e[1];

            if (!vis[u] && vis[v]) {
                f = false;
                break;
            }
}
        vector<int>ans;
        if(f){
            for(int i=0;i<n;i++){
                if(!vis[i]) ans.push_back(i);
            }
        }else{
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};