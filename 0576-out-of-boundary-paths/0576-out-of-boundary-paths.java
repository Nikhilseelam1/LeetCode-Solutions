class Solution {

    int mod = (int)1e9 + 7;

    public int findPaths(int m, int n, int maxMove, int sr, int sc) {

        int[][][] dp = new int[m][n][maxMove + 1];

        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        // Base:
        // rec(i,j,0) = 0
        // Java arrays are already initialized with 0.

        for (int move = 1; move <= maxMove; move++) {

            for (int i = 0; i < m; i++) {

                for (int j = 0; j < n; j++) {

                    long ans = 0;

                    for (int d = 0; d < 4; d++) {

                        int ni = i + dx[d];
                        int nj = j + dy[d];

                        if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                            ans++;
                        else
                            ans += dp[ni][nj][move - 1];
                    }

                    dp[i][j][move] = (int)(ans % mod);
                }
            }
        }

        return dp[sr][sc][maxMove];
    }
}