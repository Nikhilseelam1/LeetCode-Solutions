class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int it:arr) mp[it]++;
        vector<pair<int,int>>vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),[](auto &a,auto & b){
            return a.second>b.second;
        });
        int n=arr.size();
        int ans=0;
        int c=0;
        for(auto it:vec){
            c++;
            int x=it.second;
            ans+=x;
            if(ans>=n/2) break;
        }     
        return c;
    }
};