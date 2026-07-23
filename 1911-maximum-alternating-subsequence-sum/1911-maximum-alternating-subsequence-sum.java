class Solution {
    int n1;
    long [][]dp;
    long rec(int i,int f,int []nums){
        if(i==n1){
            return 0;
        }
        long ans=0;
        if(dp[i][f]!=-1) return dp[i][f];
        if(f==1){
            ans=nums[i] + rec(i+1,0,nums);
            ans=Math.max(rec(i+1,f,nums),ans);
        }else{
            ans=-nums[i] + rec(i+1,1,nums);
            ans=Math.max(ans,rec(i+1,f,nums));
        }
        dp[i][f]=ans;
        return ans;
    }
    public long maxAlternatingSum(int[] nums) {
        n1=nums.length;
        dp=new long[n1+1][2];
        for(int i=0;i<n1;i++){
            for(int j=0;j<2;j++){
                dp[i][j]=-1;
            }
        }
        return rec(0,1,nums);
    }
}