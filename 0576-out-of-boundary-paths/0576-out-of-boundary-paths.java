class Solution {
    int n1;
    int m1;
    int mod=(int)1e9+7;
    int [][][] dp;
    int rec(int i,int j,int maxi){
        if(maxi<0) return 0;
        if(i>=n1 || j>=m1 || j<0 || i<0){
            return (maxi>=0)?1:0;
        }
        if(dp[i][j][maxi]!=-1) return dp[i][j][maxi];
        int ans=0;
        ans=(ans + rec(i,j+1,maxi-1))%mod;
        ans=(ans + rec(i,j-1,maxi-1))%mod;
        ans=(ans + rec(i-1,j,maxi-1))%mod;
        ans=(ans + rec(i+1,j,maxi-1))%mod;
        dp[i][j][maxi]=ans%mod;
        return ans%mod;
    }
    public int findPaths(int m, int n, int maxi, int sr, int sc) {
        n1=m;
        m1=n;
        dp=new int [51][51][51];
        for(int i=0;i<=50;i++){
            for(int j=0;j<=50;j++){
                for(int k=0;k<=50;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        return rec(sr,sc,maxi);
    }
}