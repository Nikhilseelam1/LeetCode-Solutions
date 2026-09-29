class Solution {
public:
    int n;
    int m;
    int dp[101][101][101];
    bool rec(int i,int j,int sum,vector<vector<char>>&grid)
    {
        if(i>=n || j>=m) return false;
        if (sum < 0) {return false;}
        int remaining = (n - 1 - i) + (m - 1 - j);

        if (sum > remaining + 1)
            return false;
        if(i==n-1 && j==m-1){
            if(grid[i][j]=='(') return (sum+1)==0;
            return (sum-1)==0;
        }
        if(dp[i][j][sum]!=-1) return dp[i][j][sum];
        bool right=false;
        bool down=false;
        if(grid[i][j]=='('){
            right=rec(i,j+1,sum+1,grid);
            down=rec(i+1,j,sum+1,grid);
        }else{
            right=rec(i,j+1,sum-1,grid);
            down=rec(i+1,j,sum-1,grid);
        }
        return dp[i][j][sum]=right || down;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,0,grid);
    }
};