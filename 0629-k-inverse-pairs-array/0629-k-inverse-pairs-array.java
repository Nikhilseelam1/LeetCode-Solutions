class Solution {
    int [][]dp;
    int mod=(int)1e9+7;
    public int kInversePairs(int n, int k) {
        dp=new int[n+1][k+1];
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                for(int h=0;h<=Math.min(i-1,j);h++){
                    dp[i][j]=(dp[i][j]+dp[i-1][j-h])%mod;
                }
            }
        }
        return dp[n][k];
    }
}