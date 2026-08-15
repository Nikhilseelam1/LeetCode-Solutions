class Solution {
public:
    int minAbsDifference(vector<int>& nums, int t) {
        int n=nums.size();
        int n1=n/2;
        int n2=n-(n1);
        vector<int>sum_a(1<<n1),sum_b(1<<n2);
        for(int mask=0;mask<(1<<n1);mask++){
            int sum=0;
            for(int i=0;i<n1;i++){
                if((mask & (1<<i))){
                    sum+=nums[i];
                }
            }
            sum_a[mask]=sum;
        }
        for(int mask=0;mask<(1<<n2);mask++){
            int sum=0;
            for(int i=0;i<n2;i++){
                if((mask & (1<<i))){
                    sum+=nums[n1+i];
                }
            }
            sum_b[mask]=sum;
        }
        int ans=INT_MAX;
        sort(sum_b.begin(),sum_b.end());
        for(int i=0;i<sum_a.size();i++){
            int x=t-sum_a[i];
            int it=lower_bound(sum_b.begin(),sum_b.end(),x)-sum_b.begin();
            if(it<sum_b.size()){
                int s_1=sum_b[it];
                int total=s_1+sum_a[i];
                ans=min(abs(total-t),ans);
            }
            if(it>0){
                int s_1=sum_b[it-1];
                int total=s_1+sum_a[i];
                ans=min(abs(total-t),ans);
            }

        }
        return ans;
    }
};