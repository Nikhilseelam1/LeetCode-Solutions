class Solution {
    String s;
    String s1;
    int n;
    int m;
    int [][]dp;
    public int rec(int ind,int j){
       if(j==m){
            return 0;
       }
       if(dp[ind][j]!=-1) return dp[ind][j];
       int ans=Integer.MAX_VALUE;
       for(int i=0;i<n;i++){
            if(s.charAt(i) == s1.charAt(j)){
                int cw=Math.abs(i-ind);
                int ac=n-cw;
                int mini=Math.min(cw,ac);
                ans=Math.min(mini+1+(rec(i,j+1)),ans);
            }
       }
       dp[ind][j]=ans;
       return ans;
    }
    public int findRotateSteps(String ring, String key) {
        s=ring;
        s1=key;
        n=s.length();
        m=s1.length();
        dp=new int[101][101];
        for(int i=0;i<100;i++){
            Arrays.fill(dp[i],-1);
        }
        return rec(0,0);
    }
}