class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        bool f=true;
        for(int i=0;i<n;i++){
            if(nums[i]!=i && ans==0 && f){
                ans=nums[i];
                f=false;
            }else if(nums[i]!=i) ans=ans & nums[i];
        }
        return ans;
    }
};