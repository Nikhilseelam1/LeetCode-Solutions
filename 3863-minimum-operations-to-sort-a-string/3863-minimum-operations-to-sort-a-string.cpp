class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        char mn='z';
        char mx='a';
        for(int i=0;i<n;i++){
            if(mn>s[i]){
                mn=min(mn,s[i]);
            }
            if(mx<s[i]){
                mx=max(mx,s[i]);
            }
        }
        string x=s;
        sort(x.begin(),x.end());
        if(x==s) return 0;
        if(mn==s[0]) return 1;
        if(mx==s[n-1]) return 1;
        if(mx==s[0] && mn==s[n-1]){
            if(n==2) return -1;
            for(int i=1;i<n-1;i++){
                if(s[i]==mn || s[i]==mx) return 2;
            }
            return 3;
        }
        return 2;
    }
};