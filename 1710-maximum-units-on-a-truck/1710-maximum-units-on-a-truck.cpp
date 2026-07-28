class Solution {
public:
    int maximumUnits(vector<vector<int>>& vec, int t) {
        sort(vec.begin(),vec.end(),[](const auto &a, const auto &b){
            return a[1]>b[1];
        });
        int ans=0;
        for(auto it:vec){
            int x=it[0];
            int y=it[1];
            int mini=min(x,t);
            ans+=mini*y;
            t-=mini;
            if(t<=0) break;
        }
        return ans;
    }
};