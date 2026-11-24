class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=2;
        long long product=1;
        int j=0;
        for(int i=0;i<n;i++)
        {
            while(gcd(product,nums[i]) > 1){
                product/=nums[j];
                j++;
            }
            product*=nums[i];
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};