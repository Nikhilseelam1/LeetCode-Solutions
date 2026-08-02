class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char ch:word){
            freq[ch-'a']++;
        }
        vector<int>vec;
        for(int it:freq){
            if(it>0) vec.push_back(it);
        }
        sort(vec.rbegin(),vec.rend());
        int c=1;
        int ans=0;
        int x=vec.size();
        int j=0;
        for(int it:vec){
            ans+=c*it;
            j++;
            if((j) % 8 == 0){
                c++;
            }
            // cout<<ans<<" ";
        }
        return ans;
    }
};