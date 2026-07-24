class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // HashSet<Integer>st=new HashSet<>();
        unordered_set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                st.insert(nums[i]^nums[j]);
            }
        }
        // HashSet<Integer>st1=new HashSet<>();
        unordered_set<int>st1;
        for(int it:st){
            for(int i=0;i<n;i++){
                st1.insert(nums[i]^it);
            }
        }
        return st1.size();
    }
};