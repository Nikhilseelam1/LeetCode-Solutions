class Solution {
public:

    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={-1,1,0,0};
        int dy[]={0,0,1,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        int c1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]>0)
                {
                    queue<pair<long long,pair<int,int>>>pq;
                    vis[i][j]=1;
                    pq.push({grid[i][j],{i,j}});
                    long long ans=0;
                    while(!pq.empty())
                    {
                        auto f1=pq.front();
                        long long f=f1.first;
                        int rr=f1.second.first;
                        int cc=f1.second.second;
                        pq.pop();
                        ans+=f;
                        for(int x=0;x<4;x++)
                        {
                            int r=dx[x]+rr;
                            int c=dy[x]+cc;
                            if(r>=0 && c>=0 && r<n && c<m && !vis[r][c] && grid[r][c]>0)
                            {
                                pq.push({grid[r][c],{r,c}});
                                vis[r][c]=1;
                            }
                        }
                    }
                    // cout<<ans<<" ";
                    if(ans%k==0) c1++;
                }
            }
        }
        return c1;
    }
};