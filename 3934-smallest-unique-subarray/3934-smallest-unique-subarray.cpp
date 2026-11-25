class Solution {
public:
    int n;
    bool check(int m,vector<int>&nums)
    {
        unordered_map<long long,int>mp;
        long long base=1000003;
        long long mod=1e9+7;
        long long hash=0;
        long long power=1;
        for(int i=0;i<m;i++){
            hash=((hash * base)%mod + nums[i])%mod;
        }   
        mp[hash]++;
        for(int i=1;i<m;i++){
            power = (power * base)%mod; 
        }

        for(int i=m;i<n;i++)
        {
            hash = (hash - (nums[i-m]*1LL*power)%mod + mod)%mod;
            hash = ((hash * base)%mod + nums[i])%mod;
            mp[hash]++;
        }
        for(auto [x,y]:mp)
        {
            if(y == 1) return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums){
        n=nums.size();
        int high=n;
        int low=1;
        int ans=n;
        while(low<=high){
            int mid=low + (high-low)/2;
            if(check(mid,nums)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};