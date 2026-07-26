class Solution {
public:
    string breakPalindrome(string s) {
        int n=s.size();
        if(n==1) return "";
        int i=0;
        int j=n-1;
        while(i<j){
            if(s[i]!='a'){
                s[i]='a';
                break;
            }
            i++;
            j--;
        }
        if(i<j) return s;
        s[n-1]='b';
        return s;
    }
};