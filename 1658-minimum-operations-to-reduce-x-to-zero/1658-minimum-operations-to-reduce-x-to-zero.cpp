class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<long long,int>mp;
        int j=0;
        long long sum=0;
        long long t=0;
        int ans=1e9;
        for(int it:nums) t+=it;
        if(t<x) return -1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mp[nums[i]]++;
            while(j<n && t-sum<x){
                mp[nums[j]]--;
                sum-=nums[j];
                if(mp[nums[j]]==0) mp.erase(nums[j]);
                j++;
            }
            if(t-sum == x){
                ans=min(ans,n-(i-j+1));
                cout<<ans<<" ";
            }
        }
        return ans==1e9?-1:ans;
    }
};