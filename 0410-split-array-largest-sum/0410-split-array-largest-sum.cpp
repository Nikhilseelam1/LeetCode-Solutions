class Solution {
public:
    int n;
    vector<vector<long long>>dp;
    int splitArray(vector<int>& nums, int k) {
        n=nums.size();
        dp.assign(n+1,vector<long long>(k+1,LLONG_MAX));
        dp[n][0]=0;
        for(int i=n;i>=0;i--){
            for(int k1=1;k1<=k;k1++){
                long long sum=0;
                // dp[i][k1]=0;
                for(int j=i;j<n;j++){
                    sum=sum+(long long)nums[j];
                    long long ft=dp[j+1][k1-1];
                    if(ft!=LLONG_MAX) dp[i][k1]=min(dp[i][k1],max(sum,ft));
                }
            }
        }
        return dp[0][k];
        
    }
};