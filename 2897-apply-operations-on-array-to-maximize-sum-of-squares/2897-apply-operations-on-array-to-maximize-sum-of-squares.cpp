class Solution {
public:

    const long long mod=1e9 + 7;
    int maxSum(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<int>count(32,0);
        for(int i=0;i<32;i++){
            for(int j=0;j<n;j++){
                if((nums[j]>>i) & 1){
                    count[i]++;
                }
            }
        }
        int ans=0;
        while(k--){
            int curr=0;
            for(int i=0;i<32;i++)
            {
                if(count[i]>0){
                    count[i]--;
                    curr|=(1<<i);
                }
            }
            ans=(ans + (curr%mod*curr%mod)%mod)%mod;
        }
        return ans;
    }
};