class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=l.size();
        vector<bool>ans(n,true);
        for(int i=0;i<n;i++){
            int left=l[i];
            int right=r[i];
            int maxi=*max_element(nums.begin()+left,nums.begin()+right+1);
            int mini=*min_element(nums.begin()+left,nums.begin()+right+1);
            if ((maxi - mini) % (right - left) != 0) {
                ans[i] = false;
                continue;
            }
            int diff = (maxi - mini) / (right - left);
            if(diff == 0) continue;
            set<int>st;
            for(int j=left;j<=right;j++) st.insert(nums[j]);
            for(int j=0;j<=right-left;j++){
                int x=mini+j*diff;
                if(st.find(x)==st.end()){
                    ans[i]=false;
                    break;
                }
            }
        }
        return ans;
    }
};