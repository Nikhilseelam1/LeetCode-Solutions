class Solution {
public:
    int n;
    int m;
    bool dfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis){
        if(i<0 || j<0 || i>=n || j>=m) return false;
        
        if(grid[i][j] == 1 ||  vis[i][j]) return true;
        vis[i][j]=true;
        bool left=dfs(i,j-1,grid,vis);
        bool right=dfs(i,j+1,grid,vis);
        bool up=dfs(i-1,j,grid,vis);
        bool down =dfs(i+1,j,grid,vis);
        return up && down && left && right;
    }
    int closedIsland(vector<vector<int>>& grid)
    {
        n=grid.size();
        m=grid[0].size();
        int ans =0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 || vis[i][j]) continue;
                if(dfs(i,j,grid,vis)) ans++ ;
            }
        }
        return ans;
    }
};