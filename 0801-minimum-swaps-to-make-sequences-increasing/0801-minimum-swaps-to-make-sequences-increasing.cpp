class Solution {
public:
    int n;
    int m;
    int dp[100001][2];
    int rec(int i,vector<int>&nums1,vector<int>&nums2,bool swapp){
        if(i==m) return 0;
        if(dp[i][swapp]!=-1) return dp[i][swapp];
        int prev=nums1[i-1];
        int prev1=nums2[i-1];
        if(swapp){
            swap(prev,prev1);
        }
        int ans=INT_MAX;
        if(prev<nums1[i] && prev1<nums2[i]){
            ans=rec(i+1,nums1,nums2,false);
        }
        if(prev<nums2[i] && prev1<nums1[i]){
            ans=min(ans,1+rec(i+1,nums1,nums2,true));
        }
        return dp[i][swapp]=ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        n=nums1.size();
        m=nums2.size();
        memset(dp, -1, sizeof(dp));

        int ans=rec(1,nums1,nums2,false);
        return ans;
    }
};