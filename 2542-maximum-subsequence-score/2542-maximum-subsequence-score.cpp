class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<long long,long long>>vec;
        
        int n=nums1.size();
        for(int i=0;i<n;i++){
            vec.push_back({nums2[i],nums1[i]});
        }
        sort(vec.rbegin(),vec.rend());
        priority_queue<long long,vector<long long>,greater<int>>pq;
        long long sum=0;
        long long ans=0;
        for(auto &[e,s]:vec){
            pq.emplace(s);
            sum+=s;
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size() == k){
                ans=max(ans,sum*1ll*e);
            }
        }
        return ans;
    }
};