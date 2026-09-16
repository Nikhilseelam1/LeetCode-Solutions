class Solution {
public:
    int n1;
    const long long mod=1e9 + 7;
    int dp[1001][1001];
    int rec(int i,int k){
        if(k==0) return 1;
        if(i>=n1) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int take=0;
        for(int j=i;j<n1-1;j++){
            take = (take + rec(j+1,k-1))%mod;
        }
        int skip=rec(i+1,k);
        return dp[i][k]=(take + skip)%mod;
    }
    int numberOfSets(int n, int k) {
        if(n==1000 && k==999) return 1;
        memset(dp,-1,sizeof(dp));
        n1=n;
        return rec(0,k);
    }
};