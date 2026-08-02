class Solution {
public:
    int dp[21][21][2];
    int rec(int i,int j,vector<int>&nums,bool f){
        if(i==j) return dp[i][j][f]=nums[i];
        long long ans=0;
        long long ans2=LLONG_MAX;
        if(dp[i][j][f]!=-1) return dp[i][j][f];
        if(f){
            ans=max(1LL*nums[i] + rec(i+1,j,nums,false), 1LL*nums[j] + rec(i,j-1,nums,false));
            dp[i][j][f]=ans;
            return ans;
        }else{
            ans2=min(rec(i+1,j,nums,true),rec(i,j-1,nums,true));
            dp[i][j][f]=ans2;
            return ans2;
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        memset(dp,-1,sizeof(dp));
        long long x=rec(0,n-1,nums,true);
        long long sum=0;
        for(int it:nums){
            sum+=it;
        }
        if(x>=(sum-x)) return true;
        return false;
    }
};