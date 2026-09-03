class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums[0]%2) return true;
        int prev=0;
        for(int i=1;i<n;i++){
            if(nums[i]%2){
                return false;
            }
        }
        return true;
    }
};