class Solution {
public:
    int longestDecomposition(string text) {
        int n=text.size();
        int l=0;
        int r=n-1;
        int cnt=0;
        
        while(l<r){
            if(text[l]==text[r]){
                cnt+=2;
                l++;
                r--;
            }
            else{
                string f="";
                string b="";
                 while (l< r) {
                  b+=text[r];
                  f=text[l]+f;

                if (f == b)
                    break;

                l++;
                r--;
            }

            if (f == b) {
                cnt += 2;
                l++;
                r--;
            } else {
                cnt++;
                return cnt;
            }
        }
        }
        if(l==r){
            cnt++;
        }
        return cnt;
        
    }
};