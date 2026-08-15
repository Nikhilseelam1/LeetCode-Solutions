class Solution {
public:
    int minimumDifference(vector<int>& arr) {
        int n=arr.size();
        int n1=n/2;
        int n2=n-(n1);
        unordered_map<int,vector<int>>mp1;
        unordered_map<int,vector<int>>mp2;
        for(int mask=0;mask<(1<<n1);mask++){
            int c=0;
            int sum=0;
            for(int i=0;i<n1;i++){
                if((mask & (1<<i))){
                    sum+=arr[i];
                    c++;
                }
            }
            mp1[c].push_back(sum);
        }
        for(int mask=0;mask<(1<<n2);mask++){
            int c=0;
            int sum=0;
            for(int i=0;i<n2;i++){
                if((mask & (1<<i))){
                    sum+=arr[n1+i];
                    c++;
                }
            }
            mp2[c].push_back(sum);
        }
        
        int t=accumulate(arr.begin(),arr.end(),0);
        for(int i=0;i<=n2;i++){
            sort(mp2[i].begin(),mp2[i].end());
        }
        int ans=INT_MAX;
        for(int i=0;i<=n1;i++){
            int x=n1-i;
            vector<int>v=mp1[i];
            for(int it:v)
            {
                int need=(t-2*it)/2;
                int ind=lower_bound(mp2[x].begin(),mp2[x].end(),need)-mp2[x].begin();
                if(ind<mp2[x].size()){
                    int r_s=mp2[x][ind];
                    int l_s=it;
                    ans=min(ans,abs(2*(r_s+l_s)-t));
                }
                if(ind-1>=0){
                    int r_s=mp2[x][ind-1];
                    int l_s=it;
                    ans=min(ans,abs(2*(r_s+l_s)-t));
                }
            }
        }
        return ans;
    }

};