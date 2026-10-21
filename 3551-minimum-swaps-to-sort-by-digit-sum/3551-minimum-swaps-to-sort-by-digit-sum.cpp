class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int>&arr){
        vis[node]=1;
        int i=arr[node];
        if(!vis[i]){
            dfs(i,vis,arr);
        }
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        vector<pair<int,int>>vec,vec1;
        for(int i=0;i<n;i++)
        {
            vec.push_back({nums[i],i});
            int x=nums[i];
            int res=0;
            while(x>0)
            {
                res+=x%10;
                x=x/10;
            }
            vec1.push_back({nums[i],res});
        }
        sort(vec1.begin(),vec1.end(),[&](const auto &a,const auto &b){
            if (a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[vec1[i].first]=i;
        }
        vector<int>arr;
        for(int i=0;i<n;i++){
            arr.push_back(mp[nums[i]]);
        }
        for(int it:arr) cout<<it<<" ";
        vector<int>vis(n,0);
        int nik=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                nik++;
                dfs(i,vis,arr);
            }
        }
        return n-nik;

    }
};