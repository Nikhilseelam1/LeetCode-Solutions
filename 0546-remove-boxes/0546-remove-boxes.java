class Solution {
    int rec(int i,int j,int k,int [] b,int [][][]dp){
        if(i>=j) return 0;
        int i0=i;
        int k0=k;
        if(dp[i][j][k]!=0) return dp[i][j][k];
        while(i+1<j && b[i]==b[i+1]){
            i++;
            k++;
        }
        int ans=0;
        ans=(k+1)*(k+1) + rec(i+1,j,0,b,dp);
        for(int m=i+1;m<j;m++){
            if(b[i]==b[m]){
                ans=Math.max(ans,rec(i+1,m,0,b,dp)+rec(m,j,k+1,b,dp));
            }
        }
        dp[i0][j][k0]=ans;
        return ans;
    }
    public int removeBoxes(int[] boxes) {
        int [][][]dp=new int[101][101][101];
        int n=boxes.length;
        return rec(0,n,0,boxes,dp);
    }
}