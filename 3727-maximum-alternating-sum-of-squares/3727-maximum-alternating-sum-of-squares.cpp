class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0) nums[i]=nums[i]*-1;
        }
        sort(nums.begin(),nums.end());
        int i=0;
        long long ans=0;
        int j=n-1;
        while(i<=j){
            if(i==j) ans+=nums[i]*nums[i];
            ans += (nums[j]*nums[j]) - (nums[i]*nums[i]);
            i++;
            j--;
        }
        return ans;
    }
};