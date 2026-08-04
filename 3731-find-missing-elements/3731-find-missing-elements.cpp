class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        vector<int>vec;
        for(int i=mini+1;i<maxi;i++){
            if(st.find(i)==st.end()){
                vec.push_back(i);
            }
        }
        return vec;
    }
};