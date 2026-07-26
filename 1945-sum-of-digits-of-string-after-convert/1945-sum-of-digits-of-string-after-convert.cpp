class Solution {
public:
    int getLucky(string s, int k) {
        string s1="";
        int n=s.size();
        for(int i=0;i<n;i++){
            string x=to_string((s[i]-'a')+1);
            s1+=x;
        }
        int res=0;
        for(int i=0;i<k;i++){
            int j=0;
            string s2="";
            int ans=0;
            while(j<s1.size()){
                ans+=(s1[j]-'0');
                j++;
            }
            res=ans;
            s1=to_string(ans);
        }
        return res;
    }
};