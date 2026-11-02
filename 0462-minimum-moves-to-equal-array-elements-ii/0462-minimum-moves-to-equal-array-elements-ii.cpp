class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int x=nums[n/2];
        int ans=0;
        for(int it:nums){
            ans+=abs(x-it);
        }
        return ans;
    }
};