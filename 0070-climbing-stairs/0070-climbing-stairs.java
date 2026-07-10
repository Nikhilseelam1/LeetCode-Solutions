class Solution {
    int n1;
    int []dp;
    int rec(int i){
        if(i>n1) return 0;
        if(i==n1) return 1;
        if(dp[i]!=-1) return dp[i];
        int c=0;
        c+=rec(i+1)+rec(i+2);
        dp[i]=c;
        return c; 
    }
    public int climbStairs(int n) {
        dp=new int[50];
        Arrays.fill(dp,-1);
        n1=n;
        return rec(0);
    }
}