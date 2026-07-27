class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        vector<pair<int,int>>vec;
        int n=p.size();
        for(int i=0;i<n;i++){
            vec.push_back({c[i],p[i]});
        }
        sort(vec.begin(),vec.end());
        int j=0;
        priority_queue<int>pq;
        for(int i=0;i<k;i++){
            while(j<n && vec[j].first<=w){
                pq.push(vec[j].second);
                j++;
            }
            if (pq.empty()) {
                break;
            }
                 w+=pq.top();
                 pq.pop();
        }
        return w;
    }
};