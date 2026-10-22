class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<int>diff(1e5+1,0);
        int k=k1+k2;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            diff[abs(nums1[i]-nums2[i])]++;
            mx=max({mx,nums1[i],nums2[i]});
        }
        for(int i=mx;i>=1;i--){
            int move=min(k,diff[i]);
            diff[i]-=move;
            diff[i-1]+=move;
            k-=move;
        }
        long long ans=0;
        for(int i=0;i<=mx;i++){
            if(diff[i]==0) continue;
            ans += i*1LL*i*1LL*diff[i];
        }
        return ans;
    }
};