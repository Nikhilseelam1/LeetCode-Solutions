
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& q)
    {
        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int m = q.size();
        vector<pair<int,int>> queries;

        for (int i = 0; i < m; i++) {
            queries.push_back({q[i], i});
        }
        sort(queries.begin(), queries.end());
        vector<int> ans(m);
        unordered_map<int, int> mp;
        int j = 0, i = 0;
        for (int v = 0; v < m; v++)
        {
            int it = queries[v].first;
            int idx = queries[v].second;
            int x1 = it - x;
            while (j < logs.size() && logs[j][1] <= it)
            {
                mp[logs[j][0]]++;
                j++;
            }
            while (i < logs.size() && logs[i][1] < x1)
            {
                int server = logs[i][0];
                mp[server]--;
                if (mp[server] == 0)
                    mp.erase(server);

                i++;
            }
            ans[idx] = n - mp.size();
        }

        return ans;
    }
};
