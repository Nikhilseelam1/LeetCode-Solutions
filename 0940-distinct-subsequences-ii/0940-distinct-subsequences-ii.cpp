class Solution {
public:
    string s1;
    int n;
    int dp[2001];
    const int mod=1e9+7;
    vector<int>prev;
    vector<int>last;
    int solve(int i){
        if(i<0) return 0;
        if(i==0) return 1;
        if(dp[i]!=-1) return dp[i];
        int t=(2*(solve(i-1))%mod)%mod;
        int dup=0;
        if(prev[i]!=0){
            dup=(solve(prev[i]-1))%mod;
            t=(t-dup + mod)%mod;
        } 
        return dp[i]=(t)%mod;
    }
    int distinctSubseqII(string s) {
        s1=s;
        n=s.size();
        prev.resize(n+1,0);
        last.resize(26,0);
        for(int i=1;i<=n;i++){
            int ind=s[i-1]-'a';
            prev[i]=last[ind];
            last[ind]=i;
        }
        memset(dp,-1,sizeof(dp));
        return (solve(n)-1 + mod)%mod;
    }
};