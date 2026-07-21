class Solution {
    int n;
    int m;
    int [][]dp;
    int rec(int []nums,int []mu,int left,int j){
        if(left==n || j==m) return 0;
        if(dp[left][j]!=-1) return dp[left][j];
        int right=(n-1)-(j-left);
        int ans1=nums[left]*mu[j] + rec(nums,mu,left+1,j+1);
        int ans2=nums[right]*mu[j] + rec(nums,mu,left,j+1);
        dp[left][j]=Math.max(ans1,ans2);
        return Math.max(ans1,ans2);
    }
    public int maximumScore(int[] nums, int[] mu) {
        n=nums.length;
        m=mu.length;
        dp=new int [n+1][m+1];
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         dp[i][j]=-1;
        //     }
        // }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans2=0;
                if(j>=i){
                    int right=(n-1)-(j-i);
                    ans2=nums[right]*mu[j] + dp[i][j+1];
                }
                int ans1=nums[i]*mu[j] + dp[i+1][j+1];
                dp[i][j]=Math.max(ans1,ans2);
            }
        }
        return dp[0][0];
    }
}