class Solution {
public:
    int minDays(int n) {
        int m = sqrt(2LL * n) + 1;

        vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));

        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        int days = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [curr, streak] = q.front();
                q.pop();

                if (curr == n)
                    return days;

                // Increase streak
                int nxt = curr + streak + 1;

                if (nxt <= n && !visited[nxt][streak + 1]) {
                    visited[nxt][streak + 1] = true;
                    q.push({nxt, streak + 1});
                }

                // Reset streak
                if (streak > 0 && !visited[curr][0]) {
                    visited[curr][0] = true;
                    q.push({curr, 0});
                }
            }

            days++;
        }

        return -1;
    }
};