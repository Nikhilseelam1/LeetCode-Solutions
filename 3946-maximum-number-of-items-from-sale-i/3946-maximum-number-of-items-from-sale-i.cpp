class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    int dp[1001][1501][2];
    int rec(int i, int b,int f ,vector<vector<int>>& items) {
        if (i == n) return 0;
        if(dp[i][b][f]!=-1) return dp[i][b][f];
        int skip = rec(i + 1, b,0, items);
        int take = 0;
        if (items[i][1] <= b) {
            if(f==0){
                take = 1+mp[i] + rec(i, b - items[i][1],1, items);
            }
            else {
                take = 1+rec(i, b - items[i][1],1, items);
            }
        }
        return dp[i][b][f]=max(take, skip);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n = items.size();
        mp.clear();
        memset(dp,-1,sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[i][0] != 0 &&
                    items[j][0] % items[i][0] == 0) {
                    mp[i]++;
                }
            }
        }
        return rec(0, budget,0, items);
    }
};