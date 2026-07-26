class Solution {
    int n;
    int [][]dp;
    int rec(int i,int []nums,int k){
        if(k==0 && i==n) return 0;
        if(k==0 || i==n) return Integer.MAX_VALUE;
        if(dp[i][k]!=-1) return dp[i][k];
        int ans=Integer.MAX_VALUE;
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            int ft=rec(j+1,nums,k-1);
            ans=Math.min(ans,Math.max(sum,ft));
        }
        dp[i][k]=ans;
        return ans;
    }
    public int splitArray(int[] nums, int k) {
        n=nums.length;
        dp=new int[n+1][k+1];
         for (int i = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        return rec(0,nums,k);
    }
}