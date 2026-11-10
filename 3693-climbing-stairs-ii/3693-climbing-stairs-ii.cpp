class Solution {
public:
    int m;
    // int dp[100005];
    // int rec(int i,vector<int>&cost)
    // {
    //     if(i>m) return INT_MAX/2; 
    //     if(i==m) return cost[m];
    //     if(dp[i]!=-1) return dp[i];
    //     int ans=cost[i] + min({rec(i+1,cost)+1,rec(i+2,cost)+4,rec(i+3,cost)+9});
    //     return dp[i]=ans;
    // }
    int climbStairs(int n, vector<int>& costs) {        
        costs.insert(costs.begin(), 0);
        m = n;
        vector<int> dp(m+1, 1e9);
        dp[0] = 0;
        for(int i = 1; i <= m; i++) {
            int ans = 1e9;
            if(i-1 >= 0) ans = min(ans, dp[i-1] + 1);
            if(i-2 >= 0) ans = min(ans, dp[i-2] + 4);
            if(i-3 >= 0) ans = min(ans, dp[i-3] + 9);
            dp[i] = costs[i] + ans;
        }
        return dp[m];
    }
};