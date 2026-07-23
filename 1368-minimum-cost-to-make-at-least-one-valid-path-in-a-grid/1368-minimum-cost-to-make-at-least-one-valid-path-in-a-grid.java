class Solution {
   
    public int minCost(int[][] grid) {

    PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[2], b[2]));
    pq.offer(new int[]{0, 0, 0});

    int n = grid.length;
    int m = grid[0].length;

    int[] dx = {-1, 1, 0, 0}; // Up, Down, Right, Left
    int[] dy = {0, 0, 1, -1};

    boolean[][] vis = new boolean[n][m];

    while (!pq.isEmpty()) {

        int[] curr = pq.poll();

        int r = curr[0];
        int c = curr[1];
        int cost = curr[2];

        if (r == n - 1 && c == m - 1)
            return cost;

        if (vis[r][c])
            continue;

        vis[r][c] = true;

        int[] changeCost;

        if (grid[r][c] == 1)
            changeCost = new int[]{1, 1, 0, 1};   // Right
        else if (grid[r][c] == 2)
            changeCost = new int[]{1, 1, 1, 0};   // Left
        else if (grid[r][c] == 3)
            changeCost = new int[]{1, 0, 1, 1};   // Down
        else
            changeCost = new int[]{0, 1, 1, 1};   // Up

        for (int k = 0; k < 4; k++) {

            int nr = r + dx[k];
            int nc = c + dy[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                pq.offer(new int[]{nr, nc, cost + changeCost[k]});
            }
        }
    }

    return 0;
}
}