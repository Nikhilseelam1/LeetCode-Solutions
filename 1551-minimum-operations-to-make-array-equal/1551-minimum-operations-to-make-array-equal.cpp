class Solution {
public:
    int minOperations(int n) {
        vector<int>vec(n);
        for(int i=0;i<n;i++){
            vec[i]=2*i + 1;
        }
        int mid=(vec[n-1] + vec[0])/2;
        int ans=0;
        for(int i=0;i<n/2;i++){
            ans+=abs(mid-vec[i]);
        }
        return ans;
    }
};