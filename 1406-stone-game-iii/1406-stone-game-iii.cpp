class Solution {
public:
    int n;
    int dp[50001][2];
    int rec(int i,bool a_b,vector<int>&p){
        if(i>=n){
            return 0;
        }
        if(dp[i][a_b]!=-1) return dp[i][a_b];
        int res=a_b?-1e9:1e9;
        int t=0;
        for(int l=1;l<=3;l++){
            if(i+l>n) break;
            t+=p[i+l-1];
            if(a_b){
                res=max(res,t+rec(i+l,!a_b,p));
            }else{
                res=min(res,rec(i+l,!a_b,p));
            }
        }
        dp[i][a_b]=res;
        return res;
    }
    string stoneGameIII(vector<int>& p) {
        n=p.size();
        int t=accumulate(p.begin(),p.end(),0);
        memset(dp,-1,sizeof(dp));
        int x=rec(0,1,p);
        int x1=t-x;
        if(x>x1)
        {
            return "Alice";
        }else if(x<x1)
        {
            return "Bob";
        }else
        {
            return "Tie";
        }
    }
};