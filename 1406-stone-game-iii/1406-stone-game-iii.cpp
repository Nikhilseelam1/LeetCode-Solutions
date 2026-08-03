class Solution {
public:
    int dp[50001][2];

    int rec(int i, vector<int>& p, bool f) {
        int n = p.size();
        if (i >= n) return 0;

        if (dp[i][f] != -1) return dp[i][f];

        if (f) {
            int maxi = INT_MIN;

            maxi = max(maxi, p[i] + rec(i + 1, p, false));

            if (i + 1 < n)
                maxi = max(maxi, p[i] + p[i + 1] + rec(i + 2, p, false));

            if (i + 2 < n)
                maxi = max(maxi, p[i] + p[i + 1] + p[i + 2] + rec(i + 3, p, false));

            return dp[i][f] = maxi;
        } else {
            int maxi = INT_MAX;

            maxi = min(maxi, rec(i + 1, p, true));

            if (i + 1 <= n)
                maxi = min(maxi, rec(i + 2, p, true));

            if (i + 2 <= n)
                maxi = min(maxi, rec(i + 3, p, true));

            return dp[i][f] = maxi;
        }
    }

    string stoneGameIII(vector<int>& p) {
        memset(dp, -1, sizeof(dp));

        int alice = rec(0, p, true);

        int sum = 0;
        for (int x : p) sum += x;

        if (alice > sum - alice) return "Alice";
        if (alice == sum - alice) return "Tie";
        return "Bob";
    }
};