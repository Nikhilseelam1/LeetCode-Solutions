class Solution {
    int mod=(int)1e9+7;
    Integer [][][] dp;
    int n1;
    int rec(int i,int l,int a){
        if(i==n1){
            return 1;
        }
        if(dp[i][a][l] != null) return dp[i][a][l];
        int c=0;
        c=(c+rec(i+1,0,a))%mod;
        if(l<2){
            c=(c+rec(i+1,l+1,a))%mod;
        }
        if(a<1){
            c=(c+rec(i+1,0,a+1))%mod;
        }
        dp[i][a][l]=c;
        return c%mod;
    }
    public int checkRecord(int n) {
        n1=n;
        dp=new Integer [n+1][2][3];
        return rec(0,0,0);
    }
}