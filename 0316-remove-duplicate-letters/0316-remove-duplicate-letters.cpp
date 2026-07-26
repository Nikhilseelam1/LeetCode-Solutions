class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans="";
        int n=s.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']=i;
        }
        vector<bool>used(26,false);
        for(int i=0;i<n;i++){
            if(used[s[i]-'a']) continue;
            while(!ans.empty() && ans.back()>s[i] && freq[ans.back()-'a']>i){
                used[ans.back()-'a']=false;
                ans.pop_back();
            }
            used[s[i]-'a']=true;
            ans+=s[i];
        }
        return ans;
    }
};