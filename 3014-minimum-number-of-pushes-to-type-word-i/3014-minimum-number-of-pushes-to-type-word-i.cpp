class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int m=n/8;
        if(8>n) return n;
        int rem=n%8;
        int ans=0;
        int c=1;
        for(int i=1;i<=m;i++){
            ans+=8*i;
            c++;
        }
        ans+=c*rem;
        return ans;
    }
};