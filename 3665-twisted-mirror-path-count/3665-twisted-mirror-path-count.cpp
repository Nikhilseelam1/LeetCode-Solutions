class Solution {
public:
    int m,n;
    int dp[501][501][2];
    const long long mod=1e9 + 7;
    int rec(int i,int j,int f,vector<vector<int>>&grid)
    {
        if(i==n-1 && j==m-1) return 1;
        if(i>=n || j>=m || i<0 || j<0) return 0;
        int ans=0;
        if(dp[i][j][f]!=-1) return dp[i][j][f];
        if(grid[i][j]==1){
            if(f) ans=(ans + (rec(i+1,j,0,grid))%mod)%mod;
            else ans=(ans + (rec(i,j+1,1,grid))%mod)%mod;
        }else{
            ans = (ans + (rec(i,j+1,1,grid))%mod)%mod;
            ans =(ans + (rec(i+1,j,0,grid))%mod)%mod;
        }
        return dp[i][j][f]=ans%mod;

    }
    int uniquePaths(vector<vector<int>>& grid) 
    {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return (rec(0,1,1,grid)%mod + rec(1,0,0,grid)%mod)%mod;
    }
};