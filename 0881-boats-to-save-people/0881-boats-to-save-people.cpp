class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(),p.end());
        int n=p.size();
        int ans=0;
        int i=0;
        int j=n-1;
        while(i<=j){
            int sum=p[i]+p[j];
            if(sum<=limit){
                i++;
                j--;
            }else{
                j--;
            }
            ans++;
        }
        return ans;
    }
};