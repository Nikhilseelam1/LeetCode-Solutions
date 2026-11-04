class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
       vector<vector<pair<int,int>>>adj(n+1);
       for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
       }
       priority_queue<pair<int,pair<int,int>>,
       vector<pair<int,pair<int,int>>>,
       greater<pair<int,pair<int,int>>>>pq;
       pq.push({0,{0,1}});
       vector<vector<int>>dist(n+1,vector<int>(k+1,1e9));
       dist[0][1]=0;
       while(!pq.empty())
       {
            auto it=pq.top();
            pq.pop();
            int node=it.second.first;
            int k1=it.second.second;
            int w=it.first;
            if(node==n-1) return w;
            for(auto edge:adj[node])
            {
                int node1=edge.first;
                int w1=edge.second;
                int newcount;
                if(labels[node]==labels[node1]) newcount=k1+1;
                else newcount=1;
                if(newcount<=k && w1+w<dist[node1][newcount]){
                    dist[node1][newcount]=w1+w;
                    pq.push({w+w1,{node1,newcount}});
                }
            }
       }
       return -1;
    }
};