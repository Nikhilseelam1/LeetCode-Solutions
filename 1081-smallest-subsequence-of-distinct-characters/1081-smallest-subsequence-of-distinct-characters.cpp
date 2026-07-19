class Solution {
public:
    string smallestSubsequence(string s) {
         int n=s.size();
        vector<int>freq(26,0);
        vector<bool>used(26,false);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']=i;
        }
        string res="";
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(used[ch-'a']) continue;
            while(!res.empty() && res.back()>ch && freq[res.back() - 'a']>i){
                used[res.back() -'a']=false;
                res.pop_back();
            }
            used[ch-'a']=true;
            res.push_back(ch);
        }
        return  res;
    }
};