class Solution {
public:
    int mod=(int)1e9+7;
    int dp[1001][1001];
    int rec(int n,int k){
        if(n==0){
            return 0;
        }
        if(k==0) return 1;
        if(dp[n][k]!=-1) return dp[n][k];
        long long ans=0;
        for(int i=0;i<=min(n-1,k);i++)
        {
            ans=(ans+rec(n-1,k-i))%mod;
        }
        dp[n][k]=(int)ans;
        return (int)ans;
    }
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return rec(n,k);
    }
};