class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        int n=s.size();
        int m=k.size();
        unordered_map<string,string>mp;
        for(int i=0;i<m;i++){
            string key=k[i][0];
            string value=k[i][1];
            mp[key]=value;
        }
        string ans;
        ans.reserve(n);
        int i=0;
        while(i<n)
        {
            if(s[i]=='('){
                int j=i+1;
                while(s[j]!=')'){
                    j++;
                }
                string x = s.substr(i + 1, j - i - 1);
                if(mp.find(x)!=mp.end()){
                    ans+=mp[x];
                }else{
                    ans+="?";
                }
                i=j+1;
                continue;
            }else if(s[i]==')'){
                continue;
            }else{
                ans+=s[i];
            }
            i++;
        }
        return ans;
    }
};