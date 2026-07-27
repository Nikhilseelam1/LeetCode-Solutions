class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
        int n1=t.size();
        unordered_map<char,int>mp;
        int maxi=0;
        for(char it:t){
            mp[it]++;
            maxi=max(maxi,mp[it]);
        }
        int k=0;
        for(auto it:mp){
            if(it.second == maxi) k++;
        }
        int ans=max((int)t.size(),(maxi-1)*(n+1) + k);
        return ans;
    }
};