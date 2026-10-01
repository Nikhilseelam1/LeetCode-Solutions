class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        int c=0;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            if(seq[i]=='('){
                if(i>0 && seq[i-1]=='(') c=!c;
                ans[i]=c;
            }else{
                if(i>0 && seq[i-1]==')') c=!c;
                ans[i]=c;
            }
        }
        return ans;
    }
};