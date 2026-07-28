class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        string s1(n,'#');
        vector<int>freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        int j=n-1;
        int c=0;
        char ans;
        for(int i=0;i<26;i++){
            int x=freq[i];
            if(x%2==0)
            {
                for(int k=0;k<x/2;k++){
                    s1[c]=i+'a';
                    s1[j]=i+'a';
                    c++;
                    j--;
                }
            }else{
                for(int k=0;k<x/2;k++){
                    s1[c]=i+'a';
                    s1[j]=i+'a';
                    c++;
                    j--;
                }
                ans=i+'a';
            }
        }
        if(n%2==0){
            return s1;
        }
        s1[n/2]=ans;
        return s1;
    }
};