class Solution {
public:
    int n;
    int dp[101][101][101];
    int rec(int i,vector<vector<int>>&costs,int x,int x1){
        // if(x<=0) return 0;
        // if(x1<=0) ree
        if(i==n) return 0;
        if(dp[i][x][x1]!=-1) return dp[i][x][x1];
        int ans=1e9;
        if(x>0) ans=costs[i][0] +rec(i+1,costs,x-1,x1);
        int ans2=1e9;
        if(x1>0) ans2=costs[i][1] + rec(i+1,costs,x,x1-1);
        return dp[i][x][x1]=min(ans,ans2);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        memset(dp,-1,sizeof(dp));
        n=costs.size();
        return rec(0,costs,n/2,n/2);
    }
};