class Solution {
    int mod=(int)1e9+7;
    public int gcd(int a,int b){
       while(b!=0){
          int temp=b;
          b=a%b;
          a=temp;
       }   
    return a;}
    int n1;
    Integer [][][]dp;
    int rec(int i,int g1,int g2,int []nums){
        if(i==n1){
            if(g1!=0 && g2!=0 && g1==g2) return 1;
            return 0;
        }
        if(dp[i][g1][g2]!=null) return dp[i][g1][g2];
        int g_1=gcd(nums[i],g1);
        int g_2=gcd(nums[i],g2);
        int take1=(rec(i+1,g_1,g2,nums))%mod;
        int take2=(rec(i+1,g1,g_2,nums))%mod;
        int take3=(rec(i+1,g1,g2,nums))%mod;
        long ans=0;
        ans=(ans+take1)%mod;
        ans=(ans+take2)%mod;
        ans=(ans+take3)%mod;
        dp[i][g1][g2]=(int)(ans)%mod;
        return (int)(ans)%mod;
    }
    public int subsequencePairCount(int[] nums) {
        n1=nums.length;
        int maxi=-1;
        for(int it:nums) maxi=Math.max(maxi,it);
        dp=new Integer[n1+1][maxi+1][maxi+1];
        return rec(0,0,0,nums);
    }
}