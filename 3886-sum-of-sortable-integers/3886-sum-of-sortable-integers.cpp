class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int>target=nums;
        sort(target.begin(),target.end());
        int ans=0;
        vector<int>factors;
        for (int x = 1; x * x <= n; ++x) {
            if (n % x == 0) {
                factors.push_back(x);
                if (n / x != x) {
                    factors.push_back(n / x);
                }
            }
        }
    auto kmp = [](const vector<int>& nums1, const vector<int>& nums2) {
            int n = nums1.size(), m = nums2.size();
            vector<int> pi(m, 0);
            int j = 0;
            for (int i = 1; i < m; ++i) {
                while (j > 0 && nums2[i] != nums2[j]) {
                    j = pi[j - 1];
                }
                if (nums2[i] == nums2[j]) {
                    ++j;
                }
                pi[i] = j;
            }
            j = 0;
            for (int i = 0; i < n; ++i) {
                while (j > 0 && nums1[i] != nums2[j]) {
                    j = pi[j - 1];
                }
                if (nums1[i] == nums2[j]) {
                    ++j;
                }
                if (j == m) {
                    return true;
                }
            }
            return false;
        };
    auto check=[&](vector<int>&temp,vector<int>&temp1){
        vector<int>doub=temp;
        doub.insert(doub.end(),temp.begin(),temp.end());
        return kmp(doub,temp1);
    };
        for(int it:factors){
            // int it=factors[c];
            bool f=true;
            for(int i=0;i<n;i+=it){
                int r=i + it - 1;
                vector<int>temp(nums.begin()+i,nums.begin()+r+1);
                vector<int>temp1(target.begin()+i,target.begin()+r+1);
                if(!check(temp,temp1)){
                    f=false;
                    break;
                }
            }
            if(f){
                ans+=it;
            }
        }
        for(int it:factors) cout<<it<<" ";
        return ans;
    }
};