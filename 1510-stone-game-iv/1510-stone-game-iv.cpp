class Solution {
public:
    int dp[100005][2];
    bool rec(int n,bool f){
        if(n==0) return f?false:true;
        if(dp[n][f]!=-1) return dp[n][f];
        if(f){
            bool x=false;
            for(int i=1;i*i<=n;i++){
             x=x || rec(n-i*i,false);
            }   
            return dp[n][f]=x;
        }else
        {
            bool x=true;
            for(int i=1;i*i<=n;i++){
             x=x && rec(n-i*i,true);
            }
            dp[n][f]=x;
            return x;
        }
        return true;
    }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(n,true);
    }
};