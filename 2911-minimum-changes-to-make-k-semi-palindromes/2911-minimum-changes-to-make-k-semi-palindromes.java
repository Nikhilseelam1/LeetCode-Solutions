class Solution {
    int n;
    public int cost(int start,int end,String s){
        int len=end-start+1;
        int mini=Integer.MAX_VALUE;
        for(int d=1;d<len;d++){
            if(len%d!=0) continue;
            int cost=0;
            for(int g=0;g<d;g++){
                int l=start+g;
                int r=l+(len/d - 1)*d;
                while(l<r){
                    if(s.charAt(l) != s.charAt(r)) cost++;
                    l+=d;
                    r-=d;
                }
                
            }
            mini=Math.min(mini,cost);
        }
        // System.out.println(mini + " " + start + " " + end);
        return mini;
    }
    int [][]dp;
    public int solve(String s,int start,int k){
        if(k==0)
        {
            if(start==n) return 0;
            else return Integer.MAX_VALUE;
        }
        if (n - start < k) return Integer.MAX_VALUE;
        if(dp[start][k]!=-1) return dp[start][k];
        int mini=Integer.MAX_VALUE;
        for(int e=start+1;e<n;e++)
        {
            int rem=solve(s,e+1,k-1);
            if (rem != Integer.MAX_VALUE) {
                mini=Math.min(mini,cost(start,e,s) + rem);
            }
        }
        return dp[start][k]=mini;
    }
    public int minimumChanges(String s, int k) {
        n=s.length();
        dp=new int [n+1][k+1];
        for(int []row:dp){
            Arrays.fill(row,-1);
        }
        return solve(s,0,k);
    }
}