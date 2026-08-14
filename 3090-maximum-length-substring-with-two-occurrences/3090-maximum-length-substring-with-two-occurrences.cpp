class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int,int>mp;
        int n=s.size();
        int j=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp[s[i]]>2){
                mp[s[j]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                j++;
            }
            maxi=max(maxi,i-j+1);
        } 
        return maxi;
    }
};