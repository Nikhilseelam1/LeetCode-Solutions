class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(s1[i]==s2[j]){
                i++;
                j++;
                continue;
            }
            int x=((s1[i]-'a') +1)%26;
            int x1=s2[j]-'a';
            if(x==x1){
                i++;
                j++;
                continue;
            }else{
                i++;
            }
        }
        if(j==m) return true;
        return false;
    }
};