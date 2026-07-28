class Solution {
public:
    int dp[10005];
    int rec(int i,vector<int>&nums){
        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=nums.size();
        for(int j=1;j<=nums[i];j++){
            ans=min(1 + rec(i+j,nums),ans);
        }
        // cout<<ans<<" ";
        dp[i]=ans;
        return ans;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
      return rec(0,nums);
    }
};