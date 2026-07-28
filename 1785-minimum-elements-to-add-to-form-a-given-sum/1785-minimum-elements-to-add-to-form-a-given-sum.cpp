class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum=0;
        for(int it:nums) sum+=it;
        double ans=abs(sum-goal);
        return ceil(ans/(double)limit);
    }
};