class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int rec(int i, vector<int>& nums, int k) {

        if (k == 0 && i == n)
            return 0;

        if (k == 0 || i == n)
            return INT_MAX;

        if (dp[i][k] != -1)
            return dp[i][k];

        int ans = INT_MAX;
        int sum = 0;

        for (int j = i; j < n; j++) {

            sum += nums[j];

            int ft = rec(j + 1, nums, k - 1);

            if (ft != INT_MAX)
                ans = min(ans, max(sum, ft));
        }

        return dp[i][k] = ans;
    }

    int splitArray(vector<int>& nums, int k) {

        n = nums.size();

        dp.assign(n + 1, vector<int>(k + 1, -1));

        return rec(0, nums, k);
    }
};