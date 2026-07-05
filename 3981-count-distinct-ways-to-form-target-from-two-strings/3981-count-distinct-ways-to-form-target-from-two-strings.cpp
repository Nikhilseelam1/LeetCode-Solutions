class Solution {
public:
    int mod = 1e9 + 7;
    int n, m, o;
    int dp[101][101][101][2][2];
    int solve(int i, int j, int k, string& word1, string& word2, string& target,
              bool flag1, bool flag2) {
        if (k == o) {
            if (flag1 && flag2)
                return 1;
            return 0;
        }
        if(dp[i][j][k][flag1][flag2]!=-1) return dp[i][j][k][flag1][flag2];
        int take1 = 0;
        for (int ii = i; ii < n; ii++) {
            if (target[k] == word1[ii]) {
                take1 =
                    (take1 + solve(ii + 1, j, k + 1, word1, word2, target, true, flag2)) %
                    mod;
            }
        }
        int take2 = 0;
        for (int jj = j; jj < m; jj++) {
            if (target[k] == word2[jj]) {
                take2 =
                    (take2 + solve(i, jj + 1, k + 1, word1, word2, target, flag1, true)) %
                    mod;
            }
        }
        return dp[i][j][k][flag1][flag2]=(take1 + take2) % mod;
    }
    int interleaveCharacters(string word1, string word2, string target) {
        n = word1.size(), m = word2.size(), o = target.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, 0, 0, word1, word2, target, false, false);
    }
};