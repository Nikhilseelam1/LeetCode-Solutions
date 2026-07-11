class Solution {
    String s;
    String s1;
    int n;
    int m;
    int [][]dp;
    public int findRotateSteps(String ring, String key) {
        s=ring;
        s1=key;
        n=s.length();
        m=s1.length();
        dp=new int[m+1][n];
        for(int i=0;i<n;i++){
            dp[m][i]=0;
        }
        for(int k=m-1;k>=0;k--){
            for(int i=0;i<n;i++){
                dp[k][i]=Integer.MAX_VALUE;
                for(int j=0;j<n;j++){
                    if (ring.charAt(j) == key.charAt(k)) {

                        int diff = Math.abs(j - i);
                        int rotation = Math.min(diff, n - diff);

                        dp[k][i] = Math.min(
                                dp[k][i],
                                rotation + 1 + dp[k + 1][j]
                        );
                    }
                }
            }
        }
        return dp[0][0];
    }
}