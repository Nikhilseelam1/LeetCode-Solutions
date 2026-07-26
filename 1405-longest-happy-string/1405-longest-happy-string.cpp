class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a!=0) pq.push({a,'a'});
        if(b!=0) pq.push({b,'b'});
        if(c!=0) pq.push({c,'c'});
        string ans="";
        while(!pq.empty()){
            auto it=pq.top();
            int x=it.first;
            char ch=it.second;
            pq.pop();
            if(x<=0) continue;
            if(ans.size()>=2)
            {
                int n=ans.size();
                if(ans[n-1]==ans[n-2] && ch==ans[n-1]){
                    if(!pq.empty()){
                        auto it1=pq.top();
                        char ch1=it1.second;
                        int x1=it1.first;
                        pq.pop();
                        if(x1<=0) continue;
                        ans+=ch1;
                        pq.push({x1-1,ch1});
                        pq.push({x,ch});
                    }else{
                        break;
                    }
                }else{
                    ans+=ch;
                    pq.push({x-1,ch});
                }
            }else{
                ans+=ch;
                pq.push({x-1,ch});
            }
        }
        return ans;
    }
};