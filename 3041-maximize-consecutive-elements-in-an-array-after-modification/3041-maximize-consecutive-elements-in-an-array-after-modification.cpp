class Solution {
public:
    int n;
    int find(vector<int>&nums,int s,int t)
    {
        int j=lower_bound(nums.begin()+s,nums.end(),t)-nums.begin();
        if(j<n && nums[j]==t) return j;
        return -1;
    }
    int dp[100004][2];
    int rec(int i,int inc,vector<int>&nums){
        if(i==n) return 0;
        if(dp[i][inc]!=-1) return dp[i][inc];
        int curr=nums[i]+inc;
        int res=1;
        int j=find(nums,i+1,curr+1);
        if(j!=-1){
            res=max(res,1+rec(j,0,nums));
        }
        j=find(nums,i+1,curr);
        if(j!=-1){
            res=max(res,1+rec(j,1,nums));
        }
        return dp[i][inc]=res;
    }
    int maxSelectedElements(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        int res=1;
        for(int i=0;i<n;i++){
            res=max(res,max(rec(i,0,nums),rec(i,1,nums)));
        }
        return res;
    }
};