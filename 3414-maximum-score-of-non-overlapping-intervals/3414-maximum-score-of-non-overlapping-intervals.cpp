class Solution {
public:
    struct node{
        long long sum=-1;
        vector<int>inds;
    };
    vector<vector<node>>dp;
    vector<int>nextIndex;
    int search(vector<vector<int>>&vec,int x){
        int low=0;
        int ans=-1;
        int high=vec.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(vec[mid][0]>x){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    node solve(vector<vector<int>>&vec,int i,int k){
        if(i<0) return node();
        if(k==0 || i>=vec.size()) return node();
        if(dp[i][k].sum != -1) return dp[i][k];
        node notake=solve(vec,i+1,k);
        int wt=vec[i][2];
        int ind=vec[i][3];
        int next=nextIndex[i];
        node temp=solve(vec,next,k-1);
        node take;
        take.sum=wt + temp.sum;
        take.inds=temp.inds;
        take.inds.push_back(ind);
        sort(take.inds.begin(),take.inds.end());
        node res;
        if(take.sum<notake.sum){
            res=notake;
        }else if(take.sum>notake.sum){
            res=take;
        }else{
            res=(notake.inds<take.inds)?notake:take;
        }
        return dp[i][k]=res;
    }
    vector<int> maximumWeight(vector<vector<int>>& inter) {
        int n=inter.size();
        vector<vector<int>>vec(n,vector<int>(4));
        for(int i=0;i<n;i++){
            vec[i][0]=inter[i][0];
            vec[i][1]=inter[i][1];
            vec[i][2]=inter[i][2];
            vec[i][3]=i;
        }
        sort(vec.begin(),vec.end(),[&](const auto & a,const auto & b){
            return a[0]<b[0];
        });
        nextIndex.resize(n+1);
        for(int i=0;i<n;i++){
            nextIndex[i]=search(vec,vec[i][1]);
        }
        dp.assign(n+1,vector<node>(5));
        node x=solve(vec,0,4);
        return x.inds;
    }
};