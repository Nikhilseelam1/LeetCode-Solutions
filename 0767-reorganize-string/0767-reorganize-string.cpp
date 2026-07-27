class Solution {
public:
    string reorganizeString(string s) {
       unordered_map<char,int>mp;
       priority_queue<pair<int,char>>pq;
       for(char ch:s){
            mp[ch]++;
       }
       for(auto it:mp){
        pq.push({it.second,it.first});
       }
       string ans="";
       while(pq.size()>1){
            auto it=pq.top();
            int x=it.first;
            char ch=it.second;
            pq.pop();
            auto it1=pq.top();
            int x1=it1.first;
            char ch1=it1.second;
            ans+=ch;
            ans+=ch1;
            pq.pop();
            if(x>1) pq.push({x-1,ch});
            if(x1>1) pq.push({x1-1,ch1});
       }
       while(!pq.empty()){
        auto it=pq.top();
        int x=it.first;
        ans+=it.second;
        pq.pop();
        if(x>1) pq.push({x-1,it.second});
       }
       cout<<ans;
       for(int i=0;i<ans.size()-1;i++){
            if(ans[i] == ans[i+1]) return "";
       }
       return ans;
    }
};