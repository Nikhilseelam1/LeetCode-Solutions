class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int x=0;
        for(int i=1;i<=n;i++){
             x+=i*(26-(s[i-1]-'a'));
        }
        return x;
    }
};