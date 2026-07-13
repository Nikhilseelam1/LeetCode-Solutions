class Solution {
    int mod=(int)1e9+7;
    public int checkRecord(int n) {
        int [][][] dp=new int [n+1][2][3];
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                dp[n][i][j]=1;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                for(int k=2;k>=0;k--){
                    int c=0;
                    dp[i][j][k]=(dp[i][j][k]+dp[i+1][j][0])%mod;
                    if(k<2){
                        dp[i][j][k]=(dp[i][j][k]+dp[i+1][j][k+1])%mod;
                    }
                    if(j<1){
                        dp[i][j][k]=(dp[i][j][k]+dp[i+1][j+1][0])%mod;
                    }
                }
            }
        }
        return dp[0][0][0];
    }
}