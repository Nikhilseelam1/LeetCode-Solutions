class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int c=0;
        int odd_sum=0;
        int even_sum=1;
        int sum=0;
        int mod=1e9+7;
        for(int it:arr){
            sum+=it;
            if(sum%2==0){
                c+=odd_sum;
                even_sum++;
            }else{
                c+=even_sum;
                odd_sum++;
            }
            c=c%mod;
        }
        return c;
    }
};