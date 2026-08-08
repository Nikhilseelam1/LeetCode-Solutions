class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int i=n-1;
        int j=m-1;
        int match=0;
        vector<int>right(n,0);
        while(i>=0){
            if(j>=0 && word1[i]==word2[j]){
                match++;
                j--;
            }
            right[i]=match;
            i--;
        }
        i=0;
        j=0;
        bool f=true;
        vector<int>ans;
        while(i<n && j<m)
        {
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }else if(i+1<n && f==true && right[i+1]>=m-j-1){
                ans.push_back(i);
                j++;
                f=false;
            }
            i++;
        }
        if(ans.size()==m) return ans;
        return {};
    }
};