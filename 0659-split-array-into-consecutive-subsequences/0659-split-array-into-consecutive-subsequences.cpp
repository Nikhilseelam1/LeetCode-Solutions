class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>freq,need;
        for(int it:nums) freq[it]++;
        for(int it:nums){
            if(freq[it]==0) continue;
            freq[it]--;
            if(need[it]>0){
                need[it]--;
                need[it+1]++;
            }else if(freq[it+1]>0 && freq[it+2]>0){
                freq[it+1]--;
                freq[it+2]--;
                need[it+3]++;
            }else{
                return false;
            }
        }
        return true;
    }
};