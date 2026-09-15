class Solution {
public:
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) {
            this->n = n;
            bit.assign(n + 1, 0);
        }

        void add(int idx, int val) {
            idx++;

            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int sum(int idx) {
            idx++;

            int res = 0;

            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }

            return res;
        }

        int rangeSum(int l, int r) {
            if (l > r)
                return 0;

            return sum(r) - (l > 0 ? sum(l - 1) : 0);
        }
    };

    long long shadowPairs(vector<int>& nums) {

        int n = nums.size();

        // -----------------------------
        // Find next smaller element
        // -----------------------------
        vector<int> nextS(n, n);

        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() &&
                   nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (!st.empty())
                nextS[i] = st.top();

            st.push(i);
        }

        // -----------------------------
        // Sort indices by value
        // -----------------------------
        vector<int> order(n);

        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(),
             [&](int a, int b) {
                 return nums[a] > nums[b];
             });

        Fenwick fw(n);

        long long ans = 0;

        int p = 0;

        while (p < n) {

            int q = p;

            // Same value must be processed together
            while (q < n &&
                   nums[order[q]] == nums[order[p]]) {
                q++;
            }

            // -----------------------------
            // Query first
            // -----------------------------
            for (int k = p; k < q; k++) {

                int i = order[k];

                int l = i + 1;
                int r = nextS[i] - 1;

                if (l <= r) {
                    int x = fw.rangeSum(l, r);

                    ans += x;
                }
            }

            // -----------------------------
            // Add current value
            // -----------------------------
            for (int k = p; k < q; k++) {

                int i = order[k];

                fw.add(i, 1);
            }

            p = q;
        }

        return ans;
    }
};