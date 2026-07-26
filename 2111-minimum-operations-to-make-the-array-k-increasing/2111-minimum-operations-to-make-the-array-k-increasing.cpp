class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int ans=0;
        int n=arr.size();
        for(int s=0;s<k;s++){
            vector<int>seq;
            for(int i=s;i<n;i+=k){
                seq.push_back(arr[i]);
            }
            vector<int>lis;
            for(int it:seq){
                if(lis.empty() || lis.back()<=it){
                    lis.push_back(it);
                }else{
                    int ind=upper_bound(lis.begin(),lis.end(),it)-lis.begin();
                    lis[ind]=it;
                }
            }
            ans+=seq.size() -  lis.size();
        }
        return ans;
    }
};