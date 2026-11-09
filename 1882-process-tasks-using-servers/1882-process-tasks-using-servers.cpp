class Solution {
public:
    struct server{
        long long t;
        int ser,ind;
        bool operator>(const server& other) const{
            return t>other.t;
        }
    };
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();
        priority_queue<server,vector<server>,greater<server>>pq1;
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>>pq2;
        vector<int>ans(m,0);
        for(int i=0;i<n;i++) pq2.push({servers[i],i});
        long long curr=0;
        for(int i=0;i<m;i++)
        {
            curr=max(curr,(long long)i);
            while(!pq1.empty() && pq1.top().t<=curr)
            {
                pq2.push({pq1.top().ser,pq1.top().ind});
                pq1.pop();
            }
            if(pq2.empty()) {
                curr = pq1.top().t;

                while(!pq1.empty() && pq1.top().t == curr) {
                    pq2.push({pq1.top().ser, pq1.top().ind});
                    pq1.pop();
                }
            }
            auto x=pq2.top();
            int x1=x.first;
            int x2=x.second;
            pq2.pop();
            pq1.push({tasks[i]+curr,x1,x2});
            ans[i]=x2;
        }
        return ans;
    }
};