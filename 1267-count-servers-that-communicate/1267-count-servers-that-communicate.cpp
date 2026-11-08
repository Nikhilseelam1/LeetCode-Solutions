class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            bool f=false;
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                bool c=false;
                if(f)
                {
                    ans++;
                    continue;
                }
                f=true;
                for(int x=j+1;x<m;x++){
                    if(grid[i][x])
                    {
                        ans++;
                        f=true;
                        c=true;
                        break;
                    }
                }
                if(c){
                    continue;
                }
                for(int x=i-1;x>=0;x--){
                    if(grid[x][j]){
                        ans++;
                        c=true;
                        break;
                    }
                }
                if(c) continue;
                for(int x=i+1;x<n;x++){
                    if(grid[x][j])
                    {
                        ans++;
                        break;
                    }
                }
            }
            cout<<ans<<" ";
        }
        return ans;
    }
};