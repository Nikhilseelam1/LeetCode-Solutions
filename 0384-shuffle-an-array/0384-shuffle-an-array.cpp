class Solution {
public:
    vector<int>original,v;
    Solution(vector<int>& nums) {
        original=nums;
        v=nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        next_permutation(v.begin(),v.end());
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */