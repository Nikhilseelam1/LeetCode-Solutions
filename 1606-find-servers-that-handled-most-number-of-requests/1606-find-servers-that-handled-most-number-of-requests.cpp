class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n=arrival.size();
        set<long long>st;
        priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>>pq;
        vector<int>cnt(n,0);
        for(int i=0;i<k;i++) st.insert(i); 
        for(int i=0;i<n;i++) 
        {
            while(!pq.empty() && pq.top().first <= arrival[i])
            {
                st.insert(pq.top().second);
                pq.pop();
            }
            int x=i%k;
            if(st.empty()) continue;
            auto ind=st.lower_bound(x);
            if(ind==st.end())
            {
                ind=st.begin();
            }
            int ele=*ind;
            st.erase(ele);
            cnt[ele]++;
            pq.push({arrival[i]+load[i],ele});
        }
        int maxi=*max_element(cnt.begin(),cnt.end());
        vector<int>ans;

        for(int i=0;i<n;i++) {
            // cout<<it<<" ";
            if(cnt[i]==maxi) ans.push_back(i);
        }
        return ans;
    }
};