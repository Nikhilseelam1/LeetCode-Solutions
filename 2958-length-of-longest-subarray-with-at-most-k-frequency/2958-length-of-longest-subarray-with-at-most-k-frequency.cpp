class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int j=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(mp[nums[i]]>k){
                mp[nums[j]]--;
                if(mp[nums[j]]==0) mp.erase(nums[j]);
                j++;
            }
            maxi=max(maxi,i-j+1);
        } 
        return maxi;
    }
};