class Solution {
public:
    string s1;
    string t1;
    int dp[1001][1001];
    int rec(int i,int j){
        if(j==t1.size()){
            return 1;
        }
        if(i==s1.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int t=0;
        if(s1[i]==t1[j]){
            t=rec(i+1,j+1);
        }
        int no=rec(i+1,j);
        return dp[i][j]=t+no;
    }
    int numDistinct(string s, string t) {
        s1=s;
        t1=t;
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};