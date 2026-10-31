class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int,vector<pair<int,int>>> m;

        for(auto x:edges){
            m[x[0]].push_back({x[1],x[2]});
        }

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > q;

        vector<vector<int>> dp(n,vector<int>(k+1,INT_MAX));

        dp[0][1]=0;
        q.push({0,0,1});

        while(!q.empty()){
            auto [cost,node,c]=q.top();
            q.pop();

            if(cost!=dp[node][c]) continue;

            if(node==n-1) return cost;

            for(auto x:m[node]){
                int v=x.first;
                int wt=x.second;
                int cnt=1;

                if(labels[v]==labels[node]){
                    cnt=c+1;
                }

                if(cnt>k) continue;

                if(cost+wt<dp[v][cnt]){
                    dp[v][cnt]=cost+wt;
                    q.push({cost+wt,v,cnt});
                }
            }
        }

        return -1;
    }
};