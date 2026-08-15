class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int it:nums) mp[it]=1;
        int xorr=nums[0];
        for(int i=1;i<n;i++){
            xorr=xorr^nums[i];
        }
        if(mp.size()==1 && nums[0]==0 && xorr==0) return 0;
        return xorr==0?n-1:n;
    }
};