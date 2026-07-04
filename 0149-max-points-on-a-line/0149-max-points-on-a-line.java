class Solution {

    public int gcd(int a, int b) {
        if (b == 0)
            return Math.abs(a);
        return gcd(b, a % b);
    }

    public int maxPoints(int[][] p) {

        int n = p.length;
        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {

            int x1 = p[i][0];
            int y1 = p[i][1];

            HashMap<String, Integer> mp = new HashMap<>();
            int maxi = 0;

            for (int j = i + 1; j < n; j++) {

                int x2 = p[j][0];
                int y2 = p[j][1];

                int dx = x2 - x1;
                int dy = y2 - y1;

                // Vertical line
                if (dx == 0) {
                    dy = 1;
                }
                // Horizontal line
                else if (dy == 0) {
                    dx = 1;
                }
                else {
                    int g = gcd(dx, dy);
                    dx /= g;
                    dy /= g;

                    // Normalize sign
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                }

                String key = dy + "/" + dx;

                mp.put(key, mp.getOrDefault(key, 0) + 1);

                maxi = Math.max(maxi, mp.get(key));
            }

            ans = Math.max(ans, maxi + 1);
        }

        return ans;
    }
}