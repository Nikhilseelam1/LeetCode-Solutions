class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(2*n,0);
        int j=0;
        for(int i=0;i<2*n;i++){
            arr[j++]=nums[i%n];
        }
        vector<long long>pre(2*n + 1);
        for(int i=0;i<2*n;i++){
            pre[i+1]=pre[i]+(long long)arr[i];
        }
        deque<int>dq;
        dq.push_back(0);
        long long maxi=LLONG_MIN;
        for(int i=1;i<=2*n;i++){
            while(!dq.empty() && dq.front()<i-n){
                dq.pop_front();
            }
            if(!dq.empty()){
                maxi=max(maxi,pre[i]-pre[dq.front()]);
            }
            while(!dq.empty() && pre[dq.back()]>=pre[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return maxi;
    }
};