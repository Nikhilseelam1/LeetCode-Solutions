class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int n=arr1.size();
        int ans=0;
        for(int i=0;i<n;i++){
            auto it=lower_bound(arr2.begin(),arr2.end(),arr1[i]);
            if(it!=arr2.end()){
                int x=*it;
                int ind=distance(arr2.begin(),it);
                int t=x-arr1[i];
                if(ind-1>=0){
                    t=min(t,abs(arr1[i]-arr2[ind-1]));
                }
                if(t>d) ans++;
            }else{
                if(abs(arr1[i]-arr2[arr2.size()-1])>d) ans++;
            }
        }
        return ans;
    }
};