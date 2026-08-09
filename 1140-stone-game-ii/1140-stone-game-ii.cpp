class Solution {
public:
    int n;
    int dp[101][2][202];
    int rec(int i,bool f,int m,vector<int>&p){
        if(i>=n) return 0;
        long long maxi=f?0:1e9;
        if(dp[i][f][m]!=-1) return dp[i][f][m];
        if(f){
            long long sum=0;
            for(int j=1;j<=2*m && i+j<=n;j++){
                sum+=p[i+j-1];
                maxi=max(maxi,sum+rec(j+i,false,max(m,j),p));
            }
        }else{
            for(int j=1;j<=2*m && i+j<=n;j++){
                maxi=min(maxi,(long long)rec(j+i,true,max(m,j),p));
            }
        }
        return dp[i][f][m]=maxi;
    }
    int stoneGameII(vector<int>& p) {
        n=p.size();
        memset(dp,-1,sizeof(dp));
       return rec(0,true,1,p);
    }
};