class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto &it:mp){
            vector<int>vec=it.second;
            if(vec.size()<3){
                continue;
            }
            int gap=vec[1]-vec[0];
            bool f=true;
            for(int i=2;i<vec.size();i++){
                if(vec[i]-vec[i-1] != gap){
                    f=false;
                    break;
                }
            }
            if(f) ans++;
        }
        return ans;
    }
};