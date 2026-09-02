class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }

        int maxi = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                int prev = arr[i];
                int prev2 = arr[j];

                int c = 2;
                int pos = j;

                while (true) {

                    int sum = prev + prev2;

                    if (!mp.count(sum))
                        break;

                    int nextPos = mp[sum];

                    if (nextPos <= pos)
                        break;

                    c++;

                    prev = prev2;
                    prev2 = sum;

                    pos = nextPos;
                }

                maxi = max(maxi, c);
            }
        }

        return maxi >= 3 ? maxi : 0;
    }
};